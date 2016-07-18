#ifndef GO_MOVES_H
#define GO_MOVES_H

#include <list>
#include <stack>
#include "Move.h"
#include "LastMoveNotFoundException.h"
#include "PenultimateMoveNotFoundException.h"
#include "EmptyMovesListException.h"

namespace Go {

class Moves {
 public:
  const Move &getLastMove() const;
  const Move &getPenultimateMove() const;
  void pushMoveToBack(const Move &move) noexcept;
  void popLastMove();

 private:
  std::list<Move> moves;
  std::stack<Move> undoneMoves;
};

}

#endif //GO_MOVES_H
