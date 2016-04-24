#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/Motion.h"
//TODO finish class
class MotionTest : public QObject
{
Q_OBJECT

public:
    MotionTest();


private Q_SLOTS:
    void putStone();
    void pass();
    void isGameOver();
    void throwingMoveOutsideTheBoardException();
    void throwingMoveToNotEmptyPointException();
    void throwingMoveRepeatException();
    void throwingMoveToDieException();
};

MotionTest::MotionTest()
{
}

void MotionTest::putStone()
{
    Board* board = new Board(19);
    Motion* motion = new Motion();

    int ind = 0;
    for( int i = 0; i < 19; ++i )
    {
        for( int j = 0; j < 19; ++j )
        {
            motion->putStone(board, i, j);
            QCOMPARE(motion->getMoves()[ind].getFirst(), i);
            QCOMPARE(motion->getMoves()[ind].getSecond(), j);
            ++ind;
        }
    }

    delete board;
    delete motion;
}

void MotionTest::pass()
{
    {
        Board* board = new Board(19);
        Motion* motion = new Motion();

        motion->pass();
        QCOMPARE(motion->getMoves()[0].getFirst(), PASS_COORD);
        QCOMPARE(motion->getMoves()[0].getSecond(), PASS_COORD);

        delete board;
        delete motion;
    }

}

void MotionTest::isGameOver()
{
    {
        Board*board = new Board(19);
        Motion*motion = new Motion();

        motion->pass();
        motion->pass();
        QVERIFY(motion->isGameOver());

        delete board;
        delete motion;
    }

    {
        Board*board = new Board(19);
        Motion*motion = new Motion();

        motion->putStone(board, 1, 3);
        motion->putStone(board, 4, 3);
        motion->putStone(board, 2, 2);
        motion->pass();
        motion->putStone(board, 3, 2);
        motion->putStone(board, 2, 4);
        motion->pass();
        motion->pass();
        QVERIFY(motion->isGameOver());

        delete board;
        delete motion;
    }
}

void MotionTest::throwingMoveOutsideTheBoardException()
{
    Board* board = new Board(19);
    Motion* motion = new Motion();

    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, -1), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 19), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -2, 7), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 20, 7), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -3, -2), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -4, 30), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 20, -1), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 27, 100), MoveOutsideTheBoardException);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveToNotEmptyPointException()
{
    Board* board = new Board(19);
    Motion* motion = new Motion();

    motion->putStone(board, 5, 7);
    motion->putStone(board, 5, 8);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 7), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 8), MoveToNotEmptyPointException);
    motion->putStone(board, 18, 12);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 18, 12), MoveToNotEmptyPointException);
    motion->putStone(board, 4, 2);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 4, 2), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 7), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 8), MoveToNotEmptyPointException);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveRepeatException()
{
    //падает, т.к не реализовано съедение
    Board* board = new Board(7);
    Motion* motion = new Motion();

    motion->putStone(board, 1, 3);
    motion->putStone(board, 4, 3);
    motion->putStone(board, 2, 2);
    motion->putStone(board, 3, 2);
    motion->putStone(board, 2, 4);
    motion->putStone(board, 3, 4);
    motion->putStone(board, 3, 3);
    motion->putStone(board, 2, 3);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 3, 3), MoveRepeatException);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveToDieException()
{
    //Не проходятся, т.к не реализовано съедение
    //и не реализовано определение хода под смерть
    Board* board = new Board(13);
    Motion* motion = new Motion();

    motion->putStone(board, 1, 0);
    motion->putStone(board, 1, 1);
    motion->putStone(board, 0, 1);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 0, 0), MoveToDieException);

    motion->putStone(board, 7, 7);
    motion->putStone(board, 12, 12);
    motion->putStone(board, 8, 6);
    motion->putStone(board, 12, 11);
    motion->putStone(board, 8, 8);
    motion->putStone(board, 12, 10);
    motion->putStone(board, 9, 7);
    motion->putStone(board, 12, 9);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 8, 7), MoveToDieException);

    delete board;
    delete motion;
}




QTEST_APPLESS_MAIN(MotionTest)

#include "MotionTest.moc"