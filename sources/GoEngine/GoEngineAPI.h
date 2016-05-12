#ifndef GOENGINEAPI_H
#define GOENGINEAPI_H

#include <string>

#include "GoEngineInterface.h"

/**
 * API
 */
class GoEngineAPI : public GoEngineInterface
{

public:

    /**
     * Конструктор.
     */
    GoEngineAPI() noexcept;

    /**
     * Деструктор.
     */
    ~GoEngineAPI() noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param go присваиваемый объект
     * @return ссылку на объект
     */
    GoEngineAPI& operator=( const GoEngineAPI& go ) noexcept;

    /**
     * Начать игру.
     * Начинает игру в соответствии с параметрми, заданными аргументами.
     * @param diagonal диагональ
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    //todo использовать enum как тип
    //Rules rules
    void startGame( const int diagonal, const int rules, const int colorDistribution ) noexcept override;


    /**
     * Положить камень в выбранный пункт.
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     */
    void putStone( const int first, const int second ) override;

    /**
     * Пропустить ход.
     */
    void pass() noexcept override;

    /**
     * Сдаться.
     */
    void surrender() noexcept override;

    /**
     * Чей ход?
     * @return цвет игрока, чей сейчас ход
     */
    Status whoseMove() const noexcept override;

    /**
     * Игра закончена?
     * @return true, если игра закончена, и false, если игра не закончена
     */
    bool isGameOver() const noexcept override;

    /**
     * Кто сдался?
     * @return цвет игрока, который сдался
     */
    Status whoSurrendered() const noexcept override;

    /**
     * Кто победил?
     * @return цвет победителя
     */
    Status whoWon() const noexcept override;

    /**
     * Получить диагональ.
     * @return диагональ
     */
    int getDiagonal() const noexcept override;

    /**
     * Получить статус first, second - го пункта доски.
     */
    Status getPointsStatus( const int first, const int second ) const noexcept override;

    /**
     * Получить число камней, съеденных чёрным.
     * @return число камней, съеденных чёрным
     */
    int getStonesEatenByBlack() const noexcept override;

    /**
     * Получить число камней, съеденных белым.
     * @return число камней, съеденных белым
     */
    int getStonesEatenByWhite() const noexcept override;

    /**
     * Получить индекс хода.
     * @return индекс хода
     */
    int getMoveIndex() const noexcept override;

    /**
     * Получить вектор ходов.
     * @return ссылку на вектор ходов.
     */
    std::vector<Move>& getMoves() const noexcept override;

    /**
     * Получить последний совершённый ход.
     * @return ссылку на последний совершённый ход.
     */
    Move& getLastMove() const noexcept override;

    /**
     * Получить предпоследний совершённый ход.
     * @return ссылку на предпоследний совершённый ход
     */
    Move& getPenultMove() const noexcept override;

    /**
     * Получить очки чёрного.
     * @return очки чёрного
     */
    int getBlackScore() const noexcept override {};

    /**
     * Получить очки белого.
     * @return очки белого
     */
    int getWhiteScore() const noexcept override {};

private:

    GameProcess* gameProcess; /**< Указатель на объект процесса ходов */

};

#endif // GOENGINEAPI_H
