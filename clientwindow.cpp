#include <QtGui>

#include <QDebug>

#include "clientwindow.h"

#include "databasemanager.h"
#include "clientmodel.h"

ClientWindow::ClientWindow(QWidget *parent)
    :QDialog(parent)
{
    lbName = new QLabel();
    lbName->setWordWrap(true);

    lbDis = new QLabel();

    QLabel *lbAdr = new QLabel("Адрес:");
    lbAddress = new QLabel();
    lbAddress->setWordWrap(true);

    listOrders = new QListView;
    listOrders->setFixedSize(200, 250);

    pbClose = new QPushButton(tr("Закрыть"));
    connect(pbClose, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *addrLayout = new QHBoxLayout;
    addrLayout->addWidget(lbAdr, 0, Qt::AlignTop);
    addrLayout->addSpacing(20);
    addrLayout->addWidget(lbAddress, 1, Qt::AlignTop);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(lbName);
    leftLayout->addWidget(lbDis);
    leftLayout->addLayout(addrLayout);
    leftLayout->addStretch();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(listOrders);

    QHBoxLayout *infoLayout = new QHBoxLayout;
    infoLayout->addLayout(leftLayout, 1);
    infoLayout->addWidget(listOrders);

    // ordering information
    lbNumberOrder = new QLabel("0");
    QLabel *lbReceptionDate = new QLabel("Дата обращения: ");
    deReceptionDate = new QDateEdit;

    QLabel *lbPayment = new QLabel("Вид оплаты: ");
    cbPayment = new QComboBox;

    QLabel *lbType = new QLabel("Вид изделия: ");
    cbArticle = new QComboBox;
    QLabel *lbDelivery = new QLabel("дата выдачи изделия ");
    deDeliveryDate = new QDateEdit;

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(pbClose);

    QHBoxLayout *numOrderLayout = new QHBoxLayout;
    numOrderLayout->addWidget(lbNumberOrder);
    numOrderLayout->addWidget(lbReceptionDate);
    numOrderLayout->addWidget(deReceptionDate);

    QHBoxLayout *payOrderLayout = new QHBoxLayout;
    payOrderLayout->addWidget(lbPayment);
    payOrderLayout->addWidget(cbPayment);

    QHBoxLayout *articleOrderLayout = new QHBoxLayout;
    articleOrderLayout->addWidget(lbType);
    articleOrderLayout->addWidget(cbArticle);
    articleOrderLayout->addWidget(lbDelivery);
    articleOrderLayout->addWidget(deDeliveryDate);

    QVBoxLayout *orderLayout = new  QVBoxLayout;
    orderLayout->addLayout(numOrderLayout);
    orderLayout->addLayout(payOrderLayout);
    orderLayout->addLayout(articleOrderLayout);

    QGroupBox *orderGroupBox = new QGroupBox(tr("Заказ"));
    orderGroupBox->setFlat(true);
    orderGroupBox->setLayout(orderLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(infoLayout);
    mainLayout->addWidget(orderGroupBox);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    //setFixedSize(600, 300);
    setWindowTitle(tr("Окно клиента"));
}

void ClientWindow::setFullName(QString name)
{
    lbName->setText(name);
}

void ClientWindow::setDisability(QString disability)
{
    lbDis->setText(disability);
}

void ClientWindow::setAddress(QString address)
{
    lbAddress->setText(address);
}
