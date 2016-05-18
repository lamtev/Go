#include "GoEngineAPI.h"

GoEngineAPI::GoEngineAPI() noexcept : gameProcess{nullptr} { }

GoEngineAPI &GoEngineAPI::operator=(const GoEngineAPI &go) noexcept {
  this->gameProcess = go.gameProcess;
  return *this;
}

void GoEngineAPI::startGame(const int diagonal, const int rules, const int colorDistribution) noexcept {
  gameProcess = new GameProcess{diagonal};
}

GoEngineAPI::~GoEngineAPI() noexcept {
  delete gameProcess;
}

void GoEngineAPI::putStone(const int first, const int second) {
  gameProcess->putStone(first, second);
}

void GoEngineAPI::pass() noexcept {
  gameProcess->pass();
}

void GoEngineAPI::surrender() noexcept {
  gameProcess->surrender();
}

Status GoEngineAPI::whoseMove() const noexcept {
  return gameProcess->whoseMove();
}

bool GoEngineAPI::isGameOver() const noexcept {
  return gameProcess->isGameOver();
}

Status GoEngineAPI::whoSurrendered() const noexcept {
  return gameProcess->whoSurrendered();
}

Status GoEngineAPI::whoWon() const noexcept {
  return gameProcess->whoWon();
}

int GoEngineAPI::getDiagonal() const noexcept {
  return gameProcess->getBoard().getDiagonal();
}

Status GoEngineAPI::getPointsStatus(const int first, const int second) const noexcept {
  return gameProcess->getBoard().operator()(first, second).getStatus();
}

int GoEngineAPI::getStonesEatenByBlack() const noexcept {
  return gameProcess->getStonesEatenByBlack();
}

int GoEngineAPI::getStonesEatenByWhite() const noexcept {
  return gameProcess->getStonesEatenByWhite();
}

int GoEngineAPI::getMoveIndex() const noexcept {
  return gameProcess->getMoveIndex();
}

std::vector<Move> &GoEngineAPI::getMoves() const noexcept {
  return gameProcess->getMoves();
}

Move &GoEngineAPI::getLastMove() const noexcept {
  return gameProcess->getLastMove();
}

Move &GoEngineAPI::getPenultMove() const noexcept {
  return gameProcess->getPenultMove();
}
