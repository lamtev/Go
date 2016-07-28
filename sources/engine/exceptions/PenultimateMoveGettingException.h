#ifndef GO_PENULTIMATEMOVEGETTINGEXCEPTION_H
#define GO_PENULTIMATEMOVEGETTINGEXCEPTION_H

#include <exception>

class PenultimateMoveGettingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't get penultimate move: it's not found!";
  }
};


#endif //GO_PENULTIMATEMOVEGETTINGEXCEPTION_H
