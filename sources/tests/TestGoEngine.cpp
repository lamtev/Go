#include "gtest/gtest.h"
#include "../engine/GoEngine.h"

using namespace Go;
//TODO refactor
class TestGoEngine: public ::testing::Test {
 protected:
  virtual void SetUp() override { };
  virtual void TearDown() override { };
  GoEngine go{13};

  PointLocation pointLocation1{VerticalCoordinate::F, 13};
  Move move1{MoveType::STONE_SETTING, PlayerColor::BLACK, pointLocation1};

  PointLocation pointLocation2{VerticalCoordinate::B, 9};
  Move move2{MoveType::STONE_SETTING, PlayerColor::WHITE, pointLocation2};

  Move move3{MoveType::CHECK, PlayerColor::BLACK};

  Move move4{MoveType::CHECK, PlayerColor::WHITE};

  Move move5{MoveType::RESIGN, PlayerColor::WHITE};
};

TEST_F(TestGoEngine, makeAMove1) {
  EXPECT_EQ(WhoseMove::BLACKS, go.getWhoseMove());
  go.makeAMove(move1);
  EXPECT_EQ(move1, go.getMoves().getLastMove());
  go.makeAMove(move2);
  EXPECT_EQ(move2, go.getMoves().getLastMove());
  go.makeAMove(move3);
  EXPECT_EQ(move3, go.getMoves().getLastMove());
  go.makeAMove(move4);
  EXPECT_EQ(move4, go.getMoves().getLastMove());
  EXPECT_EQ(go.getWhoseMove(), WhoseMove::GAME_IS_OVER);
}

TEST_F(TestGoEngine, makeAMove2) {
  go.makeAMove(move5);
  EXPECT_EQ(move5, go.getMoves().getLastMove());
  EXPECT_EQ(WhoseMove::GAME_IS_OVER, go.getWhoseMove());
  EXPECT_THROW(go.makeAMove(move1), GameIsOverException);
}

TEST_F(TestGoEngine, makeAMoveExceptions) {
  PointLocation pointLocationOutside{VerticalCoordinate::F, 14};
  Move moveOutside1{MoveType::STONE_SETTING, PlayerColor::BLACK, pointLocationOutside};
  EXPECT_THROW(go.makeAMove(moveOutside1), MoveOutsideTheBoardException);

  PointLocation pointLocation{VerticalCoordinate::A, 12};
  Move move{MoveType::STONE_SETTING, PlayerColor::BLACK, pointLocation};
  go.makeAMove(move);
  Move moveToNotEmptyPoint{MoveType::STONE_SETTING, PlayerColor::WHITE, pointLocation};
  //go.makeAMove(moveToNotEmptyPoint);
  EXPECT_THROW(go.makeAMove(moveToNotEmptyPoint), MoveToNotEmptyPointException);
}