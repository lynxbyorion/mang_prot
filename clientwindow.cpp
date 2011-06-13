#include <QtGui>

#include "clientwindow.h"

#include "databasemanager.h"
#include "clientmodel.h"

ClientWindow::ClientWindow(const int clientID, DataBaseManager *db, QWidget *parent)
    :QDialog(parent)
{
    client = new Client();
    db->getClient(clientID, client);

    QString name =  client->getSurname() + " " + client->getName() +
        " " + client->getPatronymic();
    QLabel *lbName = new QLabel(name);

    pbClose = new QPushButton(tr("Закрыть"));
    connect(pbClose, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(lbName);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(pbClose);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    setFixedSize(600, 300);
    setWindowTitle(tr("Окно Клиента"));
}
