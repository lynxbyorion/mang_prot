#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

#include "iviewclientform.h"

class Client;
class DataBaseManager;

class QLabel;
class QListView;
class QDateEdit;
class QComboBox;
class QTextEdit;


class ClientWindow: public QDialog, public IViewClientForm
{
    Q_OBJECT

  public:
    explicit ClientWindow(QWidget *parent = 0);

    void setFullName(QString);
    void setDisability(QString);
    void setAddress(QString);

  private:
    QPushButton *pbClose;
    QListView *listOrders;

    QLabel *lbName;
    QLabel *lbDis;
    QLabel *lbAddress;

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
