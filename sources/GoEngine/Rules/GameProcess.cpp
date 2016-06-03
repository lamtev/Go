#include "GameProcess.h"

GameProcess::GameProcess(const int diagonal) noexcept : diagonal{diagonal},
                                                        board{new Board{diagonal}},
                                                        walketh{-1},
                                                        surrendered{Status::EMPTY},
                                                        winner{Status::EMPTY},
                                                        stonesEatenByBlack{0},
                                                        stonesEatenByWhite{0} {
  moves.reserve(1000);
  pointsWithEatenStones.reserve(361);
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
  determineEatenStones();
  deleteEatenStones();
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

void GameProcess::determineEatenStones() noexcept {
  for (int i = 1; i <= diagonal; ++i) {
    for (int j = 1; j <= diagonal; ++j) {
      if (board->operator()(i, j).getStatus() != whoseMove() && couldStoneBeEaten(i, j)) {
        pointsWithEatenStones.push_back(&board->operator()(i, j));
      }
    }
  }
}

void GameProcess::deleteEatenStones() noexcept {
  for (auto point : pointsWithEatenStones) {
    ++(point->getStatus()==Status::BLACK ? stonesEatenByWhite : stonesEatenByBlack);
    point->deleteStone();
  }
  pointsWithEatenStones.erase(pointsWithEatenStones./*c*/begin(), pointsWithEatenStones./*c*/end());
}

bool GameProcess::couldStoneBeEaten(int first, int second) const noexcept {
  Status pointStatus{board->operator()(first, second).getStatus()};
  Status eaterStatus{static_cast<Status>(-static_cast<int>(pointStatus))};
  if (pointStatus != Status::EMPTY) {
    if (first==1) {
      Status rightStatus{board->operator()(first+1, second).getStatus()};
      if (second==1) {
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            rightStatus==downStatus &&
            rightStatus==eaterStatus;
      }
      else if (second==diagonal) {
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            rightStatus==upStatus &&
            rightStatus==eaterStatus;
      }
      else {
        Status downStatus{board->operator()(first, second+1).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            rightStatus==downStatus &&
            rightStatus==upStatus &&
            rightStatus==eaterStatus;
      }
    }
    else if (first==diagonal) {
      Status leftStatus{board->operator()(first-1, second).getStatus()};
      if (second==1) {
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            leftStatus==downStatus &&
            leftStatus==eaterStatus;
      }
      else if (second==diagonal) {
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            leftStatus==upStatus &&
            leftStatus==eaterStatus;
      }
      else {
        Status downStatus{board->operator()(first, second+1).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            leftStatus==downStatus &&
            leftStatus==upStatus &&
            leftStatus==eaterStatus;
      }
    }
    else {
      Status rightStatus{board->operator()(first+1, second).getStatus()};
      Status leftStatus{board->operator()(first-1, second).getStatus()};
      if (second==1) {
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            rightStatus==leftStatus &&
            rightStatus==downStatus &&
            rightStatus==eaterStatus;
      }
      else if (second==diagonal) {
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            rightStatus==leftStatus &&
            rightStatus==upStatus &&
            rightStatus==eaterStatus;
      }
      else {
        Status downStatus{board->operator()(first, second+1).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            rightStatus==leftStatus &&
            rightStatus==downStatus &&
            rightStatus==upStatus &&
            rightStatus==eaterStatus;
      }
    }
  }
  return false;
}

bool GameProcess::isMoveToDie(int first, int second) const noexcept {
  Point &point = board->operator()(first, second);
  point.addStone(static_cast<Color>(whoseMove()), first, second, 4);
  bool canNotEat = true;
  for (int i = 1; i <= diagonal; ++i) {
    for (int j = 1; j <= diagonal; ++j) {
      if (board->operator()(i, j).getStatus()==static_cast<Status>(-static_cast<int>(whoseMove())) &&
          couldStoneBeEaten(i, j)) {
        canNotEat = false;
        break;
      }
    }
    if (!canNotEat) {
      break;
    }
  }
  bool result{couldStoneBeEaten(first, second) && canNotEat};
  point.deleteStone();
  return result;
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
  if (isMoveToDie(first, second)) {
    throw MoveToDieException();
  }
}

void GameProcess::ifMoveIllegalThrowException(int first, int second) const {
  ifMoveOutsideTheBoardThrowException(first, second);
  ifMoveToNotEmptyPointThrowException(first, second);
  ifMoveRepeatThrowException(first, second);
  ifMoveToDieThrowException(first, second);
}

