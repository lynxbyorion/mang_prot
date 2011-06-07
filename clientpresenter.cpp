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
}

void ClientPreseter::refreshView()
{
}

//! slots
void ClientPreseter::identificationClient()
{
    QString lastName;
    QString firstName;
    QString middleName;

    dbManager->findClient(lastName, firstName, middleName, &clients);
    qWarning() << "in identific 1: " + (clients.at(0))->getSurname();
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

