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

/**
 *  @short Class open datebase connection.
 *
 *  This class is created uses pattern Singleton. His created
 *  only one instance using method getInstance() and provides an
 *  interface for SQL query.
 */
class DataBaseManager: public QObject
{
  public:
    /**
     *  Create an instance of class if don't exists.
     */
    static DataBaseManager* getInstance();

    /**
     *  Close database and destoys instance
     */
    ~DataBaseManager();

  public:
    int getMaxID();
    int getMaxOrderID();
    bool insertClientInDB(Client &);
    bool removeClient(const int);
    bool insertOrderInDB(Order &);
    bool removeOrderInDB(const int idx_);

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

