#ifndef GO_MOVEANALYSER_H
#define GO_MOVEANALYSER_H

#include <memory>
#include "Board.h"
#include "Moves.h"

namespace Go {

class MoveAnalyser {
 public:
  MoveAnalyser(const Board &board, const Moves &moves) noexcept;
 private:
  std::shared_ptr<Board> board;
  std::shared_ptr<Moves> moves;
};

}

#endif //GO_MOVEANALYSER_H
