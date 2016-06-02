#include "Point.h"

Point::Point(Status status) noexcept : status{status},
                                       stone{nullptr},
                                       isStoneDeleted{true} { }

Point::Point(const Point &point) noexcept : status(point.status),
                                            stone{point.stone},
                                            isStoneDeleted{point.isStoneDeleted} { }

Point::~Point() noexcept {
  if (!isStoneDeleted) {
    deleteStone();
  }
}

Point &Point::operator=(const Point &point) noexcept {
  this->status = point.status;
  this->stone = point.stone;
  this->isStoneDeleted = point.isStoneDeleted;
  return *this;
}

void Point::addStone(const Color color, const int first, const int second, const int breaths) noexcept {
  stone = new Stone{color, first, second, breaths};
  status = static_cast<Status>(color);
  isStoneDeleted = false;
}

void Point::deleteStone() noexcept {
  status = Status::EMPTY;
  delete stone;
  isStoneDeleted = true;
}

Status Point::getStatus() const noexcept {
  return status;
}

Stone &Point::getStone() const noexcept {
  return *stone;
}

bool Point::isEmpty() const noexcept {
  return status==Status::EMPTY;
}

bool Point::isNotEmpty() const noexcept {
  return !isEmpty();
}
