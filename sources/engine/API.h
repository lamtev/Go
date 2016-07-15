#ifndef GO_API_H
#define GO_API_H

namespace Go {

class API {
 public:
  void setBoardDimension(int boardDimension);
  void startGame();
  void putStone(int verticalCoordinate, int horizontalCoordinate);
  void check();
  void resign();
  /*PlayerColor*/ void whoseMove();
  /*Container*/ void getMoves() const noexcept;
  void undo();
  void redo();

};

}
#endif //GO_API_H
