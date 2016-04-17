#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>

#include "Stone.h"
#include "Rules/Moves.h"

#include "BoundsViolationException.h"
#include "IncorrectDiagonalException.h"

using std::vector;

//TODO noexcept swap
//TODO high performance operator=

/**
 * Доска
 */
class Board
{
public:

    /**
     * Конструктор.
     * Конструктор для инициализации объекта по значению диагонали
     * @param diagonal длина диагонали
     */
    Board( int diagonal = 19 );

    /**
     * Получить диагональ.
     * @return значение диагонали
     */
    int getDiagonal() const noexcept;

    /**
     * Получить вектор доски.
     * return вектор доски
     */
    vector<Stone>& get() const noexcept;

    /**
     * Оператор скобки.
     * Используется как оператор индексирования
     * @param i координата по строкам
     * @param j координата по столбцам
     * @return ссылку на объект данного класса
     */
    Stone& operator()( const int i, const int j );

    /**
     * Оператор присваивания.
     * Перегруженный оператор присваивания
     * @param board присваиваемая доска
     * @return ссылку на объект данного класса
     */
    Board& operator=( const Board& board ) noexcept;

    Moves& f();

private:

    int diagonal; /**< длина диагонали */
    vector<Stone> board; /**< вектор, реализующий модель доски */

    /**
     * Получить первую и вторую координату пункта.
     * Получить первую и вторую координату пункта по индексу вектора.
     */
    void getFirstAndSecond( int vectorIndex, int& first, int& second ) const noexcept;
};


#endif //GO_BOARD_H
