#ifndef GO_BOUNDSVIOLATIONEXCEPTION_H
#define GO_BOUNDSVIOLATIONEXCEPTION_H

#include <exception>

/**
 * Класс-исключение выход за границы доски.
 * Данное исключение возбуждается при выходе за границы доски
 */
class BoundsViolationException : public std::exception
{
public:

    /**
     * Чё?
     * Данный метод возвращает строку с записью о том, что
     * произошёл выход за пределы доски
     */
    const char* what() const noexcept
    {
        return "Board bounds violation";
    }

};

#endif //GO_BOUNDSVIOLATIONEXCEPTION_H
