#include "Board.h"

namespace Go {

Board::Board(int dimension) noexcept
    : dimension{dimension} {
  board.resize(dimension);
  for (auto &row : board) {
    row.resize(dimension);
  }
}

PointStatus Board::getPointStatus(const PointLocation &pointLocation) const noexcept {
  Point point{getPoint(pointLocation)};
  return point.getStatus();
}

//TODO exception
void Board::setStoneToPoint(const Stone &stone, const PointLocation &pointLocation) noexcept {
  Point &point{getPoint(pointLocation)};
  point.addStone(stone);
}

//TODO exception
void Board::removeStoneFromPoint(const PointLocation &pointLocation) noexcept {
  Point &point{getPoint(pointLocation)};
  point.deleteStone();
}

//TODO eliminate duplication
Point &Board::getPoint(const PointLocation &pointLocation) noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  return board[i][j];
}

const Point Board::getPoint(const PointLocation &pointLocation) const noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  return board[i][j];
}

MatrixCoordinates Board::toMatrixCoordinates(const PointLocation &pointLocation) const noexcept {
  return MatrixCoordinates {
      pointLocation.getVerticalCoordinate() - 1,
      pointLocation.getHorizontalCoordinate() - 1
  };
}

}
