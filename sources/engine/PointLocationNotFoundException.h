#ifndef GO_POINTLOCATIONNOTFOUNDEXCEPTION_H
#define GO_POINTLOCATIONNOTFOUNDEXCEPTION_H

#include <exception>

namespace Go {

class PointLocationNotFoundException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Current move type does not have point location";
  }
};

}

#endif //GO_POINTLOCATIONNOTFOUNDEXCEPTION_H
