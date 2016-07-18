#ifndef GO_EMPTYMOVESLISTEXCEPTION_H
#define GO_EMPTYMOVESLISTEXCEPTION_H

#include <exception>

class EmptyMovesListException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Moves list is empty";
  }
};


#endif //GO_EMPTYMOVESLISTEXCEPTION_H
