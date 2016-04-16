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
    void throwingMoveToNotEmptyPointException();
    void throwingMoveBeyondBoardException();
};

MotionTest::MotionTest()
{
}

void MotionTest::throwingMoveToNotEmptyPointException()
{
    //TODO MotionTest::throwingMoveToNotEmptyPointException
    Board* board = new Board(19);
    Motion* motion = new Motion();

    motion->putStone(board, 5, 7);
    motion->putStone(board, 18, 8);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveBeyondBoardException()
{
    Board* board = new Board(19);
    Motion* motion = new Motion();

    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 7, 19), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 10, 24), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -6, -1), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -20, -3), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -12, -6), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 35, 6), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 19, 3), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 27, 7), MoveBeyondBoardException);

    delete board;
    delete motion;

    Board* board1 = new Board(13);
    Motion* motion1 = new Motion();

    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, 7, 13), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, 10, 24), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, -6, -1), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, -20, -3), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, -12, -6), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, 13, 11), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, 15, 8), MoveBeyondBoardException);
    QVERIFY_EXCEPTION_THROWN(motion1->putStone(board1, 27, 5), MoveBeyondBoardException);

    delete board1;
    delete motion1;
}

QTEST_APPLESS_MAIN(MotionTest)

#include "MotionTest.moc"