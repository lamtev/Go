#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>
#include <utility>
#include "Point.h"

namespace Go {

using MatrixCoordinates = std::pair<int, int>;

template<class T>
using Matrix = std::vector<std::vector<T>>;

class Board {
 public:
  explicit Board(int dimension) noexcept;
  PointStatus getPointStatus(const PointLocation &pointLocation) const noexcept;
  void setStoneToPoint(const Stone &stone, const PointLocation &pointLocation);
  void removeStoneFromPoint(const PointLocation &pointLocation);

 private:
  const int dimension;
  Matrix<Point> board;

  Point &getPoint(const PointLocation &pointLocation) noexcept;
  const Point &getPoint(const PointLocation &pointLocation) const noexcept;
  MatrixCoordinates toMatrixCoordinates(const PointLocation &pointLocation) const noexcept;
};

}

#endif //GO_BOARD_H
