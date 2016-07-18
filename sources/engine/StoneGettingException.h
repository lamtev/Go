#ifndef GO_STONEGETTINGEXCEPTION_H
#define GO_STONEGETTINGEXCEPTION_H

#include <exception>

namespace Go {

class StoneGettingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't get stone: it's not found!";
  }
};

}

#endif //GO_STONEGETTINGEXCEPTION_H
