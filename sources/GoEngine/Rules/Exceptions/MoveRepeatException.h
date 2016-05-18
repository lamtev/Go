#ifndef GO_MOVEREPEATEXCEPTION_H
#define GO_MOVEREPEATEXCEPTION_H

#include "MoveException.h"

/**
 * Исключение - повтор хода.
 * Данное исключение выбрасывается, когда игрок текущим ходом повторил свой предыдущий ход
 */
class MoveRepeatException: public MoveException {

 public:

  /**
   * Чё?
   * @return сообщение о том, что игрок текущим ходом повторил свой предыдущий ход
   */
  const char *what() const noexcept override {
    return "This move is the same as your previous one";
  }

};

#endif //GO_MOVEREPEATEXCEPTION_H
