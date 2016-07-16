#ifndef GO_POINT_H
#define GO_POINT_H

#include <memory>

#include "PointLocation.h"
#include "Stone.h"

namespace Go {

enum class PointStatus: short {
  EMPTY = 0,
  HAS_BLACK_STONE,
  HAS_WHITE_STONE
};

PointLocation defaultLocation{VerticalCoordinate::A, 1};

class Point {
 public:
  Point(PointLocation location = defaultLocation, PointStatus status = PointStatus::EMPTY) noexcept
      : location(location),
        status(status),
        stone(nullptr) { }
  ~Point() {}

  PointLocation getLocation() const noexcept {
    return location;
  }

  PointStatus getStatus() const noexcept {
    return status;
  }

  Stone getStone() const noexcept {
    return *stone;
  }

  void addStone(const Stone &stone) {
    this->stone = std::make_unique<Stone>(stone);
    status = static_cast<PointStatus>(stone.getColor());
  }

  void deleteStone() {
    stone.reset();
    status = PointStatus::EMPTY;
  }

 private:
  PointLocation location;
  PointStatus status;
  std::unique_ptr<Stone> stone;
};

}

#endif //GO_POINT_H
