/*
 * \file batabasemanager.h
 * \brif in this file is implemented interaction with data base
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-06-07
 *
 */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>

class Client;
class Order;

class DataBaseManager: public QObject
{
  public:
    static DataBaseManager* getInstance();

    ~DataBaseManager();

  public:
    int getMaxID();
    int getMaxOrderID();
    bool insertClientInDB(Client);
    bool insertOrderInDB(Order);

    bool getClients( QString lastName, QString firstName,
            QString middleName, QList<Client*> &clients);
    bool getClient( int, Client *);
    bool getClientOrders( int idClient, QList<Order*> &ordersList);

  private:
    DataBaseManager(QObject *prarent = 0);
    bool dbOpen();

  private:
    static DataBaseManager *single;
    static bool instanceFlag;

    QSqlDatabase db;

};

#endif // DATABASEMANAGER_H

