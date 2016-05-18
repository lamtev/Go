#ifndef GO_MOVETODIEEXCEPTION_H
#define GO_MOVETODIEEXCEPTION_H

#include "MoveException.h"

/**
 * Исключение - ход под смерть.
 * Выбрасывается, когда игрок ходит под смерть своего камня или группы
 */
class MoveToDieException: public MoveException {

 public:

  /**
   * Чё?
   * @return сообщение о том, что игрок ходит под смерть
   */
  const char *what() const noexcept override {
    return "You moved to die";
  }

};

#endif //GO_MOVETODIEEXCEPTION_H
