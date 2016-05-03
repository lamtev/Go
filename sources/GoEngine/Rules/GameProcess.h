#ifndef GO_GAMEPROCESS_H
#define GO_GAMEPROCESS_H

#include <vector>

#include "../Model/Board.h"
#include "Move.h"
#include "Exceptions/MoveOutsideTheBoardException.h"
#include "Exceptions/MoveRepeatException.h"
#include "Exceptions/MoveToDieException.h"
#include "Exceptions/MoveToNotEmtyPointException.h"

//TODO реализовать съедение

/**
 * Процесс хода.
 * Cледит за тем, чтобы ходы выполнялись в соответствии с правилами.
 * Определяет очерёдность ходов. Определяет победителя и проигравшего.
 */
class GameProcess
{
    
public:

    /**
     * Конструктор.
     */
    GameProcess( const int diagonal ) noexcept;

    /**
     * Деструктор.
     */
    ~GameProcess() noexcept;

    /**
     * Положить камень.
     */
    void putStone( int first, int second );

    /**
     * Пропустить ход.
     * @param first первая координата
     * @param second вторая координата
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
    std::vector<Move>& getMoves() const noexcept;

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

    /**
     * Получить доску.
     * @return доску
     */
    Board& getBoard() const noexcept;

private:

    int diagonal; /**< Диагональ доски */
    Board* board; /**< Доска */
    std::vector<Move> moves; /**< Вектор, хранящий все ходы */
    int moveIndex; /**< Индекс ходов */
    int movesSize;  /**< Размер вектора ходов */
    int surrendered; /**< Сдавшийся */
    int winner; /**< Победитель */
    int stonesEatenByBlack; /**< Число камней, съеденных чёрным */
    int stonesEatenByWhite; /**< Число камней, съеденных белым */
    const Move passedMove{ PASS_COORD, PASS_COORD }; /**< Пропущенный ход */

    /**
     * Проверка двух последних ходов на пропуск.
     * @return true, если оба игрока пропустили поочередно ход, false - в противном случае
     */
    bool areTwoPasses() const noexcept;

    /**
     * Ход чёрных?
     * @return true, если ход чёрных, и false - в противном случае
     */
    bool isBlacksMove() const noexcept;

    /**
     * Изменить размер вектора moves.
     * Увеличивает размер вектора moves на 100, если есть необходимость.
     */
    void ifNeedResizeMoves() noexcept;

    /**
     * Убрать съеденные камни с доски.
     */
    void removeEatenStones() noexcept;

    /**
     * Если ход за пределы доски, бросить исключение.
     * Данная функция-член выбрасывает исключение, если игрок совершает ход за пределы доски.
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveOutsideTheBoardThrowException( int first, int second ) const;

    /**
     * Если ход в занятый пункт, бросить исключение.
     * Данная функция-член выбрасывает исключение, если игрок совершает ход в уже занятый пункт.
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveToNotEmptyPointThrowException( int first, int second ) const;

    /**
     * Если повтор хода, бросить исключение.
     * Данный метод выбрасывает исключение, если игрок повторил свой предыдущий ход
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveRepeatThrowException( int first, int second ) const;

    /**
     * Если ход под смерть, бросить исключение.
     * Данный метод выбрасывает исключение, если ход совершается под смерть
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveToDieThrowException( int first, int second ) const;

    /**
     * Если ход неверен, бросить исключение.
     * @param first первая координата
     * @param second вторая координата
     */
    void ifMoveIllegalThrowException( int first, int second ) const;

};


#endif //GO_GAMEPROCESS_H
