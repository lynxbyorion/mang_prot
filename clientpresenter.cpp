#include <QMessageBox>

#include "clientpresenter.h"
#include "iviewform.h"

#include <QDebug>

ClientPreseter::ClientPreseter(IViewForm *view, QObject *perent)
    :QObject(perent), m_view(view)
{
    QObject* view_obj = dynamic_cast<QObject*>(m_view);
    QObject::connect(view_obj, SIGNAL(actionFindClient()),
            this, SLOT(identificationClient()));

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
    refreshListClients();
}

void ClientPreseter::refreshView()
{
}

//! slots
void ClientPreseter::identificationClient()
{
    QString lastName = m_view->getLastName();
    qWarning() << lastName;
    QString firstName = "Gena";// m_view->getName();
    qWarning() << firstName;
    QString middleName = m_view->getPatronymic();

    dbManager->findClient(lastName, firstName, middleName, &clients);
    //qWarning() << "in identific 1: " + (clients.at(0))->getSurname();
    /*
     * TODO закончил здесь. дольше тест
     *
     */
    QStringList list;
    for (int i = 0; i < clients.size(); i++) {
        list << (clients.at(i))->getSurname();
        qWarning() << "in identific 2: " + (clients.at(i))->getSurname();
    }

    m_view->setList(list);

    qWarning() << "in the slot identification";
}

void ClientPreseter::refreshListClients()
{
    qWarning() << "in refreshList: begin ";
    dbManager->fullListClients(clients);
    QStringList list;
    for (int i = 0; i < clients.size(); i++) {
        list << (clients.at(i))->getSurname() +  " "
            + (clients.at(i))->getName() + " "
            + (clients.at(i))->getPatronymic();
    }

    m_view->setList(list);
}

