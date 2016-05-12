#ifndef GO_GOENGINEINTERFACE_H
#define GO_GOENGINEINTERFACE_H

#include "Rules/GameProcess.h"

/**
 * Интерфейс, предоставляемый движком приложению.
 * Суперкласс для API
 */
class GoEngineInterface
{
public:

    /**
     * Деструктор.
     */
    virtual ~GoEngineInterface() noexcept {}

    /**
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param go присваиваемый объект
     * @return ссылку на объект
     */
    GoEngineInterface& operator=( const GoEngineInterface& go ) noexcept;

    /**
     * Начать игру.
     * Начинает игру в соответствии с параметрми, заданными аргументами.
     * @param diagonal диагональ
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    //todo использовать enum как тип
    //Rules rules
    virtual void startGame( const int diagonal, const int rules, const int colorDistribution ) noexcept = 0;

    /**
     * Положить камень в выбранный пункт.
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     */
    virtual void putStone( const int first, const int second ) = 0;

    /**
     * Пропустить ход.
     */
    virtual void pass() noexcept = 0;

    /**
     * Сдаться.
     */
    virtual void surrender() noexcept = 0;

    /**
     * Чей ход?
     * @return цвет игрока, чей сейчас ход
     */
    virtual Status whoseMove() const noexcept = 0;

    /**
     * Игра закончена?
     * @return true, если игра закончена, и false, если игра не закончена
     */
    virtual bool isGameOver() const noexcept = 0;

    /**
     * Кто сдался?
     * @return цвет игрока, который сдался
     */
    virtual Status whoSurrendered() const noexcept = 0;

    /**
     * Кто победил?
     * @return цвет победителя
     */
    virtual Status whoWon() const noexcept = 0;

    /**
     * Получить диагональ.
     * @return диагональ
     */
    virtual int getDiagonal() const noexcept = 0;

    /**
     * Получить статус first, second - го пункта доски.
     */
    virtual Status getPointsStatus( const int first, const int second ) const noexcept = 0;

    /**
     * Получить число камней, съеденных чёрным.
     * @return число камней, съеденных чёрным
     */
    virtual int getStonesEatenByBlack() const noexcept = 0;

    /**
     * Получить число камней, съеденных белым.
     * @return число камней, съеденных белым
     */
    virtual int getStonesEatenByWhite() const noexcept = 0;

    /**
     * Получить индекс хода.
     * @return индекс хода
     */
    virtual int getMoveIndex() const noexcept = 0;

    /**
     * Получить вектор ходов.
     * @return ссылку на вектор ходов.
     */
    virtual std::vector<Move>& getMoves() const noexcept = 0;

    /**
     * Получить последний совершённый ход.
     * @return ссылку на последний совершённый ход.
     */
    virtual Move& getLastMove() const noexcept = 0;

    /**
     * Получить предпоследний совершённый ход.
     * @return ссылку на предпоследний совершённый ход
     */
    virtual Move& getPenultMove() const noexcept = 0;

    /**
     * Получить очки чёрного.
     * @return очки чёрного
     */
    virtual int getBlackScore() const noexcept = 0;

    /**
     * Получить очки белого.
     * @return очки белого
     */
    virtual int getWhiteScore() const noexcept = 0;

};


#endif //GO_GOENGINEINTERFACE_H
