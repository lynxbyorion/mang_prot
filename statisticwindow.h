/**
 * \file statisticwindow.h
 * \bref This class is view and shows statistics by orders.
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-07-18
 *
 */

#ifndef STATISTICWINDOW_H
#define STATISTICWINDOW_H

#include <QDialog>

class DataBaseManager;

class QLabel;
class QDateEdit;
class QPushButton;

class StatisticWindow: public QDialog
{
    Q_OBJECT

  public:
    StatisticWindow();

  private slots:
    //! get count type article
    int getCoutArticle(int article);

  private:
    int allCount;

    QLabel *countProsthesis;
    QLabel *countKarset;
    QLabel *countSplint;
    QLabel *countBandage;
    QLabel *countKnee;
    QLabel *countTrussAntral;
    QLabel *countTruss;
    QLabel *countShoes;
    QLabel *countBreast;
    QLabel *countHeadholder;
    QLabel *lbAllCount;

    QDateEdit *beginDate;
    QDateEdit *endDate;

    QPushButton *pbPrint;
    QPushButton *pbClose;

    DataBaseManager* db;
};

#endif // STATISTICWINDOW_H
