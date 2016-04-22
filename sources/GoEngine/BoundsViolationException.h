#ifndef GO_BOUNDSVIOLATIONEXCEPTION_H
#define GO_BOUNDSVIOLATIONEXCEPTION_H

#include <exception>

/**
 * Исключение - выход за границы доски.
 * Данное исключение возбуждается при выходе за границы доски
 */
class BoundsViolationException : public std::exception
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

#endif //GO_BOUNDSVIOLATIONEXCEPTION_H
