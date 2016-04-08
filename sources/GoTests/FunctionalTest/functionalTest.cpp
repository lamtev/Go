#include <QString>
#include <QtTest>
#include <vector>
#include <iostream>

using namespace std;

#include "../../GoEngine/GoEngineInterface.h"
#include "../../GoCUI/InitBoards.h"
#include "../../GoEngine/enums.h"

class FunctionalTest : public QObject
{
Q_OBJECT

public:
    FunctionalTest();

private Q_SLOTS:
    void start();
    void paintBoard();
};

FunctionalTest::FunctionalTest()
{
}

void FunctionalTest::start()
{
    GoEngineInterface Go;
    Go.startGame(19, JAPANESE, NIGIRI);
}

void FunctionalTest::paintBoard()
{
    for( int i = 0; i < 21 * 43; ++ i )
    {
        if (i % 43 == 0)
        {
            cout << endl;
        }
        cout << BOARD19[i];
    }
    cout << endl;
}

QTEST_APPLESS_MAIN(FunctionalTest)

#include "functionalTest.moc"