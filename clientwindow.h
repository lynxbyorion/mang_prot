#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

#include "iviewclientform.h"

class QLabel;
class QLineEdit;
class QListView;
class QDateEdit;
class QComboBox;
class QTextEdit;
class QModelIndex;
class QGroupBox;

class Order;
class ClientPresenter;


class ClientWindow: public QDialog, public IViewClientForm
{
    Q_OBJECT

  public:
    explicit ClientWindow(QWidget *parent = 0);

    void choosePresenter(ClientPresenter *);

    void setFullName(QString);
    void setDisability(QString);
    void setAddress(QString);
    void setOrdersList(QStringList);
    void currentOrder(Order &);

  signals:
    void viewCurrentOrder(const int);
    void pushAddOrder(Order &);
    void activeRemoveOrder(const int);

  private slots:
    void activeCurrentOrder(const QModelIndex &);
    void activePbAddOrder();
    void pushPbDelOrder();
    void checkFss(int index);

  private:
    ClientPresenter *presenter;

    QPushButton *pbClose;
    QPushButton *pbAddOrder;
    QPushButton *pbDelOrder;
    QListView *listOrders;
    QGroupBox *orderGroupBox;

    QLabel *lbName;
    QLabel *lbDis;
    QLabel *lbAddress;

    QGroupBox *groupFss;

    QLineEdit *leNumberOrder;
    QDateEdit *deReceptionDate;
    QComboBox *cbPayment;

    QLineEdit *leFssNumber;
    QDateEdit *deFssDate;
    QLineEdit *leFssNumberOfList;


    QDateEdit *deDeliveryDate;
    QComboBox *cbArticle;
    QTextEdit *teDiagnosis;
};

#endif // CLIENTWINDOW_H
