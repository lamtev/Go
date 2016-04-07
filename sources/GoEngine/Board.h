#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>
#include <cmath>

#include "BoundsViolationException.h"
#include "IncorrectDiagonalException.h"

using std::vector;

//TODO noecept swap
//TODO high performance operator=

/**
 *
 */
class Board
{
public:
    /**
     * Конструктор.
     * Конструктор для инициализации объекта по значению диагонали
     * @param diagonal диагональ
     */
    Board( int diagonal );
    /**
     * Конструктор.
     * Конструктор для инициализации объекта по массиву, содержащему расстановку камней
     * @param board массив для инициализации
     */
    Board( const vector<int>& board );
    /**
     * Оператор скобки.
     * Используется как оператор индексирования.
     * @param i координата по строкам
     * @param j координата по столбцам
     */
    int& operator()( const int i, const int j );
    /**
     * Получить диагональ.
     * Метод возвращает значение диагонали
     */
    int getDiagonal() const noexcept;
    /**
     * Оператор присваивания.
     * Перегруженный оператор присваивания.
     * @param board присваиваемый вектор
     * @return Board&
     */
    Board& operator=( const vector<int>& board ) noexcept;

private:
    /**
     * Поле диагональ
     */
    int diagonal;
    /*
     * Поле доска
     */
    vector<int> board;
};


#endif //GO_BOARD_H
