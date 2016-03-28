#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>
#include "enums.h"
/**
 * Класс, предоставляющий интерфейс движка приложению.
 */
class GoEngineInterface
{
public:

    /**
     * Начать игру.
     *
     * Этот метод начинает игру с параметрами, заданными его аргументами.
     * @param config конфигурационный файл
     * @param diagonal диагональ игровой доски
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    virtual void startGame(const std::string config, const int diagonal, const Rules rules,
                           const ColorDistribution colorDistribution)=0;

    /**
     * Положить камень в выбранный пункт.
     *
     * Данный метод позволяет игроку положить его иговой камень в пункт доски.
     * @param color цвет игрока
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     */
    virtual void putStone(PlayerColor color, LiteralCoordinate first, int second)=0;

    /**
     * Пропустить ход.
     *
     * Данный метод позваляит игроку пропустить ход.
     * @param color цвет игрока
     */
    virtual void pass(PlayerColor color)=0;

    /**
     * Сдаться.
     *
     * Данный метод позволяет игроку сдаться.
     * @param color цвет игрока
     */
    virtual void resign(PlayerColor color)=0;

private:

};

#endif // GOENGINEINTERFACE_H
