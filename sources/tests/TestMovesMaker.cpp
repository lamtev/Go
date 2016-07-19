#include "gtest/gtest.h"
#include "../engine/MovesMaker.h"

using namespace Go;

class TestMovesMaker: public ::testing::Test {
 protected:
  virtual void SetUp() override { };
  virtual void TearDown() override { };
  MovesMaker movesMaker{13};
  PointLocation pointLocation1{VerticalCoordinate::F, 13};
  Move move1{MoveType::StoneSetting, PlayerColor::BLACK, pointLocation1};

  PointLocation pointLocation2{VerticalCoordinate::B, 9};
  Move move2{MoveType::StoneSetting, PlayerColor::WHITE, pointLocation2};

  Move move3{MoveType::CHECK, PlayerColor::BLACK};

  Move move4{MoveType::CHECK, PlayerColor::WHITE};

  Move move5{MoveType::RESIGN, PlayerColor::WHITE};
};

TEST_F(TestMovesMaker, setStone1) {
  EXPECT_EQ(WhoseMove::BLACKS, movesMaker.getWhoseMove());
  movesMaker.makeAMove(move1);
  EXPECT_EQ(move1, movesMaker.getMoves().getLastMove());
  movesMaker.makeAMove(move2);
  EXPECT_EQ(move2, movesMaker.getMoves().getLastMove());
  movesMaker.makeAMove(move3);
  EXPECT_EQ(move3, movesMaker.getMoves().getLastMove());
  movesMaker.makeAMove(move4);
  EXPECT_EQ(move4, movesMaker.getMoves().getLastMove());
  EXPECT_EQ(movesMaker.getWhoseMove(), WhoseMove::GAME_IS_OVER);
}

TEST_F(TestMovesMaker, setStone2) {
  movesMaker.makeAMove(move5);
  EXPECT_EQ(move5, movesMaker.getMoves().getLastMove());
  EXPECT_EQ(WhoseMove::GAME_IS_OVER, movesMaker.getWhoseMove());
}
