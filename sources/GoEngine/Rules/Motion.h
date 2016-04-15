#ifndef GO_MOTION_H
#define GO_MOTION_H

#include <vector>

#include "../Board.h"
#include "Moves.h"
#include "../enums.h"
#include "MoveRepeatException.h"
#include "MoveBeyondBoardException.h"
#include "MoveToDieException.h"

using std::vector;

//TODO

/**
 * Процесс хода
 * Контролирует правильность совершения ходов
 */
class Motion
{
public:

    /**
     * Конструктор
     */
    Motion();

    /**
     * Положить камень
     */
    void putStone( Board* board, int first, int second );

    /**
     * Пропустить ход
     */
    void pass() noexcept;

    /**
     * Проверка двух последних ходов на пропуск
     * @return true, если оба игрока пропустили поочередно ход
     */
    bool areTwoPasses() const noexcept;

private:

    vector<Moves> moves; /**< Вектор, хранящий все ходы */
    int motionIndex; /**< Индекс ходов */

    /**
     * Ход чёрных?
     * @return true, если ход чёрных, и false - в противном случае
     */
    bool isBlacksMove() const noexcept;

    /**
     * Чей ход?
     * @return цвет игрока, чей сейчас ход
     */
    int whoseMove() const noexcept;

    /**
     * Повтор хода?
     * Данный метод выбрасывает исключение, если игрок повторил свой предыдущий ход
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveRepeat( Board* board, int first, int second ) const;

    /**
     * Ход за пределы доски?
     * Данный метод выбрасывает исключение, если ход совершается за пределы доски
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveBeyondBoard( Board* board, int first, int second ) const;

    /**
     * Ход под самоубийство?
     * Данный метод выбрасывает исключение, если ход совершается под самоубийство
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveToDie( Board* board, int first, int second ) const;

    /**
     * Проверка легитимности хода
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveIllegal( Board* board, int first, int second ) const;

};


#endif //GO_MOTION_H
