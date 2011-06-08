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
#include <QList>

#include "clientmodel.h"
#include "databasemanager.h"

class IViewForm;

class ClientPreseter: public QObject
{
    Q_OBJECT

  public:
    explicit ClientPreseter(IViewForm *view, QObject *perent = 0);

  private:
    void refreshView();

  private slots:
    /*! This slot identified client (find or create)
     *
     * TODO здесь мы должны будем обратиться к базе для поиска слиента
     *
     */
    void identificationClient();
    /*
     * refresh the list clients on form
     */
    void refreshListClients();

  private:
    QList<Client*> clients;
    IViewForm *m_view;

    DataBaseManager *dbManager;



};

#endif //CLIENTPRESENTER_H
