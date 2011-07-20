#include <QDebug>

#include "clientmodel.h"

#include "databasemanager.h"
#include "defandpar.h"

Client::Client()
    :name("noname"), surname("noname"), patronymic("noname"),
    yearOfBirth(MIN_YEAR), address(""), disability(War), group(GroupIII)
{
}

void Client::setName(QString name_)
{
    name = name_.toLower();
    name[0] = name[0].toUpper();
}

void Client::setSurname(QString surname_)
{
    surname = surname_.toLower();
    surname[0] = surname[0].toUpper();
}

void Client::setPatronymic(QString patronymic_)
{
    patronymic = patronymic_.toLower();
    patronymic[0] = patronymic[0].toUpper();
}

QString Client::getDisabilityToString()
{
    switch(disability)
    {
      case War:
          return "войны";
      case Infancy:
          return "детства";
      case Work:
          return "труда";
      case General:
          return "общего заболевания";
      default:
          qDebug() << "Error: client->getDisabilityToString";
          return "";
    }
}

QString Client::getGroupToString()
{
    switch(group)
    {
      case GroupI:
          return "первой";
      case GroupII:
          return "второй";
      case GroupIII:
          return "третей";
      default:
          qDebug() << "Error: client->getGroupToString()";
          return "";
    }
}

///////////////////////////////////////////////////////////////////////////////

ClientModel::ClientModel()
    :db(DataBaseManager::getInstance())
{

}

Client& ClientModel::getClient(int id)
{
    Client *client = new Client();
    db->getClient(id, client);

    return *client;
}

void ClientModel::getClientOrders(int id, QList<Order*> &ordersList)
{
    db->getClientOrders(id, ordersList);
}

void ClientModel::insertOrder(Order &order)
{
    db->insertOrderInDB(order);
}

void ClientModel::removeOrder(const int idx_)
{
    db->removeOrderInDB(idx_);
}
