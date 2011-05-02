/**
 * \file clientmodel.h
 * \bref This class of model client.
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-05-03
 *
 */

#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

class string;

class Client
{
public:
    //! enumeration type of disability
    enum Disability {
        War = 0,    //! disabled veteran
        Infancy,    //! disabled child
        Work,       //! disabled social work
        General     //! invalid common disease
    };
    //! Group disability
    enum Group {
        GroupIII = 0,
        GroupII,
        GroupI
    };

public:
    Client ();

    void setName(string n) { name = n; }
    string getName() { return name; }
    void setSurname(string s) { surname = s; }
    string getSurname() { return surname; }
    void setPatronymic(string p) { patronymic = p; }
    string getPatronymic() { return patronymic; }
    void setYear(int y) { yearOfBirth = y; }
    int getYear() { return yearOfBirth; }
    void setAddr(string addr) { address = addr; }
    string getAddr() { return address; }
    void setDisability(Disability d) { disability = d; }
    Disability getDisability() { return disability; }
    void setGroup(Group g) { group = g; }
    Group getGroup() { return group; }

private:
    string name;
    string surname;
    string patronymic;
    int yearOfBirth;
    string address;    //! Address of the client
    Disability disability;
    Group group;

};
#endif //CLIENTMODEL_H
