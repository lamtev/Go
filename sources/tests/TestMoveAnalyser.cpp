#include "gtest/gtest.h"
#include "../engine/MoveAnalyser.h"

using namespace Go;

class TestMoveAnalyser: public ::testing::Test {
 public:
  virtual void SetUp() override { }
  virtual void TearDown() override { }
  Board board{7};
  Moves moves;
  MoveAnalyser moveAnalyser{board, moves};
  Stone blackStone{StoneColor::BLACK};
  Stone whiteStone{StoneColor::WHITE};
  PointLocation pointLocation1{VerticalCoordinate::D, 7};
  PointLocation pointLocation2{VerticalCoordinate::E, 3};
};

TEST_F(TestMoveAnalyser, checkForWithinBoard) {

  PointLocation wrongPointLocation1{VerticalCoordinate::A, 0};
  Move wrongMove1{MoveType::STONE_SETTING, PlayerColor::BLACK, wrongPointLocation1};
  EXPECT_THROW(moveAnalyser.checkMove(wrongMove1), MoveOutsideTheBoardException);

  PointLocation wrongPointLocation2{VerticalCoordinate::B, 8};
  Move wrongMove2{MoveType::STONE_SETTING, PlayerColor::WHITE, wrongPointLocation2};
  EXPECT_THROW(moveAnalyser.checkMove(wrongMove2), MoveOutsideTheBoardException);
}

TEST_F(TestMoveAnalyser, checkForEmptyDestinationPoint) {
  Move wrongMove1{MoveType::STONE_SETTING, PlayerColor::BLACK, pointLocation1};
  board.setStoneToPoint(blackStone, pointLocation1);
  EXPECT_THROW(moveAnalyser.checkMove(wrongMove1), MoveToNotEmptyPointException);

  Move wrongMove2{MoveType::STONE_SETTING, PlayerColor::WHITE, pointLocation2};
  board.setStoneToPoint(whiteStone, pointLocation2);
  EXPECT_THROW(moveAnalyser.checkMove(wrongMove2), MoveToNotEmptyPointException);
}