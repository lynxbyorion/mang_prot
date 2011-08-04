#include <QtTest/QtTest>

class ClientWindowTest: public QObject
{
    Q_OBJECT

  private slots:
    void toUpper();
};

void ClientWindowTest::toUpper()
{
    QString str("Hello test");
    QCOMPARE(str.toUpper(), QString("HELLO TEST"));
}

QTEST_MAIN(ClientWindowTest)
#include "test_clientwindow.moc"
