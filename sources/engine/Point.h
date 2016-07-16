#ifndef GO_POINT_H
#define GO_POINT_H

#include <memory>

#include "PointLocation.h"
#include "Stone.h"

namespace Go {

enum class PointStatus {
  EMPTY = 0,
  HAS_BLACK_STONE,
  HAS_WHITE_STONE
};

constexpr PointLocation defaultLocation{VerticalCoordinate::A, 1};

class Point {
 public:
  Point(PointLocation location = defaultLocation, PointStatus status = PointStatus::EMPTY) noexcept;
  ~Point() noexcept;
  PointLocation getLocation() const noexcept;
  PointStatus getStatus() const noexcept;
  Stone getStone() const noexcept;
  void addStone(const Stone &stone) noexcept;
  void deleteStone() noexcept;

 private:
  PointLocation location;
  PointStatus status;
  std::unique_ptr<Stone> stone;
};

}

#endif //GO_POINT_H
