#include "Moves.h"

namespace Go {

//TODO think about returning reference not value
//TODO think about exceptions
Move Moves::getLastMove() const {
  return moves.back();
}

Move Moves::getPenultMove() const {
  return *(--moves.end());
}

void Moves::pushMoveToBack(const Move &move) noexcept {
  moves.push_back(move);
}

void Moves::undo() {
  undoneMoves.push(moves.back());
  moves.pop_back();
}

void Moves::redo() {
  moves.push_back(undoneMoves.top());
  undoneMoves.pop();
}

}