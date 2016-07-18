#ifndef GO_STONESETTINGEXCEPTION_H
#define GO_STONESETTINGEXCEPTION_H

#include <exception>

namespace Go {

class StoneSettingException: public std::exception {
 public:
  const char *what() const noexcept override {
    return "Can't set stone: it's already set!";
  }
};

}

#endif //GO_STONESETTINGEXCEPTION_H
