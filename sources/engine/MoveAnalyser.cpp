#include "MoveAnalyser.h"

namespace Go {

MoveAnalyser::MoveAnalyser(const Board &board, const Moves &moves) noexcept:
    board{std::make_shared<Board>(board)},
    moves{std::make_shared<Moves>(moves)} { }

void MoveAnalyser::checkMove(const Move &move) const {
  checkForWithinBoard(move);
  checkForEmptyDestinationPoint(move);
  checkForNotToDie(move);
  checkForNotRepeat(move);
}

void MoveAnalyser::checkForWithinBoard(const Move &move) const {
  PointLocation pointLocation{move.getPointLocation()};
  short verticalCoordinate = static_cast<short>(pointLocation.getVerticalCoordinate());
  HorizontalCoordinate horizontalCoordinate = pointLocation.getHorizontalCoordinate();
  if (verticalCoordinate < 1 ||
      verticalCoordinate > board->getDimension() ||
      horizontalCoordinate < 1 ||
      horizontalCoordinate > board->getDimension()) {
    throw MoveOutsideTheBoardException{};
  }
}

void MoveAnalyser::checkForEmptyDestinationPoint(const Move &move) const {
  if (board->getPointStatus(move.getPointLocation()) != PointStatus::EMPTY) {
    throw MoveToNotEmptyPointException{};
  }
}

void MoveAnalyser::checkForNotToDie(const Move &move) const {
  if (false) {
    throw MoveToDieException{};
  }
}

void MoveAnalyser::checkForNotRepeat(const Move &move) const {
  if (moves->getSize() > 2 && move == moves->getPenultimateMove()) {
    throw MoveRepeatException{};
  }
}

}