#ifndef GO_POINT_H
#define GO_POINT_H

#include <memory>
#include "PointLocation.h"
#include "Stone.h"
#include "StoneGettingException.h"
#include "StoneSettingException.h"
#include "StoneRemovingException.h"

namespace Go {

enum class PointStatus {
  EMPTY = 0,
  HAS_BLACK_STONE,
  HAS_WHITE_STONE
};

class Point {
 public:
  //TODO меня смущает в этом конструкторе возможность поставить любой статус без установки камня.
  //Может не стоит передавать сюда статус, а просто в теле конструктора ставить его EMPTY?
  explicit Point(PointStatus status = PointStatus::EMPTY) noexcept;
  PointStatus getStatus() const noexcept;
  Stone getStone() const;
  void setStone(const Stone &stone);
  void removeStone();

 private:
  PointStatus status;
  //TODO think mb weak_ptr
  std::shared_ptr<Stone> stone;
};

}

#endif //GO_POINT_H
