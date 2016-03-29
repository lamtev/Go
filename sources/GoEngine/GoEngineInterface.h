#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>
#include "enums.h"
#include "Board.h"

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
    void startGame( const std::string config );

    /**
     * Начать игру.
     *
     * Этот метод начинает игру с параметрами, заданными его аргументами.
     * @param diagonal диагональ игровой доски
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    void startGame( const int diagonal, const Rules rules,
                           const ColorDistribution colorDistribution );

    /**
     * Положить камень в выбранный пункт.
     *
     * Данный метод позволяет игроку положить его иговой камень в пункт доски.
     * @param color цвет игрока
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     */

    void putStone( const Color color, const LiteralCoordinate first,
                   const int second );

    /**
     * Пропустить ход.
     *
     * Данный метод позваляит игроку пропустить ход.
     * @param color цвет игрока
     */
    void pass( Color color );

    /**
     * Сдаться.
     *
     * Данный метод позволяет игроку сдаться.
     * @param color цвет игрока
     */
    void resign( Color color );

    /**
     * Проверка на окончание игры.
     *
     * Данный метод возвращает true, если игра закончена, и false - в противном
     * случае
     */
    bool isGameOver() const;

    /**
     * Победитель.
     *
     * Данный метод возвращает цвет победителя
     */
    Color whoWon() const;

    /**
     * Очки чёрных.
     *
     * Данный метод возвращает количество очков чёрных.
     */
    int getBlackScore() const;

    /**
     * Очки белых.
     *
     * Данный метод возвращает количество очков белых.
     */
    int getWhiteScore() const;


private:
    /**
     * Игровая доска.
     *
     */
    Board board;
};

#endif // GOENGINEINTERFACE_H
