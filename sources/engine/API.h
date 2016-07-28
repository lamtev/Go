#ifndef GO_API_H
#define GO_API_H

#include "Moves.h"

namespace Go {

class API {
 public:
  virtual ~API() noexcept {}
  //virtual void setBoardDimension(int boardDimension) = 0;
  virtual void setStone(const PointLocation &pointLocation) = 0;
  virtual void check() = 0;
  virtual void resign() = 0;
  //virtual void undo() = 0;
  //virtual void redo() = 0;
  //virtual PlayerColor whoseMove() const noexcept = 0;
  //virtual const Moves &getMoves() const noexcept = 0;

};

}
#endif //GO_API_H
