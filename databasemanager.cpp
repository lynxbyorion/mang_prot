#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>

#include <QDebug>
#include <QSqlError>

#include "databasemanager.h"
#include "clientmodel.h"
#include "clientorder.h"

DataBaseManager::DataBaseManager(QObject *parent)
    :QObject(parent)
{
    if (!dbOpen())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Не могу подключиться к базе данных.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        exit(1);

    }
}

DataBaseManager::~DataBaseManager()
{
    db.close();
    delete single;
    instanceFlag = false;
}

bool DataBaseManager::instanceFlag = false;

DataBaseManager* DataBaseManager::single = NULL;

DataBaseManager* DataBaseManager::getInstance()
{
    if (!instanceFlag) {
        single = new DataBaseManager();
        instanceFlag = true;
        return single;
    }
    else {
        return single;
    }
}

bool DataBaseManager::dbOpen()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mang_prot.db");
    if (!db.open())
    {
        qDebug() << "db open false";
        return false;
    } else
    {
        qDebug() << "db open true";
    }

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS clients "
            "(id INTEGER UNIQUE PRIMARY KEY, lastname VARCHAR(20), "
            "firstname VARCHAR(20), middlename VARCHAR(20), "
            "year INTEGER, address VARCHAR(150), disability INTEGER, "
            "groupdis INTEGER)" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "table created!";

    query.prepare("INSERT INTO clients (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) VALUES (1, 'Sazowov', "
            "'Gennady', 'Валерьевич', 1985, 'бла бла бла бла 12 бла 43 бла', "
            "2, 3)");
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("INSERT INTO clients (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) VALUES (2, 'Петров', "
            "'Петька', 'Петрович', 1985, 'бла бла2323452 бла 43 бла', "
            "2, 3)");
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("INSERT INTO clients (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) VALUES (3, 'Ивановw', "
            "'Иван', 'Иваныч', 1965, 'блаыфвпжфывпыпжыводл ывалп о бла 12 ', "
            "2, 3)");
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("CREATE TABLE IF NOT EXISTS clientorder "
            " (idorder INTEGER UNIQUE PRIMARY KEY, idclient INTEGER, "
            " payment NUM, receptiondate DATE, deliverydate DATE, diagnosis TEXT, "
            " article NUM)" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "table order created!";

    query.prepare("INSERT INTO clientorder (idorder, idclient, payment, receptiondate, "
            " deliverydate, diagnosis, article) "
            " VALUES (30, 1, 0, '1970-12-12', '1971-11-11', "
            " 'Диагноз у меня нипойми какой', 3)" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("INSERT INTO clientorder (idorder, idclient, payment, receptiondate, "
            " deliverydate, diagnosis, article) "
            " VALUES (31, 1, 1, '1999-11-11', '1999-11-12', "
            " 'И опять не знаю чё сказать', 5)" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("INSERT INTO clientorder (idorder, idclient, payment, receptiondate, "
            " deliverydate, diagnosis, article) "
            " VALUES (32, 2, 2, '1980-10-1', '1971-11-11', "
            " 'Диагноз у меня нипойми какой', 3)" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    return true;
}

int DataBaseManager::getMaxID()
{
    QSqlQuery query;

    query.prepare("SELECT MAX(id) FROM clients");
    if(!query.exec()) {
        qDebug() << query.lastError();
        return -1;
    } else
        if (!query.next())
            return -1;

    int id = query.value(0).toInt();

    return id;
}

int DataBaseManager::getMaxOrderID()
{
    QSqlQuery query;

    query.prepare("SELECT MAX(idorder) FROM clientorder");
    if(!query.exec()) {
        qDebug() << query.lastError();
        return -1;
    } else
        if (!query.next())
            return -1;

    int id = query.value(0).toInt();

    return id;
}

bool DataBaseManager::insertClientInDB(Client &client)
{
    QSqlQuery query;

    query.prepare("INSERT INTO clients (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, client.getID());
    query.bindValue(1, client.getSurname());
    query.bindValue(2, client.getName());
    query.bindValue(3, client.getPatronymic());
    query.bindValue(4, client.getYear());
    query.bindValue(5, client.getAddr());
    query.bindValue(6, client.getDisability());
    query.bindValue(7, client.getGroup());
    if(!query.exec())
        qDebug() << query.lastError();
    else
    {
        qDebug() << "Insert!";
        return true;
    }
    return false;

}

bool DataBaseManager::removeClient(const int clientid)
{
    QSqlQuery query;
    query.prepare("DELETE FROM clientorder WHERE idclient = ?");
    query.bindValue(0, clientid);
    if(!query.exec()) {
        qDebug() << "EE in del order: " << query.lastError();
        return false;
    }
    query.prepare("DELETE FROM clients WHERE id = ?");
    query.bindValue(0, clientid);
    if(!query.exec()) {
        qDebug() << "EE in del client: " << query.lastError();
        return false;
    }
    return true;
}

bool DataBaseManager::insertOrderInDB(Order &order)
{
    QSqlQuery query;

    query.prepare("INSERT INTO clientorder (idorder, idclient, payment, receptiondate, "
            " deliverydate, diagnosis, article) "
            " VALUES(?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, getMaxOrderID() + 1);
    query.bindValue(1, order.getIDClient());
    query.bindValue(2, order.getPayment());
    query.bindValue(3, order.getReceptionDate());
    query.bindValue(4, order.getDeliveryDate());
    query.bindValue(5, order.getDiagnosis());
    query.bindValue(6, order.getArticle());
    if (!query.exec())
        qDebug() << "EE in insert order: " << query.lastError();
    else
    {
        qDebug() << "Insert!";
        return true;
    }
    return false;
}

bool DataBaseManager::removeOrderInDB(const int idx_)
{
    QSqlQuery query;
    query.prepare("DELETE FROM clientorder WHERE idorder = ?");
    query.bindValue(0, idx_);
    if(!query.exec())
        qDebug() << query.lastError();
    else {
        qDebug() << "Delete order";
        return true;
    }
    return false;
}

bool DataBaseManager::getClients( QString lastName, QString firstName,
        QString middleName, int year, int disability, int group,
        QList<Client*> &clientsList)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE lastname LIKE ? "
            "AND firstname LIKE ? AND middlename LIKE ?");
    query.bindValue(0, "%" + lastName + "%");
    query.bindValue(1, "%" + firstName + "%");
    query.bindValue(2, "%" + middleName + "%");
    if(!query.exec())
        qDebug() << query.lastError();
    else
    {
        qDebug() << "end!";
    }

    while (query.next()) {
        qWarning() << "in cicle fullListClient";
        Client *client = new Client;
        client->setID(query.value(0).toInt());
        client->setSurname(query.value(1).toString());
        client->setName(query.value(2).toString());
        client->setPatronymic(query.value(3).toString());
        if(year == 0 || year == query.value(4).toInt())
            client->setYear(query.value(4).toInt());
        else
            continue;
        client->setAddr(query.value(5).toString());
        qDebug() << "value 6 = " << query.value(6).toInt();
        if(disability == 0 || disability == -1 || disability == query.value(6).toInt()) {
            client->setDisability((Client::Disability)query.value(6).toInt());
            qDebug() << "in if disability";
        } else
            continue;
        if(group == 0 || group == -1 || group == query.value(7).toInt())
            client->setGroup((Client::Group)query.value(7).toInt());
        else
            continue;
        clientsList.append(client);
    }

    return true;
}

bool DataBaseManager::getClient(int id, Client *client)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE id = ?");
    query.bindValue(0, id);
    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    while (query.next()) {
        client->setID(query.value(0).toInt());
        qDebug() << "id client in getClient: " << client->getID();
        client->setSurname(query.value(1).toString());
        client->setName(query.value(2).toString());
        client->setPatronymic(query.value(3).toString());
        client->setYear(query.value(4).toInt());
        client->setAddr(query.value(5).toString());
        client->setDisability((Client::Disability)query.value(6).toInt());
        client->setGroup((Client::Group)query.value(7).toInt());
    }
    return true;
}

bool DataBaseManager::getClientOrders(int idClient, QList<Order*> &ordersList)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clientorder WHERE idclient = ?");
    query.bindValue(0, idClient);
    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    while(query.next()) {
        Order* order = new Order;
        order->setID(query.value(0).toInt());
        order->setPayment((Order::Payment)query.value(2).toInt());
        order->setReceptionDate(query.value(3).toDate());
        order->setDeliveryDate(query.value(4).toDate());
        order->setDiagnosis(query.value(5).toString());
        order->setArticle((Order::Article)query.value(6).toInt());
        ordersList.append(order);
    }
    return true;
}

