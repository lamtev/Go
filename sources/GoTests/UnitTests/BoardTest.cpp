#include <QString>
#include <QtTest>

#include <iostream>

#include "../../GoEngine/Model/Board.h"

class BoardTest: public QObject {
 Q_OBJECT

 public:
  BoardTest();


 private Q_SLOTS:
  void initialization();
  void indexation();
  void assigment();

};

BoardTest::BoardTest() { }

void BoardTest::initialization() {
  Board b{13};
  for (int i = 1; i <= 13; ++i) {
    for (int j = 1; j <= 13; ++j) {
      QVERIFY(b(i, j).isEmpty());
    }
  }
}

void BoardTest::indexation() {
  Board b{19};
  b(1, 1) = Point{Status::BLACK};
  b(19, 19) = Point{Status::WHITE};
  QCOMPARE(b(1, 1).getStatus(), Status::BLACK);
  QCOMPARE(b(19, 19).getStatus(), Status::WHITE);
}

void BoardTest::assigment() {
  Board b1{7};
  b1(1, 1) = Point{Status::BLACK};
  b1(7, 7) = Point{Status::WHITE};
  Board b2 = b1;
  QCOMPARE(b1(1, 1).getStatus(), b2(1, 1).getStatus());
  QCOMPARE(b1(7, 7).getStatus(), b2(7, 7).getStatus());
}


QTEST_APPLESS_MAIN(BoardTest)

#include "BoardTest.moc"