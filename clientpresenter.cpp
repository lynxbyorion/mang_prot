#include <QStringList>
#include "clientpresenter.h"

#include "iviewclientform.h"
#include "databasemanager.h"
#include "clientmodel.h"
#include "clientorder.h"

#include <QDebug>

ClientPresenter::ClientPresenter(DataBaseManager *db, int id,IViewClientForm *view,
                QObject *parent)
    :QObject(parent), clientForm(view)
{
    dbManager = db;
    QObject* view_obj = dynamic_cast<QObject*>(view);

    QObject::connect(view_obj, SIGNAL(viewCurrentOrder(const int)),
            this, SLOT(activeCurrentOrder(const int)));
    QObject::connect(view_obj, SIGNAL(pushAddOrder(Order &)),
            this, SLOT(addOrder(Order &)));

    initialize(id);

}

void ClientPresenter::initialize(int id)
{
    client = new Client();
    dbManager->getClient(id, client);
    dbManager->getClientOrders(id, clientOrders);

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
        list << (QString::number(clientOrders.at(i)->getID()) + " "
            + (clientOrders.at(i)->getDeliveryDate()).toString() + " "
            + clientOrders.at(i)->getArticleToString());
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

// slots
void ClientPresenter::activeCurrentOrder(const int index)
{
    clientForm->setOrderData(orderToStringList(index));
}

void ClientPresenter::addOrder(Order &order)
{
    order.setIDClient(client->getID());
    qDebug() << "id client: " << client->getID();
    qDebug() << "id order in addOrder: " << order.getIDClient();
    dbManager->insertOrderInDB(order);
}
