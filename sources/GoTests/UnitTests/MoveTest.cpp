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
    void assigment();
    void equallity();
    void inequallity();


};

MoveTest::MoveTest()
{
}

void MoveTest::assigment()
{
    Move move{1, 2};

    QCOMPARE(move.getFirst(), 1);
    QCOMPARE(move.getSecond(), 2);

    move = Move{5, 0};
    QCOMPARE(move.getFirst(), 5);
    QCOMPARE(move.getSecond(), 0);
}

void MoveTest::equallity()
{
    Move move1{1, 5};
    Move move2{1, 5};
    QVERIFY(move1 == move2);

    move1 = Move{7, 2};
    move2 = Move{7, 2};
    QVERIFY(move1 == move2);
}

void MoveTest::inequallity()
{
    Move move1{7, 5};
    Move move2{7, 2};
    QVERIFY(move1 != move2);

    move1 = Move{128, 256};
    move2 = Move{13, 256};
    QVERIFY(move1 != move2);

    move1 = Move{128, 0};
    move2 = Move{13, 17};
    QVERIFY(move1 != move2);
}

QTEST_APPLESS_MAIN(MoveTest)

#include "MoveTest.moc"

