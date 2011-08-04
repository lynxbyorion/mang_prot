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
class ClientModel;
class ClientWindow;

class ClientPresenter: public QObject
{
    Q_OBJECT

  public:
    explicit ClientPresenter(const int id_);
    explicit ClientPresenter(int id,IViewClientForm *view,
                    QObject *parent = 0);

    void setView(IViewClientForm *);

  private:
    void initialize();
    QString createFullNameString();
    QString createDisabilityString();
    QStringList createOrdersStringList();
    QStringList orderToStringList(int indexList);

    void refresh();

  private slots:
    void activeCurrentOrder(const int);
    void addOrder(Order &);
    void removeOrder(const int);

  private:
    ClientModel *model;

    Client *client;
    QList<Order*> clientOrders;

    IViewClientForm *clientForm;
};

#endif // CLIENTPRESENTER_H
