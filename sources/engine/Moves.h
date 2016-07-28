#ifndef GO_MOVES_H
#define GO_MOVES_H

#include <list>
#include "Move.h"
#include "exceptions/LastMoveGettingException.h"
#include "exceptions/PenultimateMoveGettingException.h"
#include "exceptions/LastMovePoppingException.h"

namespace Go {

class Moves {
 public:
  const Move &getLastMove() const;
  const Move &getPenultimateMove() const;
  void pushMoveToBack(const Move &move) noexcept;
  void popLastMove();
  int getSize() const noexcept;

 private:
  std::list<Move> moves;
};

}

#endif //GO_MOVES_H
