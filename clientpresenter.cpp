#include <QStringList>
#include "clientpresenter.h"

#include "iviewclientform.h"
#include "databasemanager.h"
#include "clientmodel.h"
#include "clientorder.h"

#include <QDebug>

ClientPresenter::ClientPresenter(const int id_)
{
    model = new ClientModel();
    client = new Client(model->getClient(id_));
}

/*
 *ClientPresenter::ClientPresenter(int id,IViewClientForm *view,
 *                QObject *parent)
 *    :QObject(parent), clientForm(view)
 *{
 *    dbManager = DataBaseManager::getInstance();
 *    QObject* view_obj = dynamic_cast<QObject*>(view);
 *
 *    QObject::connect(view_obj, SIGNAL(viewCurrentOrder(const int)),
 *            this, SLOT(activeCurrentOrder(const int)));
 *    QObject::connect(view_obj, SIGNAL(pushAddOrder(Order &)),
 *            this, SLOT(addOrder(Order &)));
 *
 *    initialize(id);
 *
 *}
 */

void ClientPresenter::setView(IViewClientForm *win_)
{
    clientForm = win_;
    initialize();
}

void ClientPresenter::initialize()
{

    clientForm->setFullName(createFullNameString());
    clientForm->setDisability(createDisabilityString());
    clientForm->setAddress(client->getAddr());

    clientForm->setOrdersList(createOrdersStringList());

    if (clientOrders.size() != 0) {
        clientForm->setOrderData(orderToStringList(0));
    }
}

QString ClientPresenter::createFullNameString()
{
    QString name =  client->getSurname() + " " + client->getName() +
        " " + client->getPatronymic() + ", " + QString::number(client->getYear()) +
        " года рождения.";

    return name;
}

QString ClientPresenter::createDisabilityString()
{
    QString disabilyty = "Инвалид " + client->getDisabilityToString() + " " +
        client->getGroupToString() + " группы.";

    return disabilyty;
}

QStringList ClientPresenter::createOrdersStringList()
{
    QStringList list;

    for (int i = 0; i < clientOrders.size(); i++)
    {
        list << (QString::number(clientOrders.at(i)->getID()) + ".  "
            + clientOrders.at(i)->getArticleToString() + ",  "
            + (clientOrders.at(i)->getDeliveryDate()).toString("dd MMMM yyyy"));
    }

    return list;
}

QStringList ClientPresenter::orderToStringList(int indexList)
{
     QStringList list;

     list << QString::number(clientOrders.at(indexList)->getID());
     list << QString::number(clientOrders.at(indexList)->getPayment());
     list << clientOrders.at(indexList)->getReceptionDate().toString();
     list << clientOrders.at(indexList)->getDeliveryDate().toString();
     list << clientOrders.at(indexList)->getDiagnosis();
     list << QString::number(clientOrders.at(indexList)->getArticle());

     return list;
}

void ClientPresenter::refresh()
{
    clientOrders.clear();
    model->getClientOrders(client->getID(), clientOrders);

    clientForm->setOrdersList(createOrdersStringList());
    clientForm->setOrderData(orderToStringList(0));
}

// slots
void ClientPresenter::activeCurrentOrder(const int index)
{
    clientForm->setOrderData(orderToStringList(index));
}

void ClientPresenter::addOrder(Order &order)
{
    order.setIDClient(client->getID());
    //dbManager->insertOrderInDB(order);
    refresh();
}
