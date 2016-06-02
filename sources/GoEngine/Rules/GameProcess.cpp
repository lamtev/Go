#include "GameProcess.h"

GameProcess::GameProcess(const int diagonal) noexcept : diagonal{diagonal},
                                                        board{new Board{diagonal}},
                                                        movesSize{100},
                                                        moveIndex{0},
                                                        surrendered{Status::EMPTY},
                                                        winner{Status::EMPTY},
                                                        stonesEatenByBlack{0},
                                                        stonesEatenByWhite{0} {
  moves.resize(movesSize);
  pointsWithEatenStones.resize(1);
  pointsWithEatenStones[0] = nullptr;
}

GameProcess::~GameProcess() {
  delete board;
}

Status GameProcess::whoseMove() const noexcept {
  if (isGameOver()) {
    return Status::EMPTY;
  }
  return isBlacksMove() ? Status::BLACK : Status::WHITE;
}

void GameProcess::putStone(int first, int second) {
  resizeMoves();
  ifMoveIllegalThrowException(first, second);
  //TODO обдумать постановку камня на доску!!!
  //todo не нравится мне вот эта строчка... выходи пункт равен тому, чей ход...
  //может что нибудь типа такой конструкции:
  //Point &samplePoint = board(first, second);
  //samplePoint.setStone(Stone(whoseMove())); ...
  //тоже не очень хорошо, громоздко, но чуть чуть понятнее
  //тут подумать надо
  board->operator()(first, second) = whoseMove();
  //todo слишком длинно, колбаса
  //todo а можно просто board(first, second)?
  //лучше разбить на 2-3 строчки.
  //тут бы еще мог бы метод setStone кстати быть:
  //Point samplePoint = board(first, second);
  //Stone sampleStone(samplePoint.getStatus(), first, second, 0);
  //board(first, second).setStone(sampleStone);
  //дело вкуса, конечно, но строчка реально длинная и непонятная.
  board->operator()(first, second).createStone(static_cast<Color>(board->operator()(first, second).getStatus()),
                                               first,
                                               second,
                                               0);
  moves[moveIndex] = Move{first, second};
  ++moveIndex;
  determineEatenStones();
  //deleteEatenStones();
}

void GameProcess::pass() noexcept {
  resizeMoves();
  moves[moveIndex] = passedMove;
  ++moveIndex;
}

void GameProcess::surrender() noexcept {
  surrendered = whoseMove();
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
  return moveIndex;
}

std::vector<Move> &GameProcess::getMoves() const noexcept {
  return const_cast<std::vector<Move> &>(moves);
}

Move &GameProcess::getLastMove() const noexcept {
  return const_cast<Move &>(moves[moveIndex - 1]);
}

Move &GameProcess::getPenultMove() const noexcept {
  return const_cast<Move &>(moves[moveIndex - 2]);
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

bool GameProcess::isStoneEaten(int first, int second) const noexcept {
  if (board->operator()(first, second).isNotEmpty()) {
    Status pointStatus{board->operator()(first, second).getStatus()};
    Status eaterStatus{pointStatus==Status::BLACK ? Status::WHITE : Status::BLACK};
    if (first == 1) {
      if (second == 1) {
        Status rightStatus{board->operator()(first+1, second).getStatus()};
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            downStatus == rightStatus &&
            downStatus == eaterStatus;
      }
      else if (second == diagonal) {
        Status rightStatus{board->operator()(first+1, second).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            upStatus == rightStatus &&
            upStatus == eaterStatus;
      }
      else {
        Status rightStatus{board->operator()(first+1, second).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            upStatus == rightStatus &&
            upStatus == downStatus &&
            upStatus == eaterStatus;
      }
    }
    else if (first == diagonal) {
      if (second == 1) {
        Status leftStatus{board->operator()(first-1, second).getStatus()};
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            downStatus == leftStatus &&
            downStatus == eaterStatus;
      }
      else if (second == diagonal) {
        Status leftStatus{board->operator()(first-1, second).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            upStatus == leftStatus &&
            upStatus == eaterStatus;
      }
      else {
        Status leftStatus{board->operator()(first-1, second).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            upStatus == leftStatus &&
                upStatus == downStatus &&
                upStatus == eaterStatus;
      }
    }
    else {
      if (second == 1) {
        Status leftStatus{board->operator()(first-1, second).getStatus()};
        Status rightStatus{board->operator()(first+1, second).getStatus()};
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            downStatus == leftStatus &&
            downStatus == rightStatus &&
            downStatus == eaterStatus;
      }
      else if (second == diagonal) {
        Status leftStatus{board->operator()(first-1, second).getStatus()};
        Status rightStatus{board->operator()(first+1, second).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        return
            upStatus == leftStatus &&
            upStatus == rightStatus &&
            upStatus == eaterStatus;
      }
      else {
        Status leftStatus{board->operator()(first-1, second).getStatus()};
        Status rightStatus{board->operator()(first+1, second).getStatus()};
        Status upStatus{board->operator()(first, second-1).getStatus()};
        Status downStatus{board->operator()(first, second+1).getStatus()};
        return
            upStatus == leftStatus &&
            upStatus == rightStatus &&
            upStatus == downStatus &&
            upStatus == eaterStatus;
      }
    }
  }
  return false;
}

void GameProcess::determineEatenStones() noexcept {
  unsigned count = 0;
  for (int i = 1; i <= diagonal; ++i) {
    for (int j = 1; j <= diagonal; ++j) {
      if (isStoneEaten(i, j)) {
//        pointsWithEatenStones.resize(++count);
//        pointsWithEatenStones[count-1] = &board->operator()(i, j);
        board->operator()(i, j).deleteStone();
      }
    }
  }
//  for (auto point : pointsWithEatenStones) {
//    point = nullptr;
//  }
//  pointsWithEatenStones.resize(0);
}

void GameProcess::deleteEatenStones() noexcept {
  for (auto point : pointsWithEatenStones) {
    point->deleteStone();
  }
}

bool GameProcess::areTwoPasses() const noexcept {
  return moveIndex >= 2 ?
         getLastMove()==passedMove &&
             getLastMove()==getPenultMove() :
         false;
}

bool GameProcess::isBlacksMove() const noexcept {
  return !(moveIndex%2);
}

void GameProcess::resizeMoves() noexcept {
  if (movesSize - 1==moveIndex) {
    movesSize += 100;
    moves.resize(movesSize);
  }
}

void GameProcess::removeEatenStones() noexcept {
  //TODO removeEatenStones
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
  if (moveIndex >= 2) {
    Move currentMove{first, second};
    if (currentMove!=passedMove && currentMove==getPenultMove()) {
      throw MoveRepeatException();
    }
  }
}

void GameProcess::ifMoveToDieThrowException(int first, int second) const {
  //TODO void GameProcess::ifMoveToDie

  if (false) {
    throw MoveToDieException();
  }
}

void GameProcess::ifMoveIllegalThrowException(int first, int second) const {
  ifMoveOutsideTheBoardThrowException(first, second);
  ifMoveToNotEmptyPointThrowException(first, second);
  //ifMoveRepeatThrowException(first, second);
  ifMoveToDieThrowException(first, second);
}
