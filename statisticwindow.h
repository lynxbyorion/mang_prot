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

class QPushButton;

class StatisticWindow: public QDialog
{
    Q_OBJECT

  public:
        StatisticWindow();

  private:
    QPushButton *pbPrint;
    QPushButton *pbClose;
};

#endif // STATISTICWINDOW_H
