#include "gtest/gtest.h"
#include "../engine/Point.h"

using namespace Go;

class TestPoint: public ::testing::Test {
 protected:
  virtual void SetUp() override {}
  virtual void TearDown() override {}
  Point point;
  Stone stone {StoneColor::BLACK};
  Stone stone1 {StoneColor::WHITE};
};

TEST_F(TestPoint, addStone) {
  point.addStone(stone);
  EXPECT_EQ(StoneColor::BLACK, point.getStone().getColor());
  EXPECT_EQ(stone, point.getStone());

  point.addStone(stone1);
  EXPECT_EQ(StoneColor::WHITE, point.getStone().getColor());
  EXPECT_EQ(stone1, point.getStone());
}

TEST_F(TestPoint, deleteStone) {
  point.addStone(stone);
  point.deleteStone();
  EXPECT_EQ(PointStatus::EMPTY, point.getStatus());
}


