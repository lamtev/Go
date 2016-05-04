#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Model/Board.h"

class BoardTest : public QObject
{
Q_OBJECT

public:
    BoardTest();


private Q_SLOTS:
    void initialization();
    void getDiagonal();
    void indexation();
    void assigment();
    void get();

};

BoardTest::BoardTest(){}

void BoardTest::initialization()
{
    Board b{ 13 };
    for( int i = 1; i <= 13; ++i )
    {
        for (int j = 1; j <= 13; ++j)
        {
            QVERIFY(b(i, j).isEmpty());
        }
    }
}

void BoardTest::getDiagonal()
{
    Board b{ 19 };
    QCOMPARE(b.getDiagonal(), 19);
    Board b1{ 7 };
    QCOMPARE(b1.getDiagonal(), 7);
}

void BoardTest::indexation()
{
    Board b{ 19 };
    b(1, 1) = static_cast<int>(Status::BLACK);
    b(19, 19) = static_cast<int>(Status::WHITE);
    QCOMPARE(b(1, 1).getStatus(), static_cast<int>(Status::BLACK));
    QCOMPARE(b(19, 19).getStatus(), static_cast<int>(Status::WHITE));
}

void BoardTest::assigment()
{
    Board b1{ 7 };
    b1(1, 1) = static_cast<int>(Status::BLACK);
    b1(7, 7) = static_cast<int>(Status::WHITE);
    Board b2 = b1;
    QVERIFY(b1(1, 1).getStatus() == b2(1, 1).getStatus());
    QVERIFY(b1(7, 7).getStatus() == b2(7, 7).getStatus());
}

void BoardTest::get()
{
    Board board{ 7 };
    int counter{ 0 };
    for( int i = 1; i <= 7; ++i )
    {
        for( int j = 1; j <= 7; ++j )
        {
            board(i, j) = counter % 3;
            ++counter;
        }
    }
    board(1, 4) = static_cast<int>(Status::BLACK);
    board(4, 1) = static_cast<int>(Status::WHITE);

    const Point EMPTY{ static_cast<int>(Status::EMPTY) };
    const Point BLACK{ static_cast<int>(Status::BLACK) };
    const Point WHITE{ static_cast<int>(Status::WHITE) };
    std::vector<Point> vector{
            EMPTY, BLACK, WHITE, WHITE, BLACK, WHITE, EMPTY,
            BLACK, WHITE, EMPTY, BLACK, WHITE, EMPTY, BLACK,
            WHITE, EMPTY, BLACK, WHITE, EMPTY, BLACK, WHITE,
            BLACK, BLACK, WHITE, EMPTY, BLACK, WHITE, EMPTY,
            BLACK, WHITE, EMPTY, BLACK, WHITE, EMPTY, BLACK,
            WHITE, EMPTY, BLACK, WHITE, EMPTY, BLACK, WHITE,
            EMPTY, BLACK, WHITE, EMPTY, BLACK, WHITE, EMPTY
    };

    for( int i = 0; i < 49; ++i )
    {
        QCOMPARE(board.get()[i].getStatus(), vector[i].getStatus());
    }
}

QTEST_APPLESS_MAIN(BoardTest)

#include "BoardTest.moc"