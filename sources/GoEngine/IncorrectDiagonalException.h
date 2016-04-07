#ifndef GO_INCORRECTDIAGONALEXCEPTION_H
#define GO_INCORRECTDIAGONALEXCEPTION_H

#include <exception>

/**
 * Класс-исключение неправильная диагональ.
 * Данное исключение возбуждается, когда инициализируется объект доски неверным значением диагонали.
 */
class IncorrectDiagonalException : public std::exception
{
public:
    /**
     * Конструктор.
     */
    IncorrectDiagonalException( const int diagonal ) : diagonal(diagonal){}
    /**
     * Получить диагональ.
     * Этот метод возвращает значение неверной диагонали.
     */
    const int getDiagonal() const noexcept
    {
        return diagonal;
    }
private:
    /**
     * Поле диагональ.
     */
    const int diagonal;
};

#endif //GO_INCORRECTDIAGONALEXCEPTION_H
