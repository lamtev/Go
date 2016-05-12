#include <QString>
#include <QtTest>

#include "../../GoEngine/Model/Stone.h"

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

StoneTest::StoneTest(){}

void StoneTest::getColor()
{
    Stone stone{ static_cast<int>(Status::BLACK), A, 5, 2 };

    QCOMPARE(stone.getColor(), static_cast<int>(Status::BLACK));
}

void StoneTest::getFirst()
{
    Stone stone{ static_cast<int>(Status::BLACK), A, 5, 2 };

    QVERIFY(stone.getFirst() == A);
}

void StoneTest::getSecond()
{
    Stone stone{ static_cast<int>(Status::BLACK), A, 5, 2 };

    QCOMPARE(stone.getSecond(), 5);
}

void StoneTest::getBreaths()
{
    Stone stone{ static_cast<int>(Status::BLACK), A, 5, 2 };

    QCOMPARE(stone.getBreaths(), 2);
}

QTEST_APPLESS_MAIN(StoneTest)

#include "StoneTest.moc"