#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>

#include "Board.h"
#include "enums.h"

//TODO

/**
 * Класс, предоставляющий интерфейс движка приложению.
 */
class GoEngineInterface
{
public:

    /**
     * Начать игру.
     *
     * Этот метод начинает игру с параметрами, заданными конфигурационным файлом.
     * @param config конфигурационный файл
     */
    void startGame( const std::string& config );

    /**
     * Начать игру.
     *
     * Этот метод начинает игру с параметрами, заданными его аргументами.
     * @param diagonal диагональ игровой доски
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    void startGame( const int diagonal, const int rules, const int colorDistribution );
    /**
     * Получить доску.
     *
     * Данный метод возвращает доску.
     * @return Board
     */
    Board getBoard() const noexcept;

    /**
     * Положить камень в выбранный пункт.
     *
     * Данный метод позволяет игроку положить его иговой камень в пункт доски.
     * @param color цвет игрока
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     * @return доска
     */
    void putStone( const int color, const int first, const int second );

    /**
     * Пропустить ход.
     *
     * Данный метод позваляит игроку пропустить ход.
     * @param color цвет игрока
     */
    void pass( int color );

    /**
     * Чей ход?
     *
     * Данный метод возвращает цвет того игрока, который должен сделать ход.
     * @return цвет игрока, чей сейчас ход
     */
    int whoseMove() const;

    /**
     * Сдаться.
     *
     * Данный метод позволяет игроку сдаться.
     * @param color цвет игрока
     */
    void resign( int color );

    /**
     * Проверка на окончание игры.
     *
     * Данный метод возвращает true, если игра закончена, и false - в противном
     * случае
     * @return булевое значение
     */
    bool isGameOver() const;

    /**
     * Кто победил?
     * Данный метод возвращает цвет победителя.
     * @return цвет победителя
     */
    int whoWon() const;

    /**
     * Очки чёрных.
     * Данный метод возвращает количество очков чёрных.
     * @return очки чёрных
     */
    int getBlackScore() const;

    /**
     * Очки белых.
     * Данный метод возвращает количество очков белых.
     * @return очки белых
     */
    int getWhiteScore() const;

    /**
     * Деструктор.
     * Разрушает объект.
     */
    ~GoEngineInterface();


private:
    /**
     * Указатель на объект игровой доски.
     */
    Board* board;
};

#endif // GOENGINEINTERFACE_H
