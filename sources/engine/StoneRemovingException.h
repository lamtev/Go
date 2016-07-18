#ifndef GO_STONEREMOVINGEXCEPTION_H
#define GO_STONEREMOVINGEXCEPTION_H

#include <exception>

namespace Go {

class StoneRemovingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't remove stone: it's already removed!";
  }
};

}

#endif //GO_STONEREMOVINGEXCEPTION_H
