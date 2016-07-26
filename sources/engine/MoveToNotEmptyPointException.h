#ifndef GO_MOVETONOTEMPTYPOINTEXCEPTION_H
#define GO_MOVETONOTEMPTYPOINTEXCEPTION_H

#include <exception>

namespace Go {

class MoveToNotEmptyPointException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't make a move to not empty point!!!";
  }
};

}

#endif //GO_MOVETONOTEMPTYPOINTEXCEPTION_H
