/**
 * \file clientpresenter.h
 * \brif In this file, the implementation of the client presenter of pattern MVP
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-06-25
 */

#ifndef CLIENTPRESENTER_H
#define CLIENTPRESENTER_H

#include <QObject>

class IViewClientForm;
class DataBaseManager;
class Client;
class Order;

class ClientPresenter: public QObject
{
    Q_OBJECT

  public:
    explicit ClientPresenter(DataBaseManager *db, int id,IViewClientForm *view,
                    QObject *parent = 0);

  private:
    void initialize(int id);
    QString createFullNameString();
    QString createDisabilityString();
    QStringList createOrdersStringList();
    QStringList orderToStringList(int indexList);

  private slots:
    void activeCurrentOrder(const int);

  private:
    Client *client;
    QList<Order*> clientOrders;
    DataBaseManager *dbManager;

    IViewClientForm *clientForm;
};

#endif // CLIENTPRESENTER_H
