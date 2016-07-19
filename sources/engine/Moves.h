#ifndef GO_MOVES_H
#define GO_MOVES_H

#include <list>
#include <stack>
#include "Move.h"
#include "LastMoveGettingException.h"
#include "PenultimateMoveGettingException.h"
#include "LastMovePoppingException.h"

namespace Go {

//TODO think about delta between moves for undo and redo

class Moves {
 public:
  const Move &getLastMove() const;
  const Move &getPenultimateMove() const;
  void pushMoveToBack(const Move &move) noexcept;
  void popLastMove();

 private:
  std::list<Move> moves;
};

}

#endif //GO_MOVES_H
