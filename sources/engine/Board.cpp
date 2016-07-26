#include "Board.h"

namespace Go {

Board::Board(int dimension) noexcept
    : dimension{dimension} {
  board.resize(dimension);
  for (auto &row : board) {
    row.resize(dimension);
  }
}

PointStatus Board::getPointStatus(const PointLocation &pointLocation) noexcept {
  Point &point{getPoint(pointLocation)};
  return point.getStatus();
}

void Board::setStoneToPoint(const Stone &stone, const PointLocation &pointLocation) {
  Point &point{getPoint(pointLocation)};
  point.setStone(stone);
}

void Board::removeStoneFromPoint(const PointLocation &pointLocation) {
  Point &point{getPoint(pointLocation)};
  point.removeStone();
}

int Board::getDimension() const noexcept {
  return dimension;
}

Point &Board::getPoint(const PointLocation &pointLocation) noexcept {
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
