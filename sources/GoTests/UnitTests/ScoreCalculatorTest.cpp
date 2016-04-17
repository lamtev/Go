#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Rules/ScoreCalculator.h"

class ScoreCalculatorTest : public QObject
{
    Q_OBJECT

public:
    ScoreCalculatorTest();


private Q_SLOTS:

};

ScoreCalculatorTest::ScoreCalculatorTest()
{
}


QTEST_APPLESS_MAIN(ScoreCalculatorTest)

#include "ScoreCalculatorTest.moc"