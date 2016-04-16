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
    void throwingExceptions();
};

MotionTest::MotionTest()
{
}

void MotionTest::throwingExceptions()
{
    Board* board = new Board(19);
    Motion* motion = new Motion();

//    //QVERIFY_EXCEPTION_THROWN( motion->putStone(board, 0, 19), MoveBeyondBoardException);
//    //QVERIFY_EXCEPTION_THROWN( motion->putStone(board, -1, 18), MoveBeyondBoardException);
//    //QVERIFY_EXCEPTION_THROWN( motion->putStone(board, 20, 30), MoveBeyondBoardException);
//
    motion->putStone(board, 5, 7);
    //motion->putStone(board, 5, 7);
//    motion->putStone(board, 5, 8);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 7), MoveToNotEmptyPointException);

//    motion->putStone(board, 5, 8);
//    std::cout << motion->getMotionIndex() << std::endl;
//    vector<Moves> v = motion->getMoves();
//    std::cout << 4 << std::endl;
//    QVERIFY(v[0] == v[2]);
//    QVERIFY(v[1] == v[3]);
//    for( int i = 0; i < motion->getMotionIndex(); ++i )
//    {
//        std::cout << v[i].getFirst() << std::endl;
//        std::cout << v[i].getSecond() << std::endl;
//        std::cout << std::endl;
//    }
//
//    QVERIFY_EXCEPTION_THROWN( motion->putStone(board, 5, 7), MoveRepeatException);

    delete board;
    delete motion;
}

QTEST_APPLESS_MAIN(MotionTest)

#include "MotionTest.moc"