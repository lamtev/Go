#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>

#include "../Rules/GameProcess.h"

/**
 * Интерфейс движка, предоставляемый приложению
 */
class GoEngineInterface
{

public:

    /**
     * Конструктор.
     */
    GoEngineInterface() noexcept;

    /**
     * Начать игру.
     * Начинает игру в соответствии с параметрми, заданными аргументами.
     * @param diagonal диагональ
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    void startGame( const int diagonal, const int rules, const int colorDistribution ) noexcept;

    /**
     * Деструктор.
     */
    ~GoEngineInterface();

    /**
     * Положить камень в выбранный пункт.
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     */
    void putStone( const int first, const int second );

    /**
     * Пропустить ход.
     */
    void pass() noexcept;

    /**
     * Сдаться.
     */
    void surrender() noexcept;

    /**
     * Чей ход?
     * @return цвет игрока, чей сейчас ход
     */
    int whoseMove() const noexcept;

    /**
     * Игра закончена?
     * @return true, если игра закончена, и false, если игра не закончена
     */
    bool isGameOver() const noexcept;

    /**
     * Кто сдался?
     * @return цвет игрока, который сдался
     */
    int whoSurrendered() const noexcept;

    /**
     * Кто победил?
     * @return цвет победителя
     */
    int whoWon() const noexcept;

    /**
     * Получить диагональ.
     * @return диагональ
     */
    int getDiagonal() const noexcept;

    /**
     * Получить статус i,j - го пункта доски.
     */
    int getIJPointsStatus( const int i, const int j ) const noexcept;

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
     * Получить вектор ходов.
     * @return ссылку на вектор ходов.
     */
    std::vector<Move>& getMoves() const noexcept;

    /**
     * Получить последний совершённый ход.
     * @return ссылку на последний совершённый ход.
     */
    Move& getLastMove() const noexcept;

    /**
     * Получить очки чёрного.
     * @return очки чёрного
     */
    int getBlackScore() const noexcept;

    /**
     * Получить очки белого.
     * @return очки белого
     */
    int getWhiteScore() const noexcept;

private:

    GameProcess* gameProcess; /**< Указатель на объект процесса ходов */

};

#endif // GOENGINEINTERFACE_H
