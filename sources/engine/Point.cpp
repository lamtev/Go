#include "Point.h"

namespace Go {

Point::Point(PointStatus status) noexcept
    : status{status} { }

PointStatus Point::getStatus() const noexcept {
  return status;
}

Stone Point::getStone() const {
  if (status == PointStatus::EMPTY) {
    throw StoneNotFoundException{};
  }
  return *stone;
}

void Point::addStone(const Stone &stone) noexcept {
  this->stone = std::make_shared<Stone>(stone);
  status = static_cast<PointStatus>(stone.getColor());
}

void Point::deleteStone() noexcept {
  stone.reset();
  status = PointStatus::EMPTY;
}

}