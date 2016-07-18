#ifndef GO_MOVE_H
#define GO_MOVE_H

#include "PointLocation.h"
#include "Stone.h"
#include "PointLocationNotFoundException.h"

namespace Go {

enum class MoveType {
  StoneSetting,
  CHECK,
  RESIGN
};

enum class PlayerColor {
  BLACK = 1,
  WHITE
};

class Move {
 public:
  constexpr Move(MoveType type, PlayerColor playerColor, PointLocation pointLocation) noexcept
      : type{type},
        playerColor{playerColor},
        pointLocation{pointLocation} { }

  constexpr Move(MoveType type, PlayerColor playerColor) noexcept
      : type{type},
        playerColor{playerColor},
        pointLocation{degeneratedPointLocation} { }

  constexpr MoveType getMoveType() const noexcept {
    return type;
  }

  constexpr PlayerColor getPlayerColor() const noexcept {
    return playerColor;
  }

  PointLocation getPointLocation() const {
    if (type != MoveType::StoneSetting) {
      throw PointLocationNotFoundException{};
    }
    return pointLocation;
  }

  constexpr bool operator==(const Move &move) const noexcept {
    if (type == MoveType::StoneSetting) {
      return
          type == move.type &&
          playerColor == move.playerColor &&
          pointLocation == move.pointLocation;
    }
    else
      return
          type == move.type &&
          playerColor == move.playerColor;
  }

  constexpr bool operator!=(const Move &move) const noexcept {
    return !(*this == move);
  }

 private:
  MoveType type;
  PlayerColor playerColor;
  PointLocation pointLocation;
};

}

#endif //GO_MOVE_H
