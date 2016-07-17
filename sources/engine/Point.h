#ifndef GO_POINT_H
#define GO_POINT_H

#include <memory>
#include "PointLocation.h"
#include "Stone.h"
#include "StoneNotFoundException.h"

namespace Go {

enum class PointStatus {
  EMPTY = 0,
  HAS_BLACK_STONE,
  HAS_WHITE_STONE
};

class Point {
 public:
  Point(PointStatus status = PointStatus::EMPTY) noexcept;
  PointStatus getStatus() const noexcept;
  Stone getStone() const;
  void addStone(const Stone &stone) noexcept;
  void deleteStone() noexcept;

 private:
  PointStatus status;
  std::shared_ptr<Stone> stone;
};

}

#endif //GO_POINT_H
