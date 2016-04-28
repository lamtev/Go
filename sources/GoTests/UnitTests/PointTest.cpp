#include <QString>
#include <QtTest>

#include "../../GoEngine/Point.h"

class PointTest : public QObject
{
Q_OBJECT

public:
    PointTest();


private Q_SLOTS:
    void getStatus();
    void assigmentObject();
    void assigmentInt();
    void equallity();
    void inequallity();
    void createDeleteStone();
    void getStone();

};

PointTest::PointTest()
{

}

void PointTest::getStatus()
{
    Point s{ BLACK };
    QVERIFY(s.getStatus() == BLACK);
}

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

void PointTest::equallity()
{
    QVERIFY(Point{ BLACK } == Point{ BLACK });
    QVERIFY(Point{ EMPTY} == Point{ EMPTY });
    QVERIFY(Point{ WHITE } == Point{ WHITE });
}

void PointTest::inequallity()
{
    QVERIFY(Point{ EMPTY } != Point{ BLACK });
    QVERIFY(Point{ BLACK } != Point{ WHITE });
    QVERIFY(Point{ WHITE } != Point{ EMPTY });
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

QTEST_APPLESS_MAIN(PointTest)

#include "PointTest.moc"