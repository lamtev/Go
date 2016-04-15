#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/Moves.h"

class MovesTest : public QObject
{
    Q_OBJECT

public:
    MovesTest();


private Q_SLOTS:
    void equallity();
    void inequallity();


};

MovesTest::MovesTest()
{
}

void MovesTest::equallity()
{
    Moves move1;
    Moves move2;
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

void MovesTest::inequallity()
{
    Moves move1;
    Moves move2;
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


QTEST_APPLESS_MAIN(MovesTest)

#include "MovesTest.moc"
