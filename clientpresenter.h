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
class ClientWindow;

class ClientPreseter: public QObject
{
    Q_OBJECT

  public:
    explicit ClientPreseter(IViewForm *view, QObject *perent = 0);

  private:
    void refreshView();

  private slots:
    /**
     * This slot search
     */
    void findClients();
    /**
     * create Client and add it to the database.
     */
    void addClient();
    /**
     * create client window
     */
    void createClientWindow(const int);

  private:
    QList<Client*> clients;
    IViewForm *m_view;
    ClientWindow *clientWindow;

    DataBaseManager *dbManager;

};

#endif //CLIENTPRESENTER_H
