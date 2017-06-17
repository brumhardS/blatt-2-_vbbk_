#include <QString>
#include <QtTest>

class ACOAlgorithmusTest : public QObject
{
    Q_OBJECT

public:
    ACOAlgorithmusTest();

private Q_SLOTS:
    void testCase1();
};

ACOAlgorithmusTest::ACOAlgorithmusTest()
{
}

void ACOAlgorithmusTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ACOAlgorithmusTest)

#include "tst_ACOAlgorithmusTest.moc"
