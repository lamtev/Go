#ifndef GO_GOGAME_H
#define GO_GOGAME_H

#include "../GoEngine/GoEngineInterface.h"

/**
 * Класс, отвечающий за
 */
class GoGame
{
public:

    /**
     * Конструктор
     */
    GoGame();

    /**
     * Деструктор
     */
    ~GoGame();

    /**
     * Начать игру
     * Этот метод объединяет методы данного класса, отвечающие за организацию игрового процесса.
     */
    void begin();

private:

    /**
     * Указатель на объект интерфейса, предоставляемого движком приложению
     */
    GoEngineInterface* goEngineInterface;

};


#endif //GO_GOGAME_H
