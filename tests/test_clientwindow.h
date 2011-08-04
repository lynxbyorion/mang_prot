/**
 * © Copyright 2011 Gennady Sazonov. All Rights Reserved.
 * 2011-08-04
 */

#ifndef TEST_CLIENTWINDOW_H
#define TEST_CLIENTWINDOW_H

#include <QDialog>
#include <QObject>

class ClientWindow;

class ClientWindowTest: public QObject
{
    Q_OBJECT

  private Q_SLOTS:
    void init();

    void toUpper();
    void testSetFullName();

  private:
    ClientWindow *clientWindow;
};

#endif // TEST_CLIENTWINDOW_H
