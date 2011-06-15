#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

class Client;
class DataBaseManager;

class QLabel;
class QListView;
class QDateEdit;
class QComboBox;
class QTextEdit;


class ClientWindow: public QDialog
{
    Q_OBJECT

  public:
    ClientWindow(const int, DataBaseManager *, QWidget *parent = 0);

  private:
    QPushButton *pbClose;
    QListView *listOrders;

    QLabel *lbNumberOrder;
    QDateEdit *deReceptionDate;
    QComboBox *cbPayment;
    QDateEdit *deDeliveryDate;
    QComboBox *cbArticle;
    QTextEdit *teDiagnosis;

    Client *client;
    DataBaseManager* dbmanager;
};

#endif // CLIENTWINDOW_H
