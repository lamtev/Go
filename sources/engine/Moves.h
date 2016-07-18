#ifndef GO_MOVES_H
#define GO_MOVES_H

#include <list>
#include <stack>
#include "Move.h"

namespace Go {

class Moves {
 public:
  Move getLastMove() const;
  Move getPenultMove() const;
  void pushMoveToBack(const Move &move) noexcept;
  void undo();
  void redo();
 private:
  std::list<Move> moves;
  std::stack<Move> undoneMoves;
};

}

#endif //GO_MOVES_H
