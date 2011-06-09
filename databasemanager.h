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

class DataBaseManager: public QObject
{
  public:
    DataBaseManager(QObject *prarent = 0);
    ~DataBaseManager();

  public:
    bool dbOpen();
    //bool dbClose();

    bool getClients( QString lastName, QString firstName,
            QString middleName, QList<Client*> &clients);

  private:
    QSqlDatabase db;

};

#endif // DATABASEMANAGER_H

