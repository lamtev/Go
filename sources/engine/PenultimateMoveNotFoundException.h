#ifndef GO_PENULTIMATEMOVENOTFOUNDEXCEPTION_H
#define GO_PENULTIMATEMOVENOTFOUNDEXCEPTION_H

#include <exception>

class PenultimateMoveNotFoundException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Penultimate move not found";
  }
};


#endif //GO_PENULTIMATEMOVENOTFOUNDEXCEPTION_H
