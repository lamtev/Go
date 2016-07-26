#include "GoEngine.h"

namespace Go {

GoEngine::GoEngine(int boardDimension) noexcept
    : whoseMove{WhoseMove::BLACKS},
      board{std::make_shared<Board>(boardDimension)},
      moves{std::make_shared<Moves>()},
      moveChecker{std::make_unique<MoveChecker>(*board, *moves)} { }

//TODO think about pattern
void GoEngine::makeAMove(const Move &move) {
  if (whoseMove == WhoseMove::GAME_IS_OVER) {
    throw GameIsOverException{};
  }
  //TODO check move for legal
  switch (move.getMoveType()) {
    case MoveType::CHECK:
      check();
      break;
    case MoveType::RESIGN:
      resign();
      break;
    case MoveType::STONE_SETTING:
      setStone(move.getPointLocation());
      break;
  }
  logMove(move);
  changeWhoseMove();
}

const Moves &GoEngine::getMoves() const noexcept {
  return *moves;
}

WhoseMove GoEngine::getWhoseMove() const noexcept {
  return whoseMove;
}

void GoEngine::check() noexcept {
  if (moves->getLastMove().getMoveType() == MoveType::CHECK) {
    whoseMove = WhoseMove::GAME_IS_OVER;
  }
}

void GoEngine::resign() noexcept {
  whoseMove = WhoseMove::GAME_IS_OVER;
}

void GoEngine::setStone(const PointLocation &pointLocation) {
  moveChecker->setPointLocation(pointLocation);
  moveChecker->checkForLegal();
  StoneColor stoneColor{static_cast<StoneColor>(whoseMove)};
  board->setStoneToPoint(Stone{stoneColor}, pointLocation);
  //TODO analyse board and remove stones
  //stonesRemover->removeEatenStones();
}

void GoEngine::logMove(const Move &move) noexcept {
  moves->pushMoveToBack(move);
}

void GoEngine::changeWhoseMove() noexcept {
  if (whoseMove == WhoseMove::BLACKS) {
    whoseMove = WhoseMove::WHITES;
  } else if (whoseMove == WhoseMove::WHITES) {
    whoseMove = WhoseMove::BLACKS;
  }

}

}