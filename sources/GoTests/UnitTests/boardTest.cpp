#include <QString>
#include <QtTest>

#include "../../GoEngine/Board.h"

class BoardTest : public QObject
{
Q_OBJECT

public:
    BoardTest();


private Q_SLOTS:
    void initialization();
    void indexation();

};

BoardTest::BoardTest()
{
}

void BoardTest::initialization()
{
    Board<int> b(19);
    QCOMPARE(b.getDiagonal(), 19);
}

void BoardTest::indexation()
{
    Board<int> b(7);
    b(1,1) = 4;
    b(0,1) = 128;
    b(1,0) = 5;
    b(0,0) = 3;
    QCOMPARE(b(1,1), 4);
    QCOMPARE(b(0,1), 128);
    QCOMPARE(b(1,0), 5);
    QCOMPARE(b(0,0), 3);
}

QTEST_APPLESS_MAIN(BoardTest)

#include "boardTest.moc"