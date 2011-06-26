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
    connect(listOrders, SIGNAL(doubleClicked(const QModelIndex &)),
            this, SLOT(activeCurrentOrder(const QModelIndex &)));
    listOrders->setSelectionMode(QAbstractItemView::NoSelection);
    listOrders->setFixedSize(230, 250);

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
    QStringList listPayment(QStringList() << "фсс" << "наличный расчёт"
            << "компенсация");
    cbPayment->addItems(listPayment);

    QLabel *lbType = new QLabel("Вид изделия: ");
    cbArticle = new QComboBox;
    QStringList listArticle(QStringList() << "Протез"
            << "Корсет грудопоясничный"
            << "Тутор"
            << "Бандаж"
            << "Наколенники"
            << "Грыжевой бандаж (антральная грыжа)"
            << "Грыжевой бандаж (паховая грыжа)"
            << "Ортопедическая обувь"
            << "Протез молочной железы"
            << "Головодержатель");
    cbArticle->addItems(listArticle);

    QLabel *lbDelivery = new QLabel("дата выдачи изделия ");
    deDeliveryDate = new QDateEdit;

    QLabel *lbDiagnosis = new QLabel(tr("Диагноз"));
    teDiagnosis = new QTextEdit;

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

    QHBoxLayout *deliveryLayout = new QHBoxLayout;
    deliveryLayout->addWidget(lbDelivery);
    deliveryLayout->addWidget(deDeliveryDate);

    QHBoxLayout *diagnosisLayout = new QHBoxLayout;
    diagnosisLayout->addWidget(lbDiagnosis);
    diagnosisLayout->addWidget(teDiagnosis);

    QVBoxLayout *orderLayout = new  QVBoxLayout;
    orderLayout->addLayout(numOrderLayout);
    orderLayout->addLayout(payOrderLayout);
    orderLayout->addLayout(articleOrderLayout);
    orderLayout->addLayout(deliveryLayout);
    orderLayout->addLayout(diagnosisLayout);


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

void ClientWindow::setOrdersList(QStringList list)
{
    listOrders->setModel( new QStringListModel(list));
}

void ClientWindow::setOrderData(QStringList list)
{
    lbNumberOrder->setText(list.takeFirst());
    cbPayment->setCurrentIndex(list.takeFirst().toInt());
    deReceptionDate->setDate(QDate::fromString(list.takeFirst()));
    deDeliveryDate->setDate(QDate::fromString(list.takeFirst()));
    teDiagnosis->setText(list.takeFirst());
    cbArticle->setCurrentIndex(list.takeFirst().toInt());
}

// slots
void ClientWindow::activeCurrentOrder(const QModelIndex &index)
{
    emit viewCurrentOrder(index.row());
}
