#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

#include "iviewclientform.h"

class QLabel;
class QListView;
class QDateEdit;
class QComboBox;
class QTextEdit;
class QModelIndex;
class QGroupBox;

class Order;


class ClientWindow: public QDialog, public IViewClientForm
{
    Q_OBJECT

  public:
    explicit ClientWindow(QWidget *parent = 0);

    void setFullName(QString);
    void setDisability(QString);
    void setAddress(QString);
    void setOrdersList(QStringList);
    void setOrderData(QStringList);

  signals:
    void viewCurrentOrder(const int);
    void pushAddOrder(Order &);

  private slots:
    void activeCurrentOrder(const QModelIndex &);
    void activePbAddOrder();

  private:
    QPushButton *pbClose;
    QPushButton *pbAddOrder;
    QListView *listOrders;
    QGroupBox *orderGroupBox;

    QLabel *lbName;
    QLabel *lbDis;
    QLabel *lbAddress;

    QLabel *lbNumberOrder;
    QDateEdit *deReceptionDate;
    QComboBox *cbPayment;
    QDateEdit *deDeliveryDate;
    QComboBox *cbArticle;
    QTextEdit *teDiagnosis;
};

#endif // CLIENTWINDOW_H
