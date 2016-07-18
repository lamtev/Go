#include "Moves.h"

namespace Go {

const Move &Moves::getLastMove() const {
  if (moves.empty()) {
    throw LastMoveNotFoundException{};
  }
  return moves.back();
}

const Move &Moves::getPenultimateMove() const {
  if (moves.size() < 2) {
    throw PenultimateMoveNotFoundException{};
  }
  auto it = moves.cend();
  --it;
  return *(--it);
}

void Moves::pushMoveToBack(const Move &move) noexcept {
  moves.push_back(move);
}

void Moves::popLastMove() {
  if (moves.empty()) {
    throw EmptyMovesListException{};
  }
  moves.pop_back();
}

}