/**
 * \file clientmodel.h
 * \bref This class of model client.
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-05-03
 *
 */

#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include <QString>

class DataBaseManager;
class Order;

class Client
{
  public:
    //! enumeration type of disability
    enum Disability {
        EmptyDisability = 0,
        War,        //! disabled veteran
        Infancy,    //! disabled child
        Work,       //! disabled social work
        General     //! invalid common disease
    };
    //! Group disability
    enum Group {
        EmptyGroup = 0,
        GroupIII,
        GroupII,
        GroupI
    };

  public:
    Client ();

    void setID(int i) { id = i; }
    int getID() { return id; }
    void setName(QString);
    QString getName() { return name; }
    void setSurname(QString s);
    QString getSurname() { return surname; }
    void setPatronymic(QString p);
    QString getPatronymic() { return patronymic; }
    void setYear(int y) { yearOfBirth = y; }
    int getYear() { return yearOfBirth; }
    void setAddr(QString addr) { address = addr; }
    QString getAddr() { return address; }
    void setDisability(Disability d) { disability = d; }
    Disability getDisability() { return disability; }
    void setGroup(Group g) { group = g; }
    Group getGroup() { return group; }

    QString getDisabilityToString();
    QString getGroupToString();

  private:
    int id;
    QString name;
    QString surname;
    QString patronymic;
    int yearOfBirth;
    QString address;    //! Address of the client
    Disability disability;
    Group group;

};

/**
 *  @short This model for client.
 */
class ClientModel: public QObject
{
  public:
    ClientModel();

    /**
     * Get instance Client by ID.
     */
    Client& getClient(int id);
    /*
     * Get client orders
     */
    void getClientOrders(int id, QList<Order*> &clientOrders);
    /*
     * insert order
     */
    void insertOrder(Order &);
    /**
     * remove order
     */
    void removeOrder(const int idx_);

  private:
    DataBaseManager* db;
};

#endif //CLIENTMODEL_H
