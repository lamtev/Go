#include <QString>
#include <QtTest>

#include "../../GoEngine/Point.h"

class PointTest : public QObject
{
Q_OBJECT

public:
    PointTest();


private Q_SLOTS:
    void assigmentObject();
    void assigmentInt();
    void createDeleteStone();
    void getStatus();
    void getStone();
    void isEmpty();
    void isNotEmpty();

};

PointTest::PointTest(){}

void PointTest::assigmentObject()
{
    Point s1{ WHITE };
    Point s2 = s1;
    QCOMPARE(s1.getStatus(), s2.getStatus());

    Point s3{ EMPTY };
    Point s4{ s3 };
    QCOMPARE(s3.getStatus(), s4.getStatus());
}

void PointTest::assigmentInt()
{
    Point s1{ BLACK };
    Point s2{ BLACK };
    QCOMPARE(s1.getStatus(), s2.getStatus());

    s1 = s2 = WHITE;
    QCOMPARE(s1.getStatus(), s2.getStatus());
}

void PointTest::createDeleteStone()
{
    Point* point = new Point;

    *point = BLACK;
    point->createStone(point->getStatus(), A, 5, 2);
    point->deleteStone();
    point->createStone(point->getStatus(), M, 19, 3);
    delete point;
}

void PointTest::getStatus()
{
    Point s{ BLACK };
    QVERIFY(s.getStatus() == BLACK);
}

void PointTest::getStone()
{
    Point* point = new Point{ WHITE };

    point->createStone(point->getStatus(), A, 5, 2);
    QVERIFY(point->getStone().getColor() == WHITE);
    QVERIFY(point->getStone().getFirst() == A);
    QCOMPARE(point->getStone().getSecond(), 5);
    QCOMPARE(point->getStone().getBreaths(), 2);

    delete point;
}

void PointTest::isEmpty()
{
    Point point{ BLACK };
    QVERIFY(!point.isEmpty());
    point = EMPTY;
    QVERIFY(point.isEmpty());
    point = WHITE;
    QVERIFY(!point.isEmpty());
    point = EMPTY;
    QVERIFY(point.isEmpty());
}

void PointTest::isNotEmpty()
{
    Point point;
    QVERIFY(!point.isNotEmpty());
    point = BLACK;
    QVERIFY(point.isNotEmpty());
    point = WHITE;
    QVERIFY(point.isNotEmpty());
}

QTEST_APPLESS_MAIN(PointTest)

#include "PointTest.moc"