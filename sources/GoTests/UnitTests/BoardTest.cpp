#include <QString>
#include <QtTest>

#include <vector>
#include <iostream>

#include "../../GoEngine/Board.h"

using std::vector;

class BoardTest : public QObject
{
Q_OBJECT

public:
    BoardTest();


private Q_SLOTS:
    void getDiagonal();
    void initializationDiagonal();
    void indexation();
    void assigment();

};

BoardTest::BoardTest()
{
}

void BoardTest::getDiagonal()
{
    Board b{19};
    QCOMPARE(b.getDiagonal(), 19);
    Board b1{7};
    QCOMPARE(b1.getDiagonal(), 7);
}

void BoardTest::initializationDiagonal()
{
    Board b{13};
    for( int i = 0; i < 13; ++i )
    {
        for (int j = 0; j < 13; ++j)
        {
            QVERIFY(b(i, j).isEmpty());
        }
    }
}

void BoardTest::indexation()
{
    Board b{19};
    b(0, 0) = BLACK;
    b(18, 18) = WHITE;
    QVERIFY(b(0, 0).getStatus() == BLACK);
    QVERIFY(b(18, 18).getStatus() == WHITE);
}

void BoardTest::assigment()
{
    Board b1{7};
    b1(0, 0) = BLACK;
    b1(6, 6) = WHITE;
    Board b2 = b1;
    QVERIFY(b1(0, 0).getStatus() == b2(0, 0).getStatus());
    QVERIFY(b1(6, 6).getStatus() == b2(6, 6).getStatus());
}

QTEST_APPLESS_MAIN(BoardTest)

#include "BoardTest.moc"