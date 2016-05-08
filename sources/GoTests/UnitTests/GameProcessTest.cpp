#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/GameProcess.h"

class GameProcessTest : public QObject
{
Q_OBJECT

public:
    GameProcessTest();


private Q_SLOTS:
    void putStone();
    void pass();
    void isGameOver();
    void whoSurrendered();
    void whoWon();
    void getMoveIndex();
    void getMoves();
    void getBoard();
    void whoseMove();
    void getLastMove();
    void getPenultMove();
    void getStonesEatenBy();
    void throwingMoveOutsideTheBoardException();
    void throwingMoveToNotEmptyPointException();
    void throwingMoveRepeatException();
    void throwingMoveToDieException();
};

GameProcessTest::GameProcessTest(){}

void GameProcessTest::putStone()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    int ind{ 0 };
    for( int i = 1; i <= 19; ++i )
    {
        for( int j = 1; j <= 19; ++j )
        {
            gameProcess->putStone(i, j);
            QCOMPARE(gameProcess->getMoves()[ind].getFirst(), i);
            QCOMPARE(gameProcess->getMoves()[ind].getSecond(), j);
            ++ind;
        }
    }
    
    delete gameProcess;
}

void GameProcessTest::pass()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    //todo неплохо бы до изменений проверить начальное состояние
    //а то вдруг любой ход будет координаты пасса давать
    gameProcess->pass();
    QCOMPARE(gameProcess->getMoves()[0].getFirst(), PASS_COORD);
    QCOMPARE(gameProcess->getMoves()[0].getSecond(), PASS_COORD);
        
    delete gameProcess;
}

void GameProcessTest::isGameOver()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    //todo неплохо бы до изменений проверить начальное состояние
    //а то вдруг и до пассов геймовер был
    gameProcess->pass();
    gameProcess->pass();
    QVERIFY(gameProcess->isGameOver());
    
    delete gameProcess;

    
    gameProcess = new GameProcess{ 7 };
    //todo неплохо бы до изменений проверить начальное состояние
    gameProcess->putStone(A, 3);
    gameProcess->putStone(D, 3);
    gameProcess->putStone(B, 2);
    gameProcess->pass();
    gameProcess->putStone(C, 2);
    gameProcess->putStone(B, 4);
    gameProcess->pass();
    gameProcess->pass();
    QVERIFY(gameProcess->isGameOver());
    
    delete gameProcess;

    
    gameProcess = new GameProcess{ 19 };

    //todo неплохо бы до изменений проверить начальное состояние
    gameProcess->surrender();
    QVERIFY(gameProcess->isGameOver());
    
    delete gameProcess;
}

void GameProcessTest::whoSurrendered()
{
    GameProcess* gameProcess = new GameProcess{ 7 };

    gameProcess->putStone(A, 6);
    gameProcess->putStone(C, 2);
    gameProcess->putStone(A, 5);
    gameProcess->surrender();
    QCOMPARE(gameProcess->whoSurrendered(), static_cast<int>(Status::WHITE));
    
    delete gameProcess;

    
    gameProcess = new GameProcess{ 7 };

    gameProcess->putStone(B, 6);
    gameProcess->putStone(C, 2);
    QCOMPARE(gameProcess->whoWon(), static_cast<int>(Status::EMPTY));
    
    delete gameProcess;
}

void GameProcessTest::whoWon()
{
    GameProcess* gameProcess = new GameProcess{ 7 };

    gameProcess->putStone(A, 6);
    gameProcess->putStone(C, 2);
    gameProcess->putStone(A, 5);
    gameProcess->surrender();
    QCOMPARE(gameProcess->whoWon(), static_cast<int>(Status::BLACK));
    
    delete gameProcess;
    
    gameProcess = new GameProcess{ 7 };

    gameProcess->putStone(A, 6);
    gameProcess->putStone(C, 2);
    gameProcess->surrender();
    QCOMPARE(gameProcess->whoWon(), static_cast<int>(Status::WHITE));
    
    delete gameProcess;

    
    gameProcess = new GameProcess{ 7 };

    gameProcess->putStone(A, 6);
    gameProcess->putStone(C, 2);
    QCOMPARE(gameProcess->whoWon(), static_cast<int>(Status::EMPTY));
    
    delete gameProcess;

}

