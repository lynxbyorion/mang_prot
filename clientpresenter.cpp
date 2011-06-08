#include <QMessageBox>

#include "clientpresenter.h"
#include "iviewform.h"

#include <QDebug>

ClientPreseter::ClientPreseter(IViewForm *view, QObject *perent)
    :QObject(perent), m_view(view)
{
    QObject* view_obj = dynamic_cast<QObject*>(m_view);
    QObject::connect(view_obj, SIGNAL(actionFindClient()),
            this, SLOT(identificationClients()));

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

    identificationClients();

}

void ClientPreseter::refreshView()
{
}

//! slots
void ClientPreseter::identificationClients()
{
    QString lastName = m_view->getLastName();
    QString firstName = m_view->getName();
    QString middleName = m_view->getPatronymic();

    clients.clear();

    dbManager->findClients(lastName, firstName, middleName, clients);

    QStringList list;
    for (int i = 0; i < clients.size(); i++) {
        list << (clients.at(i))->getSurname() +  " "
            + (clients.at(i))->getName() + " "
            + (clients.at(i))->getPatronymic();
    }

    qDebug() << "identification client" << list;

    m_view->setList(list);

}

