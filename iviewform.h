/**
 * \file iviewform.h
 * \bref This file for define interface for forms
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-05-04
 *
 */
#ifndef IVIEWFORM_H
#define IVIEWFORM_H

#include "clientmodel.h"

/*!
 * This class interfase for class type form
 *
 */
class IViewForm {
public:
    virtual void setName(QString) = 0;
    virtual QString getName() const = 0;
    virtual QString getLastName() const = 0;
    virtual QString getPatronymic() const =0;
    virtual Client::Disability getDisability() const = 0;
    virtual Client::Group getGroup() const = 0;
    virtual QString getAddress() const = 0;

public: // signals
    virtual void actionFindClient() = 0;
};

#endif //IVIEWFORM_H
