#include "Moves.h"

namespace Go {

const Move &Moves::getLastMove() const {
  if (moves.empty()) {
    throw LastMoveGettingException{};
  }
  return moves.back();
}

const Move &Moves::getPenultimateMove() const {
  if (moves.size() < 2) {
    throw PenultimateMoveGettingException{};
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
    throw LastMovePoppingException{};
  }
  moves.pop_back();
}

int Moves::size() const noexcept {
  return moves.size();
}

}