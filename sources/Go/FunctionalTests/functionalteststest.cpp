#include <QString>
#include <QtTest>

class FunctionalTests : public QObject
{
    Q_OBJECT

public:
    FunctionalTests();

private Q_SLOTS:
    void tst_cs1();
};

FunctionalTests::FunctionalTests()
{
}

void FunctionalTests::tst_cs1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(FunctionalTests)

#include "functionalteststest.moc"
