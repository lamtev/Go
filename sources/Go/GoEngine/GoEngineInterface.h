#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include "enums.h"

///Интерфейс предоставляемый движком приложению
class GoEngineInterface
{
public:
    ///Начать новую игру
    void startNewGame();
    ///Загрузить игру
    void loadGame();
    ///Положить камень в выбранный пункт
    void putStone(PlayerColor color, LiteralCoordinate x, int y);
    ///Пропустить ход
    void check(PlayerColor color);

private:

};

#endif // GOENGINEINTERFACE_H
