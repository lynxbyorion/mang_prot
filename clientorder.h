/**
 * \file clientorder.h
 * \bref Thes class define order of client.
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-06-15
 *
 */

#ifndef CLIENTORDER_H
#define CLIENTORDER_H

#include <string>

#include <QDate>

class Order {

  public:
      //! type of payment of order
      enum Payment {
          Fss = 0,
          Cash,
          Compensation
      };

      //! type of article
      enum Article
      {
          Prosthesis = 0,
          Karset,
          Splint,
          Bandage,
          Knee,
          TrussAntral,
          Truss,
          OrthopedicShoes,
          Breast,
          Headholder
      };

  public:
    Order();

    void setID(int i) { id = i; }
    int getID() { return id; }
    void setIDClient(int i) { idClient = i; }
    int getIDClient() { return idClient; }
    void setPayment(Payment p) { payment = p; }
    Payment getPayment() { return payment; }
    void setReceptionDate(QDate date) { receptionDate = date; }
    QDate getReceptionDate() { return receptionDate; }
    void setDeliveryDate(QDate date) { deliveryDate = date; }
    QDate getDeliveryDate() { return deliveryDate; }
    void setDiagnosis(QString d) { diagnosis = d; }
    QString getDiagnosis() { return diagnosis; }
    void setArticle(Article a) { article = a; }
    Article getArticle() { return article; }

    QString getPaymentToString();
    QString getArticleToString();

  private:
    int id;
    int idClient;
    Payment payment;
    QDate   receptionDate;
    QDate   deliveryDate;
    QString diagnosis;
    Article article;
};

#endif // CLIENTORDER_H
