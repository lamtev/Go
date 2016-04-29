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

MotionTest::MotionTest(){}

void MotionTest::putStone()
{
    Board* board = new Board{ 19 };
    Motion* motion = new Motion{};

    int ind{ 0 };
    for( int i = 1; i <= 19; ++i )
    {
        for( int j = 1; j <= 19; ++j )
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
        Board* board = new Board{ 19 };
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
    Board* board = new Board{ 19 };
    Motion* motion = new Motion{};

    motion->pass();
    motion->pass();
    QVERIFY(motion->isGameOver());

    delete board;
    delete motion;



    board = new Board{ 19 };
    motion = new Motion{};

    motion->putStone(board, A, 3);
    motion->putStone(board, D, 3);
    motion->putStone(board, B, 2);
    motion->pass();
    motion->putStone(board, C, 2);
    motion->putStone(board, B, 4);
    motion->pass();
    motion->pass();
    QVERIFY(motion->isGameOver());

    delete board;
    delete motion;


    board = new Board{ 19 };
    motion = new Motion{};

    motion->surrender();
    QVERIFY(motion->isGameOver());

    delete board;
    delete motion;
}

void MotionTest::whoSurrendered()
{
    Board* board = new Board{ 7 };
    Motion* motion = new Motion{};

    motion->putStone(board, A, 6);
    motion->putStone(board, C, 2);
    motion->putStone(board, A, 5);
    motion->surrender();
    int status{ WHITE };
    QCOMPARE(motion->whoSurrendered(), status);

    delete board;
    delete motion;


    board = new Board{ 7 };
    motion = new Motion{};

    motion->putStone(board, B, 6);
    motion->putStone(board, C, 2);
    status = EMPTY;
    QCOMPARE(motion->whoWon(), status);

    delete board;
    delete motion;
}

void MotionTest::whoWon()
{
    Board* board = new Board{ 7 };
    Motion* motion = new Motion{};

    motion->putStone(board, A, 6);
    motion->putStone(board, C, 2);
    motion->putStone(board, A, 5);
    motion->surrender();
    int status{ BLACK };
    QCOMPARE(motion->whoWon(), status);

    delete board;
    delete motion;


    board = new Board{ 7 };
    motion = new Motion{};

    motion->putStone(board, A, 6);
    motion->putStone(board, C, 2);
    motion->surrender();
    status = WHITE;
    QCOMPARE(motion->whoWon(), status);

    delete board;
    delete motion;

    
    board = new Board{ 7 };
    motion = new Motion{};

    motion->putStone(board, A, 6);
    motion->putStone(board, C, 2);
    status = EMPTY;
    QCOMPARE(motion->whoWon(), status);

    delete board;
    delete motion;

}

void MotionTest::getMoveIndex()
{
    Board* board = new Board{ 7 };
    Motion* motion = new Motion();

    QCOMPARE(motion->getMoveIndex(), 0);
    motion->putStone(board, A, 7);
    QCOMPARE(motion->getMoveIndex(), 1);
    motion->putStone(board, C, 2);
    QCOMPARE(motion->getMoveIndex(), 2);
    motion->putStone(board, A, 5);
    QCOMPARE(motion->getMoveIndex(), 3);
    motion->pass();
    QCOMPARE(motion->getMoveIndex(), 4);
    motion->putStone(board, A, 1);
    QCOMPARE(motion->getMoveIndex(), 5);

    delete board;
    delete motion;
}

void MotionTest::getMoves()
{
    Board* board = new Board{ 7 };
    Motion* motion = new Motion{};
    std::vector<Move> v{ Move{ A, 1 }, Move{ A, 2 }, Move{ A, 3 }, Move{ E, 1 } };

    motion->putStone(board, A, 1);
    motion->putStone(board, A, 2);
    motion->putStone(board, A, 3);
    motion->putStone(board, E, 1);

    for( int i = 0; i < 4; ++i )
    {
        QCOMPARE(v[i].getFirst(), motion->getMoves()[i].getFirst());
        QCOMPARE(v[i].getSecond(), motion->getMoves()[i].getSecond());
    }

    delete board;
    delete motion;
}

void MotionTest::whoseMove()
{
    Board* board = new Board{ 13 };
    Motion* motion = new Motion{};

    QVERIFY(motion->whoseMove() == BLACK);
    motion->pass();
    QVERIFY(motion->whoseMove() == WHITE);
    motion->putStone(board, A, 13);
    QVERIFY(motion->whoseMove() == BLACK);
    motion->pass();
    QVERIFY(motion->whoseMove() == WHITE);

    delete board;
    delete motion;
}

void MotionTest::getLastMove()
{
    Board* board = new Board{ 19 };
    Motion* motion = new Motion{};

    motion->putStone(board, A, 3);
    motion->putStone(board, D, 3);
    Move move{ D, 3 };
    QCOMPARE(motion->getLastMove(), move);
    motion->putStone(board, B, 2);
    motion->putStone(board, C, 2);
    motion->putStone(board, B, 4);
    move = Move{ B, 4 };
    QCOMPARE(motion->getLastMove(), move);
    motion->putStone(board, C, 4);
    motion->putStone(board, C, 3);
    move = Move{ C, 3 };
    QCOMPARE(motion->getLastMove(), move);
    motion->putStone(board, B, 3);
    move = Move{ B, 3 };
    QCOMPARE(motion->getLastMove(), move);

    delete board;
    delete motion;
}

void MotionTest::getStonesEatenBy()
{
    //Перестанет падать, когда будет реализовано съедение и подсчет съеденных камней!!!
    Board* board = new Board{ 19 };
    Motion* motion = new Motion{};

    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, A, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, D, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, B, 2);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, C, 2);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, B, 4);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, C, 4);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, C, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 0);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);
    motion->putStone(board, B, 3);
    QCOMPARE(motion->getStonesEatenByWhite(), 1);
    QCOMPARE(motion->getStonesEatenByBlack(), 0);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveOutsideTheBoardException()
{
    Board* board = new Board{ 19 };
    Motion* motion = new Motion{};

    motion->putStone(board, A, 1);
    motion->putStone(board, S, 19);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 0), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 5, 20), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -2, 7), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 20, 7), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -3, -2), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, -4, 30), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 20, 0), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, 27, 100), MoveOutsideTheBoardException);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveToNotEmptyPointException()
{
    Board* board = new Board{ 19 };
    Motion* motion = new Motion{};

    motion->putStone(board, E, 7);
    motion->putStone(board, E, 8);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, E, 7), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, E, 8), MoveToNotEmptyPointException);
    motion->putStone(board, S, 12);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, S, 12), MoveToNotEmptyPointException);
    motion->putStone(board, D, 2);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, D, 2), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, E, 7), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, E, 8), MoveToNotEmptyPointException);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveRepeatException()
{
    //падает, т.к не реализовано съедение
    Board* board = new Board{ 7 };
    Motion* motion = new Motion{};

    motion->putStone(board, B, 4);
    motion->putStone(board, E, 4);
    motion->putStone(board, C, 3);
    motion->putStone(board, D, 3);
    motion->putStone(board, C, 5);
    motion->putStone(board, D, 5);
    motion->putStone(board, D, 4);
    motion->putStone(board, C, 4);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, D, 4), MoveRepeatException);

    delete board;
    delete motion;
}

void MotionTest::throwingMoveToDieException()
{
    //Не проходятся, т.к не реализовано съедение
    //и не реализовано определение хода под смерть
    Board* board = new Board{ 13 };
    Motion* motion = new Motion{};

    motion->putStone(board, B, 1);
    motion->putStone(board, B, 2);
    motion->putStone(board, A, 2);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, A, 1), MoveToDieException);

    motion->putStone(board, A, 11);
    motion->putStone(board, B, 13);
    motion->putStone(board, B, 10);
    motion->putStone(board, C, 13);
    motion->putStone(board, C, 11);
    motion->putStone(board, D, 13);
    motion->putStone(board, B, 12);
    QVERIFY_EXCEPTION_THROWN(motion->putStone(board, B, 11), MoveToDieException);

    delete board;
    delete motion;
}


QTEST_APPLESS_MAIN(MotionTest)

#include "MotionTest.moc"