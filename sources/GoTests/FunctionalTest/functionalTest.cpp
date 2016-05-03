#include <QString>
#include <QtTest>
#include <vector>
#include <iostream>
#include <sstream>

#include "../../GoEngine/Model/GoEngineInterface.h"
#include "InitBoards.h"

using namespace std;

class FunctionalTest : public QObject
{
Q_OBJECT

public:
    FunctionalTest();

private Q_SLOTS:
    void checkNewDelete();
    void paintBoard();
    void makeMove();
};

FunctionalTest::FunctionalTest()
{

}

void FunctionalTest::checkNewDelete()
{
    GoEngineInterface* go = new GoEngineInterface;
    delete go;
    go = nullptr;
    delete go;
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