#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/Move.h"

class MoveTest : public QObject
{
    Q_OBJECT

public:
    MoveTest();


private Q_SLOTS:
    void putGet();
    void equallity();
    void inequallity();


};

MoveTest::MoveTest()
{
}

void MoveTest::putGet()
{
    std::vector<Move> moves(361);
    for( int i = 0; i < 361; ++i)
    {
        moves[i].putFirst(i%19);
        moves[i].putSecond((i+5)%19);

        QCOMPARE(moves[i].getFirst(), i%19);
        QCOMPARE(moves[i].getSecond(), (i+5)%19);
    }
}

void MoveTest::equallity()
{
    Move move1;
    Move move2;
    move1.putFirst(1);
    move2.putFirst(1);
    move1.putFirst(5);
    move2.putFirst(5);
    QVERIFY(move1 == move2);

    move1.putFirst(6);
    move2.putFirst(6);
    move1.putFirst(124);
    move2.putFirst(124);
    QVERIFY(move1 == move2);
}

void MoveTest::inequallity()
{
    Move move1;
    Move move2;
    move1.putFirst(1);
    move2.putFirst(2);
    move1.putFirst(5);
    move2.putFirst(3);
    QVERIFY(move1 != move2);

    move1.putFirst(45);
    move2.putFirst(7);
    move1.putFirst(123);
    move2.putFirst(9);
    QVERIFY(move1 != move2);
}


QTEST_APPLESS_MAIN(MoveTest)

#include "MoveTest.moc"

