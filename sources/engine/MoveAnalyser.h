#ifndef GO_MOVEANALYSER_H
#define GO_MOVEANALYSER_H

#include <memory>
#include "Board.h"
#include "Moves.h"
#include "exceptions/MoveOutsideTheBoardException.h"
#include "exceptions/MoveToNotEmptyPointException.h"
#include "exceptions/MoveToDieException.h"
#include "exceptions/MoveRepeatException.h"

namespace Go {

class MoveAnalyser {
 public:
  MoveAnalyser(const Board &board, const Moves &moves) noexcept;
  void checkMove(const Move &move) const;
 private:
  std::shared_ptr<Board> board;
  std::shared_ptr<Moves> moves;

  void checkForWithinBoard(const Move &move) const;
  void checkForEmptyDestinationPoint(const Move &move) const;
  void checkForNotToDie(const Move &move) const;
  void checkForNotRepeat(const Move &move) const;

};

}

#endif //GO_MOVEANALYSER_H
