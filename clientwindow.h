#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

class Client;
class DataBaseManager;
class QListView;

class ClientWindow: public QDialog
{
    Q_OBJECT

  public:
    ClientWindow(const int, DataBaseManager *, QWidget *parent = 0);

  private:
    QPushButton *pbClose;
    QListView *listOrders;

    Client *client;
    DataBaseManager* dbmanager;
};

#endif // CLIENTWINDOW_H