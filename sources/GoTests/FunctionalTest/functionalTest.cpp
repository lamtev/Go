#include <QString>
#include <QtTest>
#include <vector>
#include <iostream>
#include <sstream>

#include "../../GoEngine/GoEngineInterface.h"
#include "../../GoEngine/enums.h"
#include "InitBoards.h"

using namespace std;

class FunctionalTest : public QObject
{
Q_OBJECT

public:
    FunctionalTest();

private Q_SLOTS:
    void start();
    void paintBoard();
    void makeMove();
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
        cout << BOARD19A[i];
    }
    cout << endl;
}

void FunctionalTest::makeMove()
{

}


QTEST_APPLESS_MAIN(FunctionalTest)

#include "functionalTest.moc"