#ifndef GO_MOVETODIEEXCEPTION_H
#define GO_MOVETODIEEXCEPTION_H

#include <exception>

/**
 * Исключение - ход под смерть.
 * Выбрасывается, когда игрок ходит под смерть своего камня или группы
 */
class MoveToDieException : public std::exception
{
public:

    /**
     * Чё?
     * @return сообщение о том, что игрок ходит под смерть
     */
    const char* what()
    {
        return "You moved to die";
    }
};

#endif //GO_MOVETODIEEXCEPTION_H
