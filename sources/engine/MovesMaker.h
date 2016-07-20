#ifndef GO_MOVESMAKER_H
#define GO_MOVESMAKER_H

#include "Moves.h"
#include "Board.h"
#include "GameIsOverException.h"

namespace Go {

enum class WhoseMove {
  GAME_IS_OVER,
  BLACKS,
  WHITES
};

class MovesMaker {
 public:
  MovesMaker(int boardDimension) noexcept;
  void makeAMove(const Move &move);
  WhoseMove getWhoseMove() const noexcept;
  const Moves &getMoves() const noexcept;

 private:
  WhoseMove whoseMove;
  std::shared_ptr<Board> board;
  std::shared_ptr<Moves> moves;
  //TODO think about to locate them in another class
  //std::shared_ptr<MoveChecker> moveChecker;
  //std::shared_ptr<BoardAnalyser> boardAnalyser;
  //std::shared_ptr<StonesRemover> stonesRemover;
  //TODO этот кусок кода почему-то сразу наводит меня на мысли об реализации API.
  //Можно попробовать реализовать в этом классе логику взаимодействия объектов,
  //перечисленных выше и добавить методы соответсвующие API
  //или перенести это все в другой класс реализующий API и тогда MovieMaker станет
  //частью той реализации API, так же как классы из закоменнтированных строк.

  void check() noexcept;
  void resign() noexcept;
  void setStone(const PointLocation &pointLocation);
  void logMove(const Move &move) noexcept;

  void changeWhoseMove() noexcept;
};

}

#endif //GO_MOVESMAKER_H
