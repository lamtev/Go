#ifndef GO_LASTMOVENOTFOUNDEXCEPTION_H
#define GO_LASTMOVENOTFOUNDEXCEPTION_H

#include <exception>

class LastMoveNotFoundException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Penult move not found";
  }
};


#endif //GO_LASTMOVENOTFOUNDEXCEPTION_H
