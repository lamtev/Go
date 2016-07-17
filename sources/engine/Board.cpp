#include "Board.h"

namespace Go {

Board::Board(int dimension) noexcept
    : dimension{dimension} {
  board.resize(dimension);
  for (auto &row : board) {
    row.resize(dimension);
  }
}

//TODO eliminate duplication
PointStatus Board::getPointStatus(const PointLocation &pointLocation) const noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  Point point{board[i][j]};
  return point.getStatus();
}

//TODO exception
void Board::setStoneToPoint(const Stone &stone, const PointLocation &pointLocation) noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  Point &point{board[i][j]};
  point.addStone(stone);
//  std::shared_ptr<Point> pPoint{getPoint(pointLocation)};
//  pPoint->addStone(stone);
}

//TODO exception
void Board::removeStoneFromPoint(const PointLocation &pointLocation) noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  Point &point{board[i][j]};
  point.deleteStone();
//  std::shared_ptr<Point> pPoint{getPoint(pointLocation)};
//  pPoint->deleteStone();
}

std::shared_ptr<Point> Board::getPoint(const PointLocation &pointLocation) const noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  return std::make_shared<Point>(board[i][j]);
}

MatrixCoordinates Board::toMatrixCoordinates(const PointLocation &pointLocation) const noexcept {
  return MatrixCoordinates {
      pointLocation.getVerticalCoordinate() - 1,
      pointLocation.getHorizontalCoordinate() - 1
  };
}

}
