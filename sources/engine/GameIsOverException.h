#ifndef GO_GAMEISOVEREXCEPTION_H
#define GO_GAMEISOVEREXCEPTION_H

#include <exception>

class GameIsOverException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Game is over!!!";
  }
};


#endif //GO_GAMEISOVEREXCEPTION_H
