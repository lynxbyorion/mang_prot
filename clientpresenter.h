/**
 * \file clientpresenter.h
 * \brif In this file implements presenter of MVP
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-05-05
 *
 */
#ifndef CLIENTPRESENTER_H
#define CLIENTPRESENTER_H

#include <QObject>
#include "clientmodel.h"
#include "databasemanager.h"

class QSqlDatabase;

class IViewForm;

class ClientPreseter: public QObject
{
    Q_OBJECT

public:
    explicit ClientPreseter(IViewForm *view, QObject *perent = 0);

private:
    void refreshView();
    bool createConnection();

private slots:
    /*! This slot identified client (find or create)
     *
     * TODO здесь мы должны будем обратиться к базе для поиска слиента
     *
     */
    void identificationClient();

private:
    Client *m_client;
    IViewForm *m_view;

    DataBaseManager *dbManager;



};

#endif //CLIENTPRESENTER_H
