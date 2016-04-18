#include <QString>
#include <QtTest>
#include <vector>
#include <iostream>

#include "../../GoEngine/GoEngineInterface.h"
#include "../../GoCUI/InitBoards.h"
#include "../../GoEngine/enums.h"

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
        cout << BOARD19[i];
    }
    cout << endl;
}

void FunctionalTest::makeMove()
{
    GoEngineInterface Go;
    Go.startGame(19, JAPANESE, NIGIRI);
    int x, y;
    int counter = 0;
    while( true )
    {
        if( counter % 2 == 0 )
        {
            cout << "Black" << endl;
            cout << "Input coordinates" << endl;
            cin >> x >> y;
            x = 99;
            if( x == 99 )
            {
                break;
            }
            Go.putStone(x, y);
        }
        else
        {
            cout << "White" << endl;
            cout << "Input coordinates" << endl;
            cin >> x >> y;
            x = 99;
            if( x == 99 )
            {
                break;
            }
            Go.putStone(x, y);
        }
        counter = (++counter) % 2;
    }
}

QTEST_APPLESS_MAIN(FunctionalTest)

#include "functionalTest.moc"