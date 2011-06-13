#include <QMessageBox>

#include "clientpresenter.h"
#include "iviewform.h"

#include <QDebug>

ClientPreseter::ClientPreseter(IViewForm *view, QObject *perent)
    :QObject(perent), m_view(view)
{
    QObject* view_obj = dynamic_cast<QObject*>(m_view);
    QObject::connect(view_obj, SIGNAL(actionFindClient()),
            this, SLOT(findClients()));
    QObject::connect(view_obj, SIGNAL(actionAddClient()),
            this, SLOT(addClient()));
    QObject::connect(view_obj, SIGNAL(actionReturnIndex(const int)),
            this, SLOT(createClientWindow(const int)));

    dbManager = new DataBaseManager();
    if (!dbManager->dbOpen())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Не могу подключиться к базе данных.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        exit(1);

    }

    findClients();

}

void ClientPreseter::refreshView()
{
}

//! slots
void ClientPreseter::findClients()
{
    QString lastName = m_view->getLastName();
    QString firstName = m_view->getName();
    QString middleName = m_view->getPatronymic();

    clients.clear();

    dbManager->getClients(lastName, firstName, middleName, clients);

    QStringList list;
    for (int i = 0; i < clients.size(); i++) {
        list << (clients.at(i))->getSurname() +  " "
            + (clients.at(i))->getName() + " "
            + (clients.at(i))->getPatronymic();
    }

    m_view->setList(list);

}

void ClientPreseter::addClient()
{
    Client client;
    client.setID(dbManager->getMaxID() + 1);
    client.setSurname(m_view->getLastName());
    client.setName(m_view->getName());
    client.setPatronymic(m_view->getPatronymic());
    client.setYear(m_view->getYear());
    client.setAddr(m_view->getAddress());
    client.setDisability(m_view->getDisability());
    client.setGroup(m_view->getGroup());

    if (!dbManager->insertClientInDB(client)) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Не могу добавить в базу клиента.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

void ClientPreseter::createClientWindow(const int index)
{
    qDebug() << "Index = " << index;
}
