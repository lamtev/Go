#include <QString>
#include <QtTest>

#include "../../GoEngine/Point.h"
#include "../../GoEngine/enums.h"

class PointTest : public QObject
{
Q_OBJECT

public:
    PointTest();


private Q_SLOTS:
    void getStatus();
    void assigmentObject();
    void assigmentInt();

};

PointTest::PointTest()
{

}

void PointTest::getStatus()
{
    Point s{BLACK};
    QVERIFY(s.getStatus() == BLACK);
}

void PointTest::assigmentObject()
{
    Point s1{WHITE};
    Point s2 = s1;
    QCOMPARE(s1.getStatus(), s2.getStatus());

    Point s3{EMPTY};
    Point s4{s3};
    QCOMPARE(s3.getStatus(), s4.getStatus());
}

void PointTest::assigmentInt()
{
    Point s1{BLACK};
    Point s2{BLACK};
    QCOMPARE(s1.getStatus(), s2.getStatus());

    s1 = s2 = WHITE;
    QCOMPARE(s1.getStatus(), s2.getStatus());
}

QTEST_APPLESS_MAIN(PointTest)

#include "PointTest.moc"