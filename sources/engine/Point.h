#ifndef GO_POINT_H
#define GO_POINT_H

#include "PointLocation.h"
#include "Stone.h"

namespace Go {

enum class PointStatus {
  EMPTY = 0,
  HAS_BLACK_STONE,
  HAS_WHITE_STONE
};

class Point {
 public:
  constexpr Point(PointLocation location = defaultLocation, PointStatus status) noexcept
      : location(location),
        status(status) { }

  constexpr PointLocation getLocation() const noexcept {
    return location;
  }

  constexpr PointStatus getStatus() const noexcept {
    return status;
  }

  constexpr void setStone(const Stone &stone);

 private:
  PointLocation location;
  PointStatus status;
  static constexpr PointLocation defaultLocation{VerticalCoordinate::A, 1};
};

}

#endif //GO_POINT_H
