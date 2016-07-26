#ifndef GO_GOENGINE_H
#define GO_GOENGINE_H

#include "API.h"
#include "Board.h"
#include "MoveChecker.h"
#include "GameIsOverException.h"

namespace Go {

enum class WhoseMove {
  GAME_IS_OVER,
  BLACKS,
  WHITES
};

class GoEngine: public API {
 public:
  GoEngine(int boardDimension) noexcept;
  void makeAMove(const Move &move);
  WhoseMove getWhoseMove() const noexcept;
  const Moves &getMoves() const noexcept;

 private:
  WhoseMove whoseMove;
  std::shared_ptr<Board> board;
  std::shared_ptr<Moves> moves;
  std::unique_ptr<MoveChecker> moveChecker;
  //std::shared_ptr<BoardAnalyser> boardAnalyser;
  //std::shared_ptr<StonesRemover> stonesRemover;
  //std::unique_ptr<UndoRedoer> undoRedoer;
  //std::unique_ptr<ScoreCalculator> scoreCalculator;

  void check() noexcept;
  void resign() noexcept;
  void setStone(const PointLocation &pointLocation);
  void logMove(const Move &move) noexcept;
  void changeWhoseMove() noexcept;
};

}

#endif //GO_GOENGINE_H
