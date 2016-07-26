#ifndef GO_MOVETODIEEXCEPTION_H
#define GO_MOVETODIEEXCEPTION_H

#include <exception>

namespace Go {

class MoveToDieException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Cant make a move to die!!!";
  }
};

}

#endif //GO_MOVETODIEEXCEPTION_H
