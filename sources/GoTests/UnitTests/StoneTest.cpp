#include <QString>
#include <QtTest>

#include "../../GoEngine/Stone.h"
#include "../../GoEngine/enums.h"

class StoneTest : public QObject
{
Q_OBJECT

public:
    StoneTest();


private Q_SLOTS:
    void getColor();
    void assigmentObject();
    void assigmentInt();

};

StoneTest::StoneTest()
{
}

void StoneTest::getColor()
{
    Stone s(BLACK);
    QVERIFY(s.getColor() == BLACK);
}

void StoneTest::assigmentObject()
{
    Stone s1(WHITE);
    Stone s2 = s1;
    QCOMPARE(s1.getColor(), s2.getColor());

    Stone s3(EMPTY);
    Stone s4 = s3;
    QCOMPARE(s3.getColor(), s4.getColor());
}

void StoneTest::assigmentInt()
{
    Stone s1(BLACK);
    Stone s2 = BLACK;
    QCOMPARE(s1.getColor(), s2.getColor());

    s1 = s2 = WHITE;
    QCOMPARE(s1.getColor(), s2.getColor());
}

QTEST_APPLESS_MAIN(StoneTest)

#include "StoneTest.moc"