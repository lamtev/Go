#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>

#include "Point.h"

//TODO noexcept swap
//TODO high performance operator=

/**
 * Игровая доска
 */
class Board
{

public:

    /**
     * Конструктор.
     * @param diagonal диагональ
     */
    explicit Board( const int diagonal = 19 ) noexcept;

    /**
     * Оператор скобки.
     * Используется в качестве оператора индексирования.
     * @param first первая координата
     * @param second вторая координата
     * @return ссылку на объект
     */
    Point& operator()( const int first, const int second ) noexcept;

    /**
    * Оператор присваивания.
    * Перегруженный оператор присваивания
    * @param board ссылка на присваиваемый константный объект
    * @return ссылку на объект
    */
    Board& operator=( const Board& board ) noexcept;

    /**
     * Получить диагональ.
     * @return значение диагонали
     */
    int getDiagonal() const noexcept;

    /**
     * Получить вектор доски.
     * return вектор доски
     */
    std::vector<Point>& get() const noexcept;

private:

    int diagonal; /**< Диагональ */
    std::vector<Point> board; /**< Вектор, хранящий пункты доски */

};

#endif //GO_BOARD_H
