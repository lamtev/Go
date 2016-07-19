#include "MovesMaker.h"

namespace Go {

MovesMaker::MovesMaker(int boardDimension) noexcept
    : whoseMove{WhoseMove::BLACKS},
      moves{std::make_shared<Moves>()},
      board{std::make_shared<Board>(boardDimension)} { }


//TODO fix bug with RESIGN
void MovesMaker::makeAMove(const Move &move) {
  if (whoseMove == WhoseMove::GAME_IS_OVER) {
    //TODO throw game is over exception
    return;
  }
  switch (move.getMoveType()) {
    case MoveType::CHECK:
      check();
      break;
    case MoveType::RESIGN:
      resign();
    case MoveType::StoneSetting:
      setStone(move.getPointLocation());
      break;
  }
  logMove(move);
  changeWhoseMove();
}

const Moves &MovesMaker::getMoves() const noexcept {
  return *moves;
}

WhoseMove MovesMaker::getWhoseMove() const noexcept {
  return whoseMove;
}

void MovesMaker::check() noexcept {
  if (moves->getLastMove().getMoveType() == MoveType::CHECK) {
    whoseMove = WhoseMove::GAME_IS_OVER;
  }
}

void MovesMaker::resign() noexcept {
  whoseMove = WhoseMove::GAME_IS_OVER;
}

void MovesMaker::setStone(const PointLocation &pointLocation) {
  //checkForLegal();
  StoneColor stoneColor{static_cast<StoneColor>(whoseMove)};
  board->setStoneToPoint(Stone{stoneColor}, pointLocation);
  //analyseBoard();
}

void MovesMaker::logMove(const Move &move) noexcept {
  moves->pushMoveToBack(move);
}

void MovesMaker::changeWhoseMove() noexcept {
  if (whoseMove == WhoseMove::BLACKS) {
    whoseMove = WhoseMove::WHITES;
  } else if (whoseMove == WhoseMove::WHITES) {
    whoseMove = WhoseMove::BLACKS;
  }
}

}