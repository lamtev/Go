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
  //TODO вот тут статик каст не очень нравиться, но это скорее дело вкуса
  //Я когда енамы использую я стараю не опираться на их числовые значения.
  //Мне кажется, тяжело уследить за тем чтобы числа соответсвовали
  //друг другу все время: вдруг кто-нибудь добавит еще один элемент или удалит его.
  //Я бы тут просто сделал условие, но, как я говорил, это все - дело вкуса.
}

void Point::removeStone() {
  if (status == PointStatus::EMPTY) {
    throw StoneRemovingException{};
  }
  stone.reset();
  status = PointStatus::EMPTY;
}

}