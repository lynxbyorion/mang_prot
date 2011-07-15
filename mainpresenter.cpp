#include <QMessageBox>

#include "mainpresenter.h"
#include "iviewform.h"
#include "clientpresenter.h"
#include "clientwindow.h"

#include <QDebug>

MainPresenter::MainPresenter(IViewForm *view, QObject *perent)
    :QObject(perent), m_view(view)
{
    QObject* view_obj = dynamic_cast<QObject*>(m_view);
    QObject::connect(view_obj, SIGNAL(actionFindClient()),
            this, SLOT(findClients()));
    QObject::connect(view_obj, SIGNAL(actionAddClient()),
            this, SLOT(addClient()));
    QObject::connect(view_obj, SIGNAL(actionReturnIndex(const int)),
            this, SLOT(createClientWindow(const int)));
    QObject::connect(view_obj, SIGNAL(actionRemoveClient(const int)),
            this, SLOT(removeClient(const int)));

    dbManager = DataBaseManager::getInstance();

    findClients();

}

void MainPresenter::refreshView()
{
    m_view->refresh();
}

//! slots
void MainPresenter::findClients()
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

void MainPresenter::addClient()
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
    refreshView();
}

void MainPresenter::createClientWindow(const int index)
{
    const int id = (clients.at(index))->getID();

    ClientWindow *window = new ClientWindow();
    ClientPresenter *presenter = new ClientPresenter(id);
    presenter->setView(window);
    window->choosePresenter(presenter);

    window->exec();
}

void MainPresenter::removeClient(const int index)
{
    dbManager->removeClient(clients.at(index)->getID());
    findClients();
}
