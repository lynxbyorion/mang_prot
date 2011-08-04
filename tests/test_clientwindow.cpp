#include "test_clientwindow.h"

#include <QtTest/QtTest>

#include <clientwindow.h>

void ClientWindowTest::init()
{
    clientWindow = new ClientWindow();
}

void ClientWindowTest::toUpper()
{
    QString str("Hello test");
    QCOMPARE(str.toUpper(), QString("HELLo TEST"));
}

void ClientWindowTest::testSetFullName()
{
    //ClientWindow* clientWindow = new ClientWindow();
    QString name("Иван Иванович Иванов");

    QCOMPARE("A", "A");
}

QTEST_MAIN(ClientWindowTest)
#include "test_clientwindow.moc"
