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
 * Доска.
 */
class Board
{
public:
    /**
     * Конструктор.
     * Конструктор для инициализации объекта по значению диагонали
     * @param diagonal диагональ
     */
    Board( int diagonal = 19 );

    /**
     * Оператор скобки.
     * Используется как оператор индексирования.
     * @param i координата по строкам
     * @param j координата по столбцам
     */
    Stone& operator()( const int i, const int j );
    /**
     * Получить диагональ.
     * Метод возвращает значение диагонали
     */
    int getDiagonal() const noexcept;

    /**
     * Оператор присваивания.
     * Перегруженный оператор присваивания.
     * @param board присваиваемая доска
     * @return Board&
     */
    Board& operator=( const Board& board ) noexcept;
private:
    /**
     * Поле диагональ
     */
    int diagonal;
    /*
     * Поле доска
     */
    vector<Stone> board;
};


#endif //GO_BOARD_H
