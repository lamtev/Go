#ifndef GO_GAMEPROCESS_H
#define GO_GAMEPROCESS_H

#include "../Model/Board.h"
#include "Move.h"
#include "Exceptions/MoveOutsideTheBoardException.h"
#include "Exceptions/MoveRepeatException.h"
#include "Exceptions/MoveToDieException.h"
#include "Exceptions/MoveToNotEmtyPointException.h"

//TODO реализовать съедение

/**
 * Игровой процесс.
 * Cледит за тем, чтобы ходы выполнялись в соответствии с правилами.
 * Определяет очерёдность ходов. Определяет победителя и проигравшего.
 */
class GameProcess
{
    
public:

    /**
     * Конструктор.
     */
    explicit GameProcess( const int diagonal ) noexcept;


    /**
     * Деструктор.
     */
    ~GameProcess() noexcept;

    /**
     * Чей ход?
     * @return цвет игрока, чей сейчас ход
     */
    //todo может быть и тут использовать enum для цвета
    int whoseMove() const noexcept;

    /**
     * Положить камень.
     * @param first первая координата
     * @param second вторая координата
     */
    void putStone( int first, int second );

    /**
     * Пропустить ход.
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
    //todo может быть и тут использовать enum для цвета
    int whoSurrendered() const noexcept;

    /**
     * Кто победил?
     * @return цвет победителя.
     */
    //todo может быть и тут использовать enum для цвета
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
     * Получить последний совершённый ход.
     * @return ссылка на последний совершённый ход.
     */
    Move& getLastMove() const noexcept;

    /**
     * Получить предпоследний совершённых ход.
     * @return ссылка на последний совершённый ход
     */
    Move& getPenultMove() const noexcept;

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
     * Получить доску.
     * @return доску
     */
    Board& getBoard() const noexcept;

private:

    int diagonal; /**< Диагональ доски */
    Board* board; /**< Доска */
    int movesSize;  /**< Размер вектора ходов */
    int moveIndex; /**< Индекс ходов */
    std::vector<Move> moves; /**< Вектор, хранящий все ходы */
    //todo использовать enum как тип
    int surrendered; /**< Сдавшийся */
    //todo использовать enum как тип
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
    //todo может не использовать if в названии?
    //todo лучше не заниматься самостоятельным выделением памяти
    // в реализации вектора большие бородатые дяденьки, наверно, всю голову сломали,
    // пока думали как эффеиктивно память выделять, понаписали кучу аллокаторов...
    void ifNeedResizeMoves() noexcept;
    //возможно лучше просто resizeMoves() все равно метод вызывается постоянно... if награмождает
    //хотя, здесь подумать надо... сложно что то...

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
