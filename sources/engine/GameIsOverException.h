#ifndef GO_GAMEISOVEREXCEPTION_H
#define GO_GAMEISOVEREXCEPTION_H

#include <exception>

class GameIsOverException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't make a move because game is over!!!";
  }
};


#endif //GO_GAMEISOVEREXCEPTION_H
