#include <QMessageBox>

#include "databasemanager.h"

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

    return true;
}

