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
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  Point point{board[i][j]};
  return point.getStatus();
}

//TODO exception
void Board::setStoneToPoint(const Stone &stone, const PointLocation &pointLocation) noexcept {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  Point point{board[i][j]};
  point.addStone(stone);
}

void Board::removeStoneFromPoint(const PointLocation &pointLocation) {
  int i = toMatrixCoordinates(pointLocation).first;
  int j = toMatrixCoordinates(pointLocation).second;
  Point point{board[i][j]};
  point.deleteStone();
}

MatrixCoordinates Board::toMatrixCoordinates(const PointLocation &pointLocation) const noexcept {
  return MatrixCoordinates {
      pointLocation.getVerticalCoordinate() - 1,
      pointLocation.getHorizontalCoordinate() - 1
  };
}

}
