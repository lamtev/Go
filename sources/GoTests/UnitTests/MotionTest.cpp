#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/Motion.h"

class MotionTest : public QObject
{
Q_OBJECT

public:
    MotionTest();


private Q_SLOTS:
    void putStone();
    void pass();
    void isGameOver();
    void whoSurrendered();
    void whoWon();
    void getMoveIndex();
    void getMoves();
    void whoseMove();
    void getLastMove();
    void getStonesEatenBy();
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
    Board* board = new Board{19};
    Motion* motion = new Motion{};

    int ind{0};
    for( int i{0}; i < 19; ++i )
    {
        for( int j{0}; j < 19; ++j )
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
        Board* board = new Board{19};
        Motion* motion = new Motion{};

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
        Board* board = new Board{19};
        Motion* motion = new Motion{};

        motion->pass();
        motion->pass();
        QVERIFY(motion->isGameOver());

        delete board;
        delete motion;
    }

    {
        Board* board = new Board{19};
        Motion* motion = new Motion{};

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

    {
        Board* board = new Board{19};
        Motion* motion = new Motion{};

        motion->surrender();
        QVERIFY(motion->isGameOver());

        delete board;
        delete motion;
    }
}

void MotionTest::whoSurrendered()
{
    {
        Board* board = new Board{7};
        Motion* motion = new Motion{};

        motion->putStone(board, 0, 6);
        motion->putStone(board, 3, 2);
        motion->putStone(board, 1, 5);
        motion->surrender();
        int status{WHITE};
        QCOMPARE(motion->whoSurrendered(), status);

        delete board;
        delete motion;
    }

    {
        Board* board = new Board{7};
        Motion* motion = new Motion{};

        motion->putStone(board, 0, 6);
        motion->putStone(board, 3, 2);
        int status{EMPTY};
        QCOMPARE(motion->whoWon(), status);

        delete board;
        delete motion;
    }
}

void MotionTest::whoWon()
{
    {
        Board* board = new Board{7};
        Motion* motion = new Motion{};

        motion->putStone(board, 0, 6);
        motion->putStone(board, 3, 2);
        motion->putStone(board, 1, 5);
        motion->surrender();
        int status{BLACK};
        QCOMPARE(motion->whoWon(), status);

        delete board;
        delete motion;
    }

    {
        Board* board = new Board{7};
        Motion* motion = new Motion{};

        motion->putStone(board, 0, 6);
        motion->putStone(board, 3, 2);
        motion->surrender();
        int status{WHITE};
        QCOMPARE(motion->whoWon(), status);

        delete board;
        delete motion;
    }

    {
        Board* board = new Board{7};
        Motion* motion = new Motion{};

        motion->putStone(board, 0, 6);
        motion->putStone(board, 3, 2);
        int status{EMPTY};
        QCOMPARE(motion->whoWon(), status);

        delete board;
        delete motion;
    }
}

void MotionTest::getMoveIndex()
{
    Board* board = new Board{7};
    Motion* motion = new Motion();

    QCOMPARE(motion->getMoveIndex(), 0);
    motion->putStone(board, 0, 6);
    QCOMPARE(motion->getMoveIndex(), 1);
    motion->putStone(board, 3, 2);
    QCOMPARE(motion->getMoveIndex(), 2);
    motion->putStone(board, 1, 5);
    QCOMPARE(motion->getMoveIndex(), 3);
    motion->pass();
    QCOMPARE(motion->getMoveIndex(), 4);
    motion->putStone(board, 1, 1);
    QCOMPARE(motion->getMoveIndex(), 5);

    delete board;
    delete motion;
}

void MotionTest::getMoves()
{
    Board* board = new Board{7};
    Motion* motion = new Motion{};
    std::vector<Move> v{Move{0,0}, Move{0,1}, Move{0,2}, Move{5,1}};

    motion->putStone(board, 0, 0);
    motion->putStone(board, 0, 1);
    motion->putStone(board, 0, 2);
    motion->putStone(board, 5, 1);

    for( int i{0}; i < 4; ++i )
    {
        QCOMPARE(v[i].getFirst(), motion->getMoves()[i].getFirst());
        QCOMPARE(v[i].getSecond(), motion->getMoves()[i].getSecond());
    }

    delete board;
    delete motion;
}

void MotionTest::whoseMove()
{
    Board* board = new Board{13};
    Motion* motion = new Motion{};

    QVERIFY(motion->whoseMove() == BLACK);
    motion->pass();
    QVERIFY(motion->whoseMove() == WHITE);
    motion->putStone(board, 0, 12);
    QVERIFY(motion->whoseMove() == BLACK);
    motion->pass();
    QVERIFY(motion->whoseMove() == WHITE);

    delete board;
    delete motion;
}

void MotionTest::getLastMove()
{
    Board* board = new Board{19};
    Motion* motion = new Motion{};

    motion->putStone(board, 1, 3);
    motion->putStone(board, 4, 3);
    Move move{4, 3};
    QCOMPARE(motion->getLastMove(), move);
    motion->putStone(board, 2, 2);
    motion->putStone(board, 3, 2);
    motion->putStone(board, 2, 4);
    move = Move{2, 4};
    QCOMPARE(motion->getLastMove(), move);
    motion->putStone(board, 3, 4);
    motion->putStone(board, 3, 3);
    move = Move{3, 3};
    QCOMPARE(motion->getLastMove(), move);
    motion->putStone(board, 2, 3);
    move = Move{2, 3};
    QCOMPARE(motion->getLastMove(), move);

    delete board;
    delete motion;
}

void MotionTest::getStonesEatenBy()
{
    //Перестанет падать, когда будет реализовано съедение и подсчет съеденных камней!!!
    Board* board = new Board{19};
    Motion* motion = new Motion{};

    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 1, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 4, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 2, 2);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 3, 2);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 2, 4);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 3, 4);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 3, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, 2, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 1);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveOutsideTheBoardException()
{
    Board* board = new Board{19};
    Motion* motion = new Motion{};

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
    Board* board = new Board{19};
    Motion* motion = new Motion{};

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
    Board* board = new Board{7};
    Motion* motion = new Motion{};

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
    Board* board = new Board{13};
    Motion* motion = new Motion{};

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