#ifndef GO_MOVEBEYONDBOARDEXCEPTION_H
#define GO_MOVEBEYONDBOARDEXCEPTION_H

#include <exception>

/**
 * Исключение - ход за пределы доски
 * Выбрасывается, когда ход совершается на пункт вне доски
 */
class MoveBeyondBoardException : public std::exception
{
public:

    /**
     * Чё?
     * @return сообщение о том, что выбранный пункт вне доски
     */
    const char* what()
    {
        return "Chosen point is out of board";
    }
};

#endif //GO_MOVEBEYONDBOARDEXCEPTION_H
