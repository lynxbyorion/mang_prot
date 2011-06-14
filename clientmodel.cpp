#include <QDebug>

#include "clientmodel.h"
#include "defandpar.h"

Client::Client()
    :name("noname"), surname("noname"), patronymic("noname"),
    yearOfBirth(MIN_YEAR), address(""), disability(War), group(GroupIII)
{
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
