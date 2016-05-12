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
    Point s1{ Status::WHITE };
    Point s2 = s1;
    QCOMPARE(s1.getStatus(), s2.getStatus());

    Point s3{ Status::EMPTY };
    Point s4{ s3 };
    QCOMPARE(s3.getStatus(), s4.getStatus());
}

void PointTest::assigmentInt()
{
    Point s1{ Status::BLACK };
    Point s2{ Status::BLACK };
    QCOMPARE(s1.getStatus(), s2.getStatus());

    s1 = s2 = Status::WHITE;
    QCOMPARE(s1.getStatus(), s2.getStatus());
}

void PointTest::createDeleteStone()
{
    Point* point = new Point;

    *point = Status::BLACK;
    point->createStone(static_cast<Color>(point->getStatus()), A, 5, 2);
    point->deleteStone();
    point->createStone(static_cast<Color>(point->getStatus()), M, 19, 3);

    delete point;
}

void PointTest::getStatus()
{
    Point s{ Status::BLACK };
    QCOMPARE(s.getStatus(), Status::BLACK);
}

void PointTest::getStone()
{
    Point* point = new Point{ Status::WHITE };

    point->createStone(static_cast<Color>(point->getStatus()), A, 5, 2);
    QCOMPARE(point->getStone().getColor(), Color::WHITE);
    QCOMPARE(point->getStone().getFirst(), static_cast<int>(A));
    QCOMPARE(point->getStone().getSecond(), 5);
    QCOMPARE(point->getStone().getBreaths(), 2);

    delete point;
}

void PointTest::isEmpty()
{
    Point point{ Status::BLACK };
    QVERIFY(!point.isEmpty());
    point = Status::EMPTY;
    QVERIFY(point.isEmpty());
    point = Status::WHITE;
    QVERIFY(!point.isEmpty());
    point = Status::EMPTY;
    QVERIFY(point.isEmpty());
}

void PointTest::isNotEmpty()
{
    Point point;
    QVERIFY(!point.isNotEmpty());
    point = Status::BLACK;
    QVERIFY(point.isNotEmpty());
    point = Status::WHITE;
    QVERIFY(point.isNotEmpty());
}

QTEST_APPLESS_MAIN(PointTest)

#include "PointTest.moc"