void GameProcessTest::getMoveIndex()
{
    GameProcess* gameProcess = new GameProcess{ 7 };

    QCOMPARE(gameProcess->getMoveIndex(), 0);
    gameProcess->putStone(A, 7);
    QCOMPARE(gameProcess->getMoveIndex(), 1);
    gameProcess->putStone(C, 2);
    QCOMPARE(gameProcess->getMoveIndex(), 2);
    gameProcess->putStone(A, 5);
    QCOMPARE(gameProcess->getMoveIndex(), 3);
    gameProcess->pass();
    QCOMPARE(gameProcess->getMoveIndex(), 4);
    gameProcess->putStone(A, 1);
    QCOMPARE(gameProcess->getMoveIndex(), 5);
    
    delete gameProcess;
}

void GameProcessTest::getMoves()
{
    GameProcess* gameProcess = new GameProcess{ 7 };
    std::vector<Move> v{ Move{ A, 1 }, Move{ A, 2 }, Move{ A, 3 }, Move{ E, 1 } };

    gameProcess->putStone(A, 1);
    gameProcess->putStone(A, 2);
    gameProcess->putStone(A, 3);
    gameProcess->putStone(E, 1);

    for( int i = 0; i < 4; ++i )
    {
        QCOMPARE(v[i].getFirst(), gameProcess->getMoves()[i].getFirst());
        QCOMPARE(v[i].getSecond(), gameProcess->getMoves()[i].getSecond());
    }
    
    delete gameProcess;
}

void GameProcessTest::getBoard()
{
    GameProcess* gameProcess = new GameProcess{ 13 };

    for( int i = 1; i <= 13; ++i )
    {
        for( int j = 1; j <= 13; ++j )
        {
            QCOMPARE(gameProcess->getBoard().operator()(i, j).getStatus(), static_cast<int>(Status::EMPTY));
        }
    }
    gameProcess->putStone(A, 13);
    QCOMPARE(gameProcess->getBoard().operator()(A, 13).getStatus(), static_cast<int>(Status::BLACK));
    gameProcess->putStone(J, 7);
    QCOMPARE(gameProcess->getBoard().operator()(J, 7).getStatus(), static_cast<int>(Status::WHITE));

    delete gameProcess;
}

void GameProcessTest::whoseMove()
{
    GameProcess* gameProcess = new GameProcess { 13 };

    QCOMPARE(gameProcess->whoseMove(), static_cast<int>(Status::BLACK));
    gameProcess->pass();
    QCOMPARE(gameProcess->whoseMove(), static_cast<int>(Status::WHITE));
    gameProcess->putStone(A, 13);
    QCOMPARE(gameProcess->whoseMove(), static_cast<int>(Status::BLACK));
    gameProcess->pass();
    QCOMPARE(gameProcess->whoseMove(), static_cast<int>(Status::WHITE));
    
    delete gameProcess;
}

void GameProcessTest::getLastMove()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    gameProcess->putStone(A, 3);
    gameProcess->putStone(D, 3);
    Move move{ D, 3 };
    QCOMPARE(gameProcess->getLastMove(), move);
    gameProcess->putStone(B, 2);
    gameProcess->putStone(C, 2);
    gameProcess->putStone(B, 4);
    move = Move{ B, 4 };
    QCOMPARE(gameProcess->getLastMove(), move);
    gameProcess->putStone(C, 4);
    gameProcess->putStone(C, 3);
    move = Move{ C, 3 };
    QCOMPARE(gameProcess->getLastMove(), move);
    gameProcess->putStone(B, 3);
    move = Move{ B, 3 };
    QCOMPARE(gameProcess->getLastMove(), move);
    
    delete gameProcess;
}

void GameProcessTest::getPenultMove()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    gameProcess->putStone(A, 3);
    gameProcess->putStone(D, 3);
    Move move{ A, 3 };
    QCOMPARE(gameProcess->getPenultMove(), move);
    gameProcess->putStone(B, 2);
    gameProcess->putStone(C, 2);
    gameProcess->putStone(B, 4);
    move = Move{ C, 2 };
    QCOMPARE(gameProcess->getPenultMove(), move);
    gameProcess->putStone(C, 4);
    gameProcess->putStone(C, 3);
    move = Move{ C, 4 };
    QCOMPARE(gameProcess->getPenultMove(), move);
    gameProcess->putStone(B, 3);
    gameProcess->pass();
    move = Move{ B, 3 };
    QCOMPARE(gameProcess->getPenultMove(), move);

    delete gameProcess;
}

void GameProcessTest::getStonesEatenBy()
{
    //Перестанет падать, когда будет реализовано съедение и подсчет съеденных камней!!!
    GameProcess* gameProcess = new GameProcess{ 19 };

    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(A, 3);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(D, 3);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(B, 2);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(C, 2);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(B, 4);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(C, 4);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(C, 3);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 0);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    gameProcess->putStone(B, 3);
    QCOMPARE(gameProcess->getStonesEatenByWhite(), 1);
    QCOMPARE(gameProcess->getStonesEatenByBlack(), 0);
    
    delete gameProcess;
}

void GameProcessTest::throwingMoveOutsideTheBoardException()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    gameProcess->putStone(A, 1);
    gameProcess->putStone(S, 19);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(5, 0), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(5, 20), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(-2, 7), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(20, 7), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(-3, -2), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(-4, 30), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(20, 0), MoveOutsideTheBoardException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(27, 100), MoveOutsideTheBoardException);
    
    delete gameProcess;
}

void GameProcessTest::throwingMoveToNotEmptyPointException()
{
    GameProcess* gameProcess = new GameProcess{ 19 };

    gameProcess->putStone(E, 7);
    gameProcess->putStone(E, 8);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(E, 7), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(E, 8), MoveToNotEmptyPointException);
    gameProcess->putStone(S, 12);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(S, 12), MoveToNotEmptyPointException);
    gameProcess->putStone(D, 2);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(D, 2), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(E, 7), MoveToNotEmptyPointException);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(E, 8), MoveToNotEmptyPointException);
    
    delete gameProcess;
}

void GameProcessTest::throwingMoveRepeatException()
{
    //падает, т.к не реализовано съедение
    GameProcess* gameProcess = new GameProcess{ 7 };

    gameProcess->putStone(B, 4);
    gameProcess->putStone(E, 4);
    gameProcess->putStone(C, 3);
    gameProcess->putStone(D, 3);
    gameProcess->putStone(C, 5);
    gameProcess->putStone(D, 5);
    gameProcess->putStone(D, 4);
    gameProcess->putStone(C, 4);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(D, 4), MoveRepeatException);
    
    delete gameProcess;
}

void GameProcessTest::throwingMoveToDieException()
{
    //Не проходятся, т.к не реализовано съедение
    //и не реализовано определение хода под смерть
    GameProcess* gameProcess = new GameProcess{ 13 };

    gameProcess->putStone(B, 1);
    gameProcess->putStone(B, 2);
    gameProcess->putStone(A, 2);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(A, 1), MoveToDieException);

    gameProcess->putStone(A, 11);
    gameProcess->putStone(B, 13);
    gameProcess->putStone(B, 10);
    gameProcess->putStone(C, 13);
    gameProcess->putStone(C, 11);
    gameProcess->putStone(D, 13);
    gameProcess->putStone(B, 12);
    QVERIFY_EXCEPTION_THROWN(gameProcess->putStone(B, 11), MoveToDieException);
    
    delete gameProcess;
}

QTEST_APPLESS_MAIN(GameProcessTest)

#include "GameProcessTest.moc"