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

class DataBaseManager: public QObject
{
  public:
    DataBaseManager(QObject *prarent = 0);

  public:
    bool dbOpen();
    //bool dbClose();

  private:
    QSqlDatabase db;

};

#endif // DATABASEMANAGER_H

