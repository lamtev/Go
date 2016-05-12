#include <QString>
#include <QtTest>

#include "../../GoEngine/GoEngineAPI.h"

using namespace std;

class FunctionalTest : public QObject
{
Q_OBJECT

public:
    FunctionalTest();

private Q_SLOTS:
    void checkNewDelete();
};

FunctionalTest::FunctionalTest(){}

void FunctionalTest::checkNewDelete()
{
    GoEngineAPI* go = new GoEngineAPI;
    go->startGame(19, CHINESE, AGREEMENT);
    go->putStone(A, 3);
    delete go;
}

QTEST_APPLESS_MAIN(FunctionalTest)

#include "functionalTest.moc"