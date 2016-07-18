#ifndef GO_LASTMOVEPOPPINGEXCEPTION_H
#define GO_LASTMOVEPOPPINGEXCEPTION_H

#include <exception>

class LastMovePoppingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't pop last move: moves list is empty!";
  }
};


#endif //GO_LASTMOVEPOPPINGEXCEPTION_H
