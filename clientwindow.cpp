#include <QtGui>

#include <QDebug>

#include "clientwindow.h"
#include "clientpresenter.h"

#include "databasemanager.h"
#include "clientmodel.h"
#include "clientorder.h"

ClientWindow::ClientWindow(QWidget *parent /* =0 */)
    :QDialog(parent)
{
    lbName = new QLabel();
    lbName->setWordWrap(true);

    lbDis = new QLabel();

    QLabel *lbAdr = new QLabel("Адрес:");
    lbAdr->setAlignment(Qt::AlignTop);
    lbAddress = new QLabel();
    lbAddress->setWordWrap(true);

    listOrders = new QListView;
    connect(listOrders, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(activeCurrentOrder(const QModelIndex &)));
    listOrders->setSelectionMode(QAbstractItemView::NoSelection);
    listOrders->setFixedSize(230, 250);

    pbAddOrder = new QPushButton("+");
    connect(pbAddOrder, SIGNAL(clicked()), this, SLOT(activePbAddOrder()));

    pbDelOrder = new QPushButton("-");
    connect(pbDelOrder, SIGNAL(clicked()), this, SLOT(pushPbDelOrder()));

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

    QHBoxLayout *rightButtonLayout = new QHBoxLayout;
    rightButtonLayout->addWidget(pbAddOrder);
    rightButtonLayout->addWidget(pbDelOrder);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(listOrders);
    rightLayout->addLayout(rightButtonLayout);

    QHBoxLayout *infoLayout = new QHBoxLayout;
    infoLayout->addLayout(leftLayout, 1);
    infoLayout->addLayout(rightLayout);

    // ordering information
    QLabel *lbNumberText = new QLabel("№ ");
    lbNumberOrder = new QLabel("0");
    QLabel *lbReceptionDate = new QLabel("Дата обращения: ");
    deReceptionDate = new QDateEdit;
    deReceptionDate->setDisplayFormat("dd.MM.yyyy");

    QLabel *lbPayment = new QLabel("Вид оплаты: ");
    cbPayment = new QComboBox;
    QStringList listPayment(QStringList() << "фсс" << "наличный расчёт"
            << "компенсация");
    cbPayment->addItems(listPayment);
    connect(cbPayment, SIGNAL(currentIndexChanged(int)),
                this, SLOT(checkFss(int)));

    QLabel *lbFssNumber = new QLabel(tr("Номер:"));
    leFssNumber = new QLineEdit();
    lbFssNumber->setBuddy(leFssNumber);
    QLabel *lbFssDate = new QLabel(tr("Дата направления:"));
    deFssDate = new QDateEdit();
    deFssDate->setDisplayFormat("dd.MM.yyyy");
    lbFssDate->setBuddy(deFssDate);
    QLabel *lbFssNumberOfList = new QLabel(tr("Номер по журналу:"));
    leFssNumberOfList = new QLineEdit();

    groupFss = new QGroupBox(tr("ФСС"));

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

    QLabel *lbDelivery = new QLabel("Дата выдачи изделия ");
    deDeliveryDate = new QDateEdit;
    deDeliveryDate->setDisplayFormat("dd.MM.yyyy");

    QLabel *lbDiagnosis = new QLabel(tr("Диагноз: "));
    lbDiagnosis->setAlignment(Qt::AlignTop);
    teDiagnosis = new QTextEdit;

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(pbClose);

    QHBoxLayout *numOrderLayout = new QHBoxLayout;
    numOrderLayout->addWidget(lbNumberText);
    numOrderLayout->addWidget(lbNumberOrder);
    numOrderLayout->addStretch();
    numOrderLayout->addWidget(lbReceptionDate);
    numOrderLayout->addWidget(deReceptionDate);


    QGridLayout *fssLayout = new QGridLayout;
    fssLayout->addWidget(lbFssNumber, 0, 0);
    fssLayout->addWidget(leFssNumber, 0, 1);
    fssLayout->addWidget(lbFssDate, 1, 0);
    fssLayout->addWidget(deFssDate, 1, 1);
    fssLayout->addWidget(lbFssNumberOfList, 2, 0);
    fssLayout->addWidget(leFssNumberOfList, 2, 1);

    groupFss->setLayout(fssLayout);

    QHBoxLayout *payOrderLayout = new QHBoxLayout;
    payOrderLayout->addWidget(lbPayment);
    payOrderLayout->addWidget(cbPayment);
    payOrderLayout->addWidget(groupFss);

    QHBoxLayout *articleOrderLayout = new QHBoxLayout;
    articleOrderLayout->addWidget(lbType);
    articleOrderLayout->addWidget(cbArticle);

    QHBoxLayout *deliveryLayout = new QHBoxLayout;
    deliveryLayout->addWidget(lbDelivery);
    deliveryLayout->addStretch();
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


    orderGroupBox = new QGroupBox(tr("Заказ"));
    orderGroupBox->setFlat(true);
    orderGroupBox->setLayout(orderLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(infoLayout);
    mainLayout->addWidget(orderGroupBox);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    //setFixedSize(500, 700);
    setWindowTitle(tr("Окно клиента"));
}

void ClientWindow::choosePresenter(ClientPresenter *presenter_)
{
    presenter = presenter_;
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

void ClientWindow::activePbAddOrder()
{
    Order order;
    order.setReceptionDate(deReceptionDate->date());
    order.setPayment((Order::Payment)cbPayment->currentIndex());
    order.setDeliveryDate(deDeliveryDate->date());
    order.setArticle((Order::Article)cbArticle->currentIndex());
    order.setDiagnosis(teDiagnosis->toPlainText());

    emit pushAddOrder(order);
}

void ClientWindow::pushPbDelOrder()
{
    qDebug() << "current index = " << listOrders->currentIndex().row();
    if(listOrders->currentIndex().row() < 0)
    {
        QMessageBox::warning(this, tr("Будьте внимательны!"),
                tr("Вы не выбрали заказ для удаления"), QMessageBox::Ok);
    }
    else
        emit activeRemoveOrder(listOrders->currentIndex().row());
}

void ClientWindow::checkFss(int index)
{
    index == 0 ? groupFss->setDisabled(false) : groupFss->setDisabled(true);
}
