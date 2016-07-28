#ifndef GO_POINTLOCATIONGETTINGEXCEPTION_H
#define GO_POINTLOCATIONGETTINGEXCEPTION_H

#include <exception>

namespace Go {

class PointLocationGettingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't get point location: current move type does't have it!";
  }
};

}

#endif //GO_POINTLOCATIONGETTINGEXCEPTION_H
