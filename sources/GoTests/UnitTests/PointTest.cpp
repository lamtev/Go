#include <QString>
#include <QtTest>

#include "../../GoEngine/Model/Point.h"

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
    Point s1{ static_cast<int>(Status::WHITE) };
    Point s2 = s1;
    QCOMPARE(s1.getStatus(), s2.getStatus());

    Point s3{ static_cast<int>(Status::EMPTY) };
    Point s4{ s3 };
    QCOMPARE(s3.getStatus(), s4.getStatus());
}

void PointTest::assigmentInt()
{
    Point s1{ static_cast<int>(Status::BLACK) };
    Point s2{ static_cast<int>(Status::BLACK) };
    QCOMPARE(s1.getStatus(), s2.getStatus());

    s1 = s2 =  static_cast<int>(Status::WHITE);
    QCOMPARE(s1.getStatus(), s2.getStatus());
}

void PointTest::createDeleteStone()
{
    Point* point = new Point;

    *point = static_cast<int>(Status::BLACK);
    point->createStone(point->getStatus(), A, 5, 2);
    point->deleteStone();
    point->createStone(point->getStatus(), M, 19, 3);
    delete point;
}

void PointTest::getStatus()
{
    Point s{ static_cast<int>(Status::BLACK) };
    QCOMPARE(s.getStatus(), static_cast<int>(Status::BLACK));
}

void PointTest::getStone()
{
    Point* point = new Point{ static_cast<int>(Status::WHITE) };

    point->createStone(point->getStatus(), A, 5, 2);
    QCOMPARE(point->getStone().getColor(), static_cast<int>(Status::WHITE));
    QCOMPARE(point->getStone().getFirst(), static_cast<int>(A));
    QCOMPARE(point->getStone().getSecond(), 5);
    QCOMPARE(point->getStone().getBreaths(), 2);

    delete point;
}

void PointTest::isEmpty()
{
    Point point{ static_cast<int>(Status::BLACK) };
    QVERIFY(!point.isEmpty());
    point = static_cast<int>(Status::EMPTY);
    QVERIFY(point.isEmpty());
    point = static_cast<int>(Status::WHITE);
    QVERIFY(!point.isEmpty());
    point = static_cast<int>(Status::EMPTY);
    QVERIFY(point.isEmpty());
}

void PointTest::isNotEmpty()
{
    Point point;
    QVERIFY(!point.isNotEmpty());
    point = static_cast<int>(Status::BLACK);
    QVERIFY(point.isNotEmpty());
    point = static_cast<int>(Status::WHITE);
    QVERIFY(point.isNotEmpty());
}

QTEST_APPLESS_MAIN(PointTest)

#include "PointTest.moc"