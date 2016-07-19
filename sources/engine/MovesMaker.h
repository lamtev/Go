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
  //std::shared_ptr<MoveChecker> moveChecker;
  //std::shared_ptr<BoardAnalyser> boardAnalyser;
  //std::shared_ptr<StonesRemover> stonesRemover;

  void check() noexcept;
  void resign() noexcept;
  void setStone(const PointLocation &pointLocation);
  void logMove(const Move &move) noexcept;

  void changeWhoseMove() noexcept;
};

}

#endif //GO_MOVESMAKER_H
