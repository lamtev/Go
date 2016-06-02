#include "GameProcess.h"

GameProcess::GameProcess(const int diagonal) noexcept : diagonal{diagonal},
                                                        board{new Board{diagonal}},
                                                        walketh{-1},
                                                        surrendered{Status::EMPTY},
                                                        winner{Status::EMPTY},
                                                        stonesEatenByBlack{0},
                                                        stonesEatenByWhite{0} {
  moves.reserve(1000);
  //pointsWithEatenStones.reserve(361);
}

GameProcess::~GameProcess() {
  delete board;
}

void GameProcess::putStone(int first, int second) {
  ifMoveIllegalThrowException(first, second);
  board->operator()(first, second).addStone(static_cast<Color>(walketh),
                                            first,
                                            second,
                                            0);
  moves.push_back(Move{first, second});
  updateWalketh();
}

void GameProcess::pass() noexcept {
  moves.push_back(passedMove);
  updateWalketh();
}

void GameProcess::surrender() noexcept {
  surrendered = static_cast<Status>(walketh);
  winner = (surrendered==Status::BLACK ? Status::WHITE : Status::BLACK);
}

bool GameProcess::isGameOver() const noexcept {
  return areTwoPasses() || static_cast<bool>(whoSurrendered());
}

Status GameProcess::whoSurrendered() const noexcept {
  return surrendered;
}

Status GameProcess::whoWon() const noexcept {
  return winner;
}

int GameProcess::getMoveIndex() const noexcept {
  return moves.size()+1;
}
3
std::vector<Move> &GameProcess::getMoves() const noexcept {
  return const_cast<std::vector<Move> &>(moves);
}

Move &GameProcess::getLastMove() const noexcept {
  return const_cast<Move &>(moves.back());
}

Move &GameProcess::getPenultMove() const noexcept {
  if (moves.size() >= 2) {
    return const_cast<Move &>(*(moves.end()-2));
  }
  return getLastMove();
}

int GameProcess::getStonesEatenByBlack() const noexcept {
  return stonesEatenByBlack;
}

int GameProcess::getStonesEatenByWhite() const noexcept {
  return stonesEatenByWhite;
}

Board &GameProcess::getBoard() const noexcept {
  return *board;
}

Status GameProcess::whoseMove() const noexcept {
  return static_cast<Status>(walketh);
}

void GameProcess::updateWalketh() noexcept {
  if (isGameOver()) {
    walketh = 0;
    return;
  }
  walketh*=(-1);
}

bool GameProcess::areTwoPasses() const noexcept {
  return moves.size() >= 2 && getLastMove()==passedMove &&
               getLastMove()==getPenultMove();
}

void GameProcess::ifMoveOutsideTheBoardThrowException(int first, int second) const {
  if (first < 1 || first > board->getDiagonal() ||
      second < 1 || second > board->getDiagonal()) {
    throw MoveOutsideTheBoardException();
  }
}

void GameProcess::ifMoveToNotEmptyPointThrowException(int first, int second) const {
  if (board->operator()(first, second).isNotEmpty()) {
    throw MoveToNotEmptyPointException();
  }
}

void GameProcess::ifMoveRepeatThrowException(int first, int second) const {
  if (getMoveIndex() >= 2) {
    Move currentMove{first, second};
    if (currentMove!=passedMove && currentMove==getPenultMove()) {
      throw MoveRepeatException();
    }
  }
}

void GameProcess::ifMoveToDieThrowException(int first, int second) const {
  if (/*isStoneEaten(first, second)*/false) {
    throw MoveToDieException();
  }
}

void GameProcess::ifMoveIllegalThrowException(int first, int second) const {
  ifMoveOutsideTheBoardThrowException(first, second);
  ifMoveToNotEmptyPointThrowException(first, second);
  ifMoveRepeatThrowException(first, second);
  ifMoveToDieThrowException(first, second);
}
