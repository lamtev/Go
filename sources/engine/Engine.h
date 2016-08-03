#ifndef GO_ENGINE_H
#define GO_ENGINE_H

#include <memory>
#include "API.h"
#include "Board.h"
#include "Moves.h"
#include "exceptions/GameIsOverException.h"

namespace Go {

class Engine : public API {
 public:
  Engine(int boardDimension = 19) noexcept;
  void setStone(const PointLocation &pointLocation);
  void check();
  void resign();
  PlayerColor whoseMove() const noexcept;
  bool isGameOver() const noexcept;
 private:
  std::shared_ptr<Board> board;
  std::shared_ptr<Moves> moves;
  const int boardDimension;
  PlayerColor activeColor;
  bool gameIsOver;

  void changeActiveColor() noexcept;
  void logMove(const Move &move) noexcept;
  void checkForGameOver() const;

};

}

#endif //GO_ENGINE_H
