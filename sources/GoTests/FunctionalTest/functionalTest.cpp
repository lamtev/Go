#include <QString>
#include <QtTest>

class FunctionalTest : public QObject
{
    Q_OBJECT

public:
    FunctionalTest();

private Q_SLOTS:
    void testCase1();
};

FunctionalTest::FunctionalTest()
{
}

void FunctionalTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(FunctionalTest)

#include "functionaltest.moc"
