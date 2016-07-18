#include "gtest/gtest.h"
#include "../engine/Moves.h"

using namespace Go;

class TestMove: public ::testing::Test {
 protected:
  virtual void SetUp() override { }
  virtual void TearDown() override { }
  Moves moves;
  MoveType type1{MoveType::StoneSetting};
  PlayerColor playerColor1{PlayerColor::WHITE};
  PointLocation pointLocation1{VerticalCoordinate::D, 17};
  Move move1{type1, playerColor1, pointLocation1};

  MoveType type2{MoveType::StoneSetting};
  PlayerColor playerColor2{PlayerColor::BLACK};
  PointLocation pointLocation2{VerticalCoordinate::G, 3};
  Move move2{type2, playerColor2, pointLocation2};
};

TEST_F(TestMove, pushMoveToBack) {
  moves.pushMoveToBack(move1);
  moves.pushMoveToBack(move2);
  EXPECT_EQ(move1, moves.getLastMove());
}

TEST_F(TestMove, undo) {
  moves.pushMoveToBack(move1);
  moves.pushMoveToBack(move2);
  moves.undo();
  EXPECT_EQ(move1, moves.getLastMove());
}

TEST_F(TestMove, redo) {
  moves.pushMoveToBack(move1);
  moves.pushMoveToBack(move2);
  moves.undo();
  moves.redo();
  EXPECT_EQ(move2, moves.getLastMove());
}
