#include <QtGui>

#include <QDebug>

#include "clientwindow.h"

#include "databasemanager.h"
#include "clientmodel.h"

ClientWindow::ClientWindow(const int clientID, DataBaseManager *db, QWidget *parent)
    :QDialog(parent)
{
    client = new Client();
    db->getClient(clientID, client);

    QString name =  client->getSurname() + " " + client->getName() +
        " " + client->getPatronymic() + ", " + QString::number(client->getYear()) +
        " года рождения.";
    QLabel *lbName = new QLabel(name);
    lbName->setWordWrap(true);

    QString disabilyty = "Инвалид " + client->getDisabilityToString() + " " +
        client->getGroupToString() + " группы.";
    QLabel *lbDis = new QLabel(disabilyty);

    QLabel *lbAdr = new QLabel("Адрес:");
    QLabel *lbAddress = new QLabel(client->getAddr());
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


    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(pbClose);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(infoLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    setFixedSize(600, 300);
    setWindowTitle(tr("Окно клиента"));
}
