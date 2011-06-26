/**
 * \file iviewclientform.h
 * \bref In this file define class interface for view.
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-06-25
 */

#ifndef IVIEWCLIENTFORM_H
#define IVIEWCLIENTFORM_H

class IViewClientForm
{
  public:
    virtual void setFullName(QString) = 0;
    virtual void setDisability(QString) = 0;
    virtual void setAddress(QString) = 0;
    virtual void setOrdersList(QStringList) = 0;
    virtual void setOrderData(QStringList) = 0;
};

#endif // IVIEWCLIENTFORM_H
