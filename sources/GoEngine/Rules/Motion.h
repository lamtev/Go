#ifndef GO_MOTION_H
#define GO_MOTION_H

#include <vector>
#include <algorithm>

#include "../Board.h"
#include "Move.h"
#include "../enums.h"
#include "Exceptions/MoveRepeatException.h"
#include "Exceptions/MoveToDieException.h"
#include "Exceptions/MoveToNotEmtyPointException.h"

using std::vector;

//TODO

/**
 * Процесс хода.
 * Контролирует правильность совершения ходов
 */
class Motion
{
public:

    /**
     * Конструктор
     */
    Motion() noexcept;

    /**
     * Положить камень
     */
    void putStone( Board* board, int first, int second );

    /**
     * Пропустить ход
     */
    void pass() noexcept;

    /**
     * Сдаться.
     */
    void surrender() noexcept;

    /**
     * Игра закончена?
     * @return true, если игра закончилась, и false - в противном случае
     */
    bool isGameOver() const noexcept;

    /**
     * Кто сдался?
     * @return цвет сдавшегося.
     */
    int whoSurrendered() const noexcept;

    /**
     * Кто победил?
     * @return цвет победителя.
     */
    int whoWon() const noexcept;

    /**
     * Получить номер текущего хода.
     * @return номер текущего хода
     */
    int getMoveIndex() const noexcept;

    /**
     * Получить вектор всех ходов.
     * @return вектор всех ходов
     */
    vector<Move>& getMoves() const noexcept;

    /**
     * Чей ход?
     * @return цвет игрока, чей сейчас ход
     */
    int whoseMove() const noexcept;

    /**
     * Получить число камней, съеденных чёрным.
     * @return число камней, съеденных чёрным
     */
    int getStonesEatenByBlack() const noexcept;

    /**
     * Получить число камней, съеденных белым.
     * @return число камней, съеденных белым
     */
    int getStonesEatenByWhite() const noexcept;

    /**
     * Получить последний совершённый ход.
     * @return ссылка на последний совершённый ход.
     */
    Move& getLastMove() const noexcept;

private:

    vector<Move> moves; /**< Вектор, хранящий все ходы */
    int moveIndex; /**< Индекс ходов */
    int movesSize = 100;  /**< Размер вектора ходов */
    int surrendered = EMPTY; /**< Сдавшийся */
    int stonesEatenByBlack = 0; /**< Число камней, съеденных чёрным */
    int stonesEatenByWhite = 0; /**< Число камней, съеденных белым */

    /**
     * Проверка двух последних ходов на пропуск.
     * @return true, если оба игрока пропустили поочередно ход
     */
    bool areTwoPasses() const noexcept;

    /**
     * Изменить размер вектора moves.
     * Увеличивает размер вектора moves на 100, если есть необходимость.
     */
    void ifNeedResizeMoves() noexcept;

    /**
     * Ход чёрных?
     * @return true, если ход чёрных, и false - в противном случае
     */
    bool isBlacksMove() const noexcept;

    /**
     * Если ход за пределы доски бросить исключение.
     * Данная функция-член выбрасывает исключение, если игрок совершает ход за пределы доски.
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveOutsideTheBoardThrowException( Board* board, int first, int second ) const;

    /**
     * Если ход в занятый пункт бросить исключение.
     * Данная функция-член выбрасывает исключение, если игрок совершает ход в уже занятый пункт.
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveToNotEmptyPointThrowException( Board* board, int first, int second ) const;

    /**
     * Если повтор хода бросить исключение.
     * Данный метод выбрасывает исключение, если игрок повторил свой предыдущий ход
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveRepeatThrowException( int first, int second ) const;

    /**
     * Если ход под смерть бросить исключение.
     * Данный метод выбрасывает исключение, если ход совершается под смерть
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveToDieThrowException( Board* board, int first, int second ) const;

    /**
     * Проверка легитимности хода.
     * @param board указатель на объект доски
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveIllegalThrowException( Board* board, int first, int second ) const;

};


#endif //GO_MOTION_H
