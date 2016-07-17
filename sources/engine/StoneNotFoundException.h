#ifndef GO_STONENOTFOUNDEXCEPTION_H
#define GO_STONENOTFOUNDEXCEPTION_H

#include <exception>

namespace Go {

class StoneNotFoundException: public std::exception {
 public:
  const char *what() const noexcept override {

    return "There is no stone in the point";
  }
};

}

#endif //GO_STONENOTFOUNDEXCEPTION_H
