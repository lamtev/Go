#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>
#include "enums.h"
/**
 * @brief Класс, предоставляющий интерфейс движка приложению
 */
class GoEngineInterface
{
public:

    /**
     * @brief Начать игру.
     *
     * Метод, позволяющий начать игру в соответствии с параметрами, которые задаются его аргументами.
     * @param config Конфиг
     */
    void startGame(std::string config=0, int size=0, Rules rules=JAPANESE, bool isNigiri=true);
    ///Положить камень в выбранный пункт
    void putStone(PlayerColor color, LiteralCoordinate x, int y);
    ///Пропустить ход
    void pass(PlayerColor color);
    ///Cдаться
    void resign(PlayerColor color);

private:

};

#endif // GOENGINEINTERFACE_H
