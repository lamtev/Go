#ifndef GO_MOVEREPEATEXCEPTION_H
#define GO_MOVEREPEATEXCEPTION_H

#include <exception>

namespace Go {

class MoveRepeatException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't make a move that repeats your previous!!!";
  }
};

}

#endif //GO_MOVEREPEATEXCEPTION_H
