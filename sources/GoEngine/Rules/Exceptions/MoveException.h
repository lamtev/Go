#ifndef GO_MOVEEXCEPTION_H
#define GO_MOVEEXCEPTION_H

#include <exception>

/**
 * Супер-класс для всех классов исключений, связанных с ходом.
 */
class MoveException : public std::exception
{

public:

    /**
     * Виртуальный деструктор.
     */
    virtual ~MoveException(){};

    /**
     * Виртуальный "Чё?"
     * @return сообщение об ошибке
     */
    virtual const char* what() const noexcept = 0;

};

#endif //GO_MOVEEXCEPTION_H
