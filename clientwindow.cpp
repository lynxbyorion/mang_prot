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

    QString disabilyty = "Инвалид " + client->getDisabilityToString() + " " +
        client->getGroupToString() + " группы.";
    QLabel *lbDis = new QLabel(disabilyty);

    QLabel *lbAdr = new QLabel("Адресс:");
    QLabel *lbAddress = new QLabel(client->getAddr());

    pbClose = new QPushButton(tr("Закрыть"));
    connect(pbClose, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *nameLayout = new QVBoxLayout;
    nameLayout->addWidget(lbName);
    nameLayout->addWidget(lbDis);

    QHBoxLayout *addrLayout = new QHBoxLayout;
    addrLayout->addWidget(lbAdr);
    addrLayout->addWidget(lbAddress);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(pbClose);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(addrLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    //setFixedSize(600, 300);
    setWindowTitle(tr("Окно клиента"));
}
