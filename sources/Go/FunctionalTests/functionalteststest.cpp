#include <QString>
#include <QtTest>

class FunctionalTests : public QObject
{
    Q_OBJECT

public:
    FunctionalTests();

private Q_SLOTS:

};

FunctionalTests::FunctionalTests()
{
}

QTEST_APPLESS_MAIN(FunctionalTests)

#include "functionalteststest.moc"
