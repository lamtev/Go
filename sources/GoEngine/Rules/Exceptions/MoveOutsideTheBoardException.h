#ifndef GO_MOVEOUTSIDETHEBOARDEXCEPTION_H
#define GO_MOVEOUTSIDETHEBOARDEXCEPTION_H

#include "MoveException.h"

/**
 * Исключение - выход за границы доски.
 * Данное исключение возбуждается при выходе за границы доски
 */
class MoveOutsideTheBoardException : public MoveException
{
public:

    /**
     * Чё?
     * @return сообщение о том, что произошёл выход за пределы доски
     */
    const char* what() const noexcept
    {
        return "You moved outside the board";
    }

};

#endif //GO_MOVEOUTSIDETHEBOARDEXCEPTION_H
