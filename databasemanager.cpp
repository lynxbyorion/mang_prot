#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>

#include <QDebug>
#include <QSqlError>

#include "databasemanager.h"
#include "clientmodel.h"

DataBaseManager::DataBaseManager(QObject *parent)
    :QObject(parent)
{
}

DataBaseManager::~DataBaseManager()
{
    db.close();
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
    query.prepare("CREATE TABLE IF NOT EXISTS client "
            "(id INTEGER UNIQUE PRIMARY KEY, lastname VARCHAR(20), "
            "firstname VARCHAR(20), middlename VARCHAR(20), "
            "year INTEGER, address VARCHAR(150), disability INTEGER, "
            "groupdis INTEGER)" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "table created!";

    /*query.prepare("INSERT INTO client (id, lastname, firstname, middlename,"*/
            /*"year) VALUES (1, 'Sazonov', 'Gennady', 'Валерьевич', 1985)");*/
    /*if(!query.exec())*/
        /*qDebug() << query.lastError();*/
    /*else*/
        /*qDebug() << "Insert!";*/

    query.prepare("INSERT INTO client (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) VALUES (1, 'Sazowov', "
            "'Gennady', 'Валерьевич', 1985, 'бла бла бла бла 12 бла 43 бла', "
            "2, 3)");
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("INSERT INTO client (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) VALUES (2, 'Петров', "
            "'Петька', 'Петрович', 1985, 'бла бла2323452 бла 43 бла', "
            "2, 3)");
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";
    query.prepare("INSERT INTO client (id, lastname, firstname, middlename, "
            "year, address, disability, groupdis) VALUES (3, 'Ивановw', "
            "'Иван', 'Иваныч', 1965, 'блаыфвпжфывпыпжыводл ывалп о бла 12 ', "
            "2, 3)");
    if(!query.exec())
        qDebug() << query.lastError();
    else
        qDebug() << "Insert!";

    query.prepare("SELECT * FROM client WHERE lastname LIKE ?");
    query.bindValue(0, "%w%");
    if(!query.exec())
        qDebug() << query.lastError();
    else
    {
        while (query.next())
            qDebug() << query.value(1);
        qDebug() << "end!";
    }



    return true;
}

bool DataBaseManager::getClients( QString lastName, QString firstName,
        QString middleName, QList<Client*> &clientsList)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE lastname LIKE ? "
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
        client->setYear(query.value(4).toInt());
        client->setAddr(query.value(5).toString());
        clientsList.append(client);
    }

    return true;
}

