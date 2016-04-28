#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Stone.h"

class StoneTest : public QObject
{
    Q_OBJECT

public:
    StoneTest();


private Q_SLOTS:
    void getColor();
    void getFirst();
    void getSecond();
    void getBreaths();

};

StoneTest::StoneTest()
{
}

void StoneTest::getColor()
{
    Stone stone{ BLACK, A, 5, 2 };

    QVERIFY(stone.getColor() == BLACK);
}

void StoneTest::getFirst()
{
    Stone stone{ BLACK, A, 5, 2 };

    QVERIFY(stone.getFirst() == A);
}

void StoneTest::getSecond()
{
    Stone stone{ BLACK, A, 5, 2 };

    QCOMPARE(stone.getSecond(), 5);
}

void StoneTest::getBreaths()
{
    Stone stone{ BLACK, A, 5, 2 };

    QCOMPARE(stone.getBreaths(), 2);
}

QTEST_APPLESS_MAIN(StoneTest)

#include "StoneTest.moc"