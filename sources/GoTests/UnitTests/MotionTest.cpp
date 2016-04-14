#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/Motion.h"

class MotionTest : public QObject
{
Q_OBJECT

public:
    MotionTest();


private Q_SLOTS:

};

MotionTest::MotionTest()
{
}


QTEST_APPLESS_MAIN(MotionTest)

#include "MotionTest.moc"