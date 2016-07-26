#ifndef GO_MOVEOUTSIDETHEBOARDEXCEPTION_H
#define GO_MOVEOUTSIDETHEBOARDEXCEPTION_H

#include <exception>

namespace Go {

class MoveOutsideTheBoardException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't make a move outside the board!!!";
  }
};

}

#endif //GO_MOVEOUTSIDETHEBOARDEXCEPTION_H
