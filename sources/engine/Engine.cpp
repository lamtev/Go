#include "Engine.h"

namespace Go {

Engine::Engine(int boardDimension) noexcept:
    board{std::make_shared<Board>(boardDimension)},
    moves{std::make_shared<Moves>()},
    moveAnalyser{std::make_unique<MoveAnalyser>(*board, *moves)},
    boardDimension{boardDimension},
    activeColor{PlayerColor::BLACK},
    gameIsOver{false} { }

void Engine::setStone(const PointLocation &pointLocation) {
  checkForGameOver();
  Move move{MoveType::STONE_SETTING, activeColor, pointLocation};
  moveAnalyser->checkMove(move);
  StoneColor stoneColor;
  if (activeColor == PlayerColor::BLACK) {
    stoneColor = StoneColor::BLACK;
  } else {
    stoneColor = StoneColor::WHITE;
  }
  Stone stone{stoneColor};
  board->setStoneToPoint(stone, pointLocation);
  logMove(move);
  //TODO removeStones();
}

void Engine::check() {
  checkForGameOver();
  Move previousMove{moves->getLastMove()};
  if (moves->getSize() > 1 && previousMove.getType() == MoveType::CHECK) {
    gameIsOver = true;
  }
  Move move{MoveType::CHECK, activeColor};
  logMove(move);
}

void Engine::resign() {
  checkForGameOver();
  Move move{MoveType::RESIGN, activeColor};
  logMove(move);
  gameIsOver = true;
}

PlayerColor Engine::whoseMove() const noexcept {
  return activeColor;
}

bool Engine::isGameOver() const noexcept {
  return gameIsOver;
}

void Engine::changeActiveColor() noexcept {
  if (activeColor == PlayerColor::BLACK) {
    activeColor = PlayerColor::WHITE;
  } else {
    activeColor = PlayerColor::BLACK;
  }
}

void Engine::logMove(const Move &move) noexcept {
  moves->pushMoveToBack(move);
}

void Engine::checkForGameOver() const {
  if (gameIsOver) {
    throw GameIsOverException{};
  }
}

}