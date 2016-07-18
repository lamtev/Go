#ifndef GO_MOVES_H
#define GO_MOVES_H

#include <list>
#include <stack>
#include "Move.h"

namespace Go {

class Moves {
 public:
  void pushMoveToBack(const Move &move) noexcept;
  Move getLastMove() const noexcept;
  void undo();
  void redo();
 private:
  std::list<Move> moves;
  std::stack<Move> undoneMoves;
};

}

#endif //GO_MOVES_H
