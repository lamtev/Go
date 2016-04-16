#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>

#include "Stone.h"

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
     * Оператор скобки.
     * Используется как оператор индексирования
     * @param i координата по строкам
     * @param j координата по столбцам
     * @return ссылку на объект данного класса
     */
    Stone& operator()( const int i, const int j );

    /**
     * Получить диагональ.
     * @return значение диагонали
     */
    int getDiagonal() const noexcept;

    vector<Stone>& get() const noexcept;

    /**
     * Оператор присваивания.
     * Перегруженный оператор присваивания
     * @param board присваиваемая доска
     * @return ссылку на объект данного класса
     */
    Board& operator=( const Board& board ) noexcept;

private:

    int diagonal; /**< длина диагонали */
    vector<Stone> board; /**< вектор, реализующий модель доски */

};


#endif //GO_BOARD_H
