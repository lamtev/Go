#include "gtest/gtest.h"
#include "../engine/Point.h"

using namespace Go;

class TestPoint: public ::testing::Test {
 protected:
  virtual void SetUp() override { }
  virtual void TearDown() override { }
  Point point;
  Stone whiteStone {StoneColor::WHITE};
  Stone blackStone {StoneColor::BLACK};
};

TEST_F(TestPoint, getStone) {
  EXPECT_THROW(point.getStone(), StoneNotFoundException);
}

TEST_F(TestPoint, addStone) {

  point.addStone(whiteStone);
  EXPECT_EQ(whiteStone, point.getStone());
  EXPECT_EQ(StoneColor::WHITE, point.getStone().getColor());
  EXPECT_EQ(PointStatus::HAS_WHITE_STONE, point.getStatus());
}

TEST_F(TestPoint, deleteStone) {
  point.addStone(whiteStone);
  point.deleteStone();
  EXPECT_EQ(PointStatus::EMPTY, point.getStatus());
  EXPECT_THROW(point.getStone(), StoneNotFoundException);
}

TEST_F(TestPoint, addAndDeleteStone) {
  point.addStone(whiteStone);
  point.deleteStone();
  point.addStone(blackStone);
  EXPECT_EQ(blackStone, point.getStone());
  EXPECT_EQ(StoneColor::BLACK, point.getStone().getColor());
  EXPECT_EQ(PointStatus::HAS_BLACK_STONE, point.getStatus());
}


