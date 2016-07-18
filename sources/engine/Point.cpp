#include "Point.h"

namespace Go {

Point::Point(PointStatus status) noexcept
    : status{status} { }

PointStatus Point::getStatus() const noexcept {
  return status;
}

Stone Point::getStone() const {
  if (status == PointStatus::EMPTY) {
    throw StoneGettingException{};
  }
  return *stone;
}

void Point::setStone(const Stone &stone) {
  if (status != PointStatus::EMPTY) {
    throw StoneSettingException{};
  }
  this->stone = std::make_shared<Stone>(stone);
  status = static_cast<PointStatus>(stone.getColor());
}

void Point::removeStone() {
  if (status == PointStatus::EMPTY) {
    throw StoneRemovingException{};
  }
  stone.reset();
  status = PointStatus::EMPTY;
}

}