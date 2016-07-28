#ifndef GO_POINT_H
#define GO_POINT_H

#include <memory>
#include "PointLocation.h"
#include "Stone.h"
#include "exceptions/StoneGettingException.h"
#include "exceptions/StoneSettingException.h"
#include "exceptions/StoneRemovingException.h"

namespace Go {

enum class PointStatus {
  EMPTY = -1,
  HAS_BLACK_STONE = 0,
  HAS_WHITE_STONE = 0
};

class Point {
 public:
  explicit Point() noexcept;
  PointStatus getStatus() const noexcept;
  Stone getStone() const;
  void setStone(const Stone &stone);
  void removeStone();

 private:
  PointStatus status;
  //TODO think mb weak_ptr
  std::shared_ptr<Stone> stone;

  PointStatus stoneColorToPointStatus(StoneColor stoneColor) const noexcept;
};

}

#endif //GO_POINT_H
