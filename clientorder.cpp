#include <QDebug>

#include "clientorder.h"

Order::Order()
{
}

QString Order::getPaymentToString()
{
    switch(payment)
    {
        case Fss:
            return "ФСС";
        case Cash:
            return "Наличный расчёт";
        case Compensation:
            return "Компенсация";
        default:
            qDebug() << "Warning:  empty payment!";
            return "";
    }
}

QString Order::getArticleToString()
{
    switch(article)
    {
        case Prosthesis:
            return "Протез";
        case Karset:
            return "Корсет грудопоясничный";
        case Splint:
            return "Тутор";
        case Bandage:
            return "Бандаж";
        case Knee:
            return "Наколенники";
        case TrussAntral:
            return "Грыжевой бандаж (антральная грыжа)";
        case Truss:
            return "Грыжевой бандаж (паховая грыжа)";
        case OrthopedicShoes:
            return "Ортопедическая обувь";
        case Breast:
            return "Протез молочной железы";
        case Headholder:
            return "Головодержатель";
        default:
            qDebug() << "Warning:  Empty article in Order!";
            return "";
    }
}

