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
  EXPECT_THROW(point.getStone(), StoneGettingException);
}

TEST_F(TestPoint, setStone) {
  point.setStone(whiteStone);
  EXPECT_THROW(point.setStone(blackStone), StoneSettingException);
  EXPECT_EQ(whiteStone, point.getStone());
  EXPECT_EQ(StoneColor::WHITE, point.getStone().getColor());
  EXPECT_EQ(PointStatus::HAS_WHITE_STONE, point.getStatus());
}

TEST_F(TestPoint, removeStone) {
  point.setStone(whiteStone);
  point.removeStone();
  EXPECT_THROW(point.removeStone(), StoneRemovingException);
  EXPECT_EQ(PointStatus::EMPTY, point.getStatus());
}

TEST_F(TestPoint, setAndRemoveStone) {
  point.setStone(whiteStone);
  point.removeStone();
  point.setStone(blackStone);
  EXPECT_EQ(blackStone, point.getStone());
  EXPECT_EQ(StoneColor::BLACK, point.getStone().getColor());
  EXPECT_EQ(PointStatus::HAS_BLACK_STONE, point.getStatus());
}
