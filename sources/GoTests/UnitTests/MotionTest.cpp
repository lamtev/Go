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
};

MotionTest::MotionTest()
{
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

QTEST_APPLESS_MAIN(MotionTest)

#include "MotionTest.moc"