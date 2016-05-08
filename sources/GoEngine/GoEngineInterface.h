#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>

#include "Rules/GameProcess.h"

//todo может выделить интерфейс в отдельный класс и наследовать вот это от него
//todo также нельзя назвыть данный класс интерфейсом (в интерфейсе не должено быть реализации чего-либо)
//при данной реализации такой необходимости, конечно, нет
//но все же лучше придерживаться некой структуры

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
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param go присваиваемый объект
     * @return ссылку на объект
     */
    //todo а нужен он? оператор этот. зачем игру дублировать?
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
    //todo first second вводят в заблуждение...
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
    //todo везду first second, а тут i и j. Лучше везде одинаково.
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
     * Получить индекс хода.
     * @return индекс хода
     */
    int getMoveIndex() const noexcept;

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
     * Получить предпоследний совершённый ход.
     * @return ссылку на предпоследний совершённый ход
     */
    Move& getPenultMove() const noexcept;

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
