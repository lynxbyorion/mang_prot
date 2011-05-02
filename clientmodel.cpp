#include "clientmodel.h"
#include "defandpar.h"

Client::Client()
    :name("noname"), surname("noname"), patronymic("noname"),
    yearOfBirth(MIN_YEAR), address(""), disability(War), group(GroupIII)
{
}
