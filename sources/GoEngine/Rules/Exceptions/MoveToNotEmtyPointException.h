#ifndef GO_MOVETONOTEMTYPOINTEXCEPTION_H
#define GO_MOVETONOTEMTYPOINTEXCEPTION_H

#include "MoveException.h"

/**
 * Исключение - ход в несвободный пункт.
 * Выбрасывается, когда игрок ходит в несвободный пункт.
 */
class MoveToNotEmptyPointException : public MoveException
{

public:

    /**
     * Чё?
     * @return сообщение о том, что игрок совершил ход в несвободный пункт
     */
    const char* what() const noexcept
    {
        return "You moved to not empty point";
    }

};

#endif //GO_MOVETONOTEMTYPOINTEXCEPTION_H
