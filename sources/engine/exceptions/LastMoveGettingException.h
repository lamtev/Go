#ifndef GO_LASTMOVEGETTINGEXCEPTION_H
#define GO_LASTMOVEGETTINGEXCEPTION_H

#include <exception>

class LastMoveGettingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't get last move: moves list is empty!";
  }
};


#endif //GO_LASTMOVEGETTINGEXCEPTION_H
