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
  void setStoneToPoint(const Stone &stone, const PointLocation &pointLocation) noexcept;
  void removeStoneFromPoint(const PointLocation &pointLocation) noexcept;

 private:
  const int dimension;
  Matrix<Point> board;

  std::shared_ptr<Point> getPoint(const PointLocation &pointLocation) const noexcept;
  MatrixCoordinates toMatrixCoordinates(const PointLocation &pointLocation) const noexcept;
};

}

#endif //GO_BOARD_H
