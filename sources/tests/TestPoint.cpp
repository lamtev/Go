#include "gtest/gtest.h"
#include "../engine/Point.h"

using namespace Go;

class TestPoint: public ::testing::Test {
 protected:
  virtual void SetUp() override { }
  virtual void TearDown() override { }
  Point point;
  Stone stone {StoneColor::WHITE};
};

TEST_F(TestPoint, addStone) {

  point.addStone(stone);
  EXPECT_EQ(StoneColor::WHITE, point.getStone().getColor());
  EXPECT_EQ(stone, point.getStone());
}

TEST_F(TestPoint, deleteStone) {
  Point point;
  Stone stone {StoneColor::BLACK};
  point.addStone(stone);
  point.deleteStone();
  EXPECT_EQ(PointStatus::EMPTY, point.getStatus());
}


