#include "gtest/gtest.h"
#include "../engine/Board.h"

using namespace Go;

class TestBoard: public ::testing::Test {
 protected:
  virtual void SetUp() override { }
  virtual void TearDown() override { }
  int dimension = 19;
  Board board{dimension};
  Stone stone{StoneColor::WHITE};
  PointLocation pointLocation{VerticalCoordinate::A, 1};
};

TEST_F(TestBoard, getPoint) {
  for (int i = 1; i <= dimension; ++i) {
    for (int j = 1; j <= dimension; ++j) {
      VerticalCoordinate verticalCoordinate{static_cast<VerticalCoordinate>(i)};
      HorizontalCoordinate horizontalCoordinate{static_cast<HorizontalCoordinate>(j)};
      PointLocation location{verticalCoordinate, horizontalCoordinate};
      EXPECT_EQ(PointStatus::EMPTY, board.getPointStatus(location));
    }
  }
}

TEST_F(TestBoard, setStoneToPoint) {
  board.setStoneToPoint(stone, pointLocation);
  EXPECT_EQ(PointStatus::HAS_WHITE_STONE, board.getPointStatus(pointLocation));
}

TEST_F(TestBoard, removeStoneFromPoint) {
  board.setStoneToPoint(stone, pointLocation);
  board.removeStoneFromPoint(pointLocation);
  EXPECT_EQ(PointStatus::EMPTY, board.getPointStatus(pointLocation));
}