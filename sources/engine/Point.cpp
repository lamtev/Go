#include "Point.h"

namespace Go {

Point::Point() noexcept
    : status{PointStatus::EMPTY} { }

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
  StoneColor stoneColor{stone.getColor()};
  status = stoneColorToPointStatus(stoneColor);
}

void Point::removeStone() {
  if (status == PointStatus::EMPTY) {
    throw StoneRemovingException{};
  }
  stone.reset();
  status = PointStatus::EMPTY;
}

PointStatus Point::stoneColorToPointStatus(StoneColor stoneColor) const noexcept {
  if (stoneColor == StoneColor::BLACK) {
    return PointStatus::HAS_BLACK_STONE;
  } else {
    return PointStatus::HAS_WHITE_STONE;
  }
}

}