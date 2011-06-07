#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>

#include "databasemanager.h"
#include "clientmodel.h"

DataBaseManager::DataBaseManager(QObject *parent)
    :QObject(parent)
{
    dbOpen();
}

bool DataBaseManager::dbOpen()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mang_prot.db");
    if (!db.open())
        return false;

    QSqlQuery query;
    query.exec("create table client (id int primary key, "
            "lastname varchar(20), firstname varchar(20), "
            "middlename varchar(20), year int, address varchar(150), "
            "disability int, group int)");

    query.exec("insert into client values(101, 'Сазонов', 'Геннадий', "
            "'Валерьевич', 1985, 'бла бла бла бла 12 бла 43, бла', 2, 3");


    return true;
}

bool DataBaseManager::findClient( QString lastName, QString firstName,
        QString middleName, QList<Client*> *clients)
{
    QSqlQuery query;
    query.exec("SELECT * FROM client WHERE (lastname, firstname, middlename) "
            "VALUES (?,?,?)");
    query.bindValue(0, lastName);
    query.bindValue(1, firstName);
    query.bindValue(2, middleName);
    query.exec();

    Client *client = new Client;
    if (query.next()) {
        client->setID(query.value(0).toInt());
        client->setSurname(query.value(1).toString());
        client->setName(query.value(2).toString());
        client->setPatronymic(query.value(3).toString());
        client->setYear(query.value(4).toInt());
        client->setAddr(query.value(5).toString());
        clients->append(client);
    }


    return true;
}
