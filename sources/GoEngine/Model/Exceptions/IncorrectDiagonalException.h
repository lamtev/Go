#ifndef GO_INCORRECTDIAGONALEXCEPTION_H
#define GO_INCORRECTDIAGONALEXCEPTION_H

#include <exception>

/**
 * Исключение - неправильная диагональ
 * Данное исключение возбуждается, когда инициализируется объект доски
 * непредусмотренным(неправильным) значением диагонали
 */
class IncorrectDiagonalException: public std::exception {

 public:

  /**
   * Чё?
   * @return сообщение о том, что значение длины диагонали неверно
   */
  const char *what() const noexcept {
    return "Wrong diagonal";
  }

};

#endif //GO_INCORRECTDIAGONALEXCEPTION_H
