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
    virtual void refresh() = 0;

    virtual void setName(QString) = 0;
    virtual QString getName() const = 0;
    virtual QString getLastName() const = 0;
    virtual QString getPatronymic() const =0;
    virtual int getYear() const = 0;
    virtual QString getAddress() const = 0;
    virtual Client::Disability getDisability() const = 0;
    virtual Client::Group getGroup() const = 0;

    virtual void setList( QStringList ) = 0;

public: // signals
    /**
     * emit when changing text in line edit Name of.
     */
    virtual void actionFindClient() = 0;
    /**
     * emit when pressed button pbAdd for addition
     * client in database.
     */
    virtual void actionAddClient() = 0;
    /**
     * emit when pressed button pbRemoveClient
     */
    virtual void actionRemoveClient(const int) = 0;
    /**
     * emit end return index item of list
     */
    virtual void actionReturnIndex(const int) = 0;
};

#endif //IVIEWFORM_H
