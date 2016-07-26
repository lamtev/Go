#ifndef GO_MOVECHECKER_H
#define GO_MOVECHECKER_H

#include <memory>
#include "Board.h"
#include "Moves.h"
#include "MoveToNotEmptyPointException.h"
#include "MoveOutsideTheBoardException.h"
#include "MoveToDieException.h"
#include "MoveRepeatException.h"

namespace Go {

class MoveChecker {
 public:
  MoveChecker(const Board &board, const Moves &moves) noexcept;
  void setPointLocation(const PointLocation &destinationLocation) noexcept;
  void checkForLegal() const;

 private:
  std::shared_ptr<Board> board;
  std::shared_ptr<Moves> moves;
  PointLocation destinationLocation;

  void checkForDestinationPointWithinBoard() const;
  void checkForDestinationPointIsEmpty() const;
  void checkForNotToDie() const;
  void checkForNotRepeat()const;
};

}

#endif //GO_MOVECHECKER_H
