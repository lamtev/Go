#include "MoveChecker.h"

namespace Go {

MoveChecker::MoveChecker(const Board &board, const Moves &moves) noexcept:
    board{std::make_shared<Board>(board)},
    moves{std::make_shared<Moves>(moves)},
    destinationLocation{degeneratedPointLocation} { }

void MoveChecker::setPointLocation(const PointLocation &destinationLocation) noexcept {
  this->destinationLocation = destinationLocation;
}

void MoveChecker::checkForLegal() const {
  checkForDestinationPointWithinBoard();
  checkForDestinationPointIsEmpty();
  checkForNotToDie();
  checkForNotRepeat();
}

void MoveChecker::checkForDestinationPointWithinBoard() const {
  if (destinationLocation.getHorizontalCoordinate() < 1 ||
      destinationLocation.getHorizontalCoordinate() > board->getDimension() ||
      destinationLocation.getVerticalCoordinate() < 1 ||
      destinationLocation.getVerticalCoordinate() > board->getDimension()) {
    throw MoveOutsideTheBoardException{};
  }
}

//BUG
void MoveChecker::checkForDestinationPointIsEmpty() const {
  if (board->getPointStatus(destinationLocation) == PointStatus::EMPTY) {
    throw MoveToNotEmptyPointException{};
  }
}

void MoveChecker::checkForNotToDie() const {
  if (false) {
    throw MoveToDieException{};
  }
}

void MoveChecker::checkForNotRepeat() const {
  if (moves->size() < 2) {
    return;
  }
  Move penultimateMove = moves->getPenultimateMove();
  if (penultimateMove.getPointLocation() == destinationLocation) {
    throw MoveRepeatException{};
  }
}

}