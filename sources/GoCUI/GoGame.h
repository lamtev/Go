#ifndef GO_GOGAME_H
#define GO_GOGAME_H

#include <iostream>

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

    /**
     * Напечатать, чей ход.
     */
    void printWhoseMove();

    /**
     * Напечатать, сколько камней съели чёрные.
     */
    void printStonesEatenByBlack();

    /**
     * Напечатать, сколько камней съели белые.
     */
    void printStonesEatenByWhite();

    /**
     * Отрисовать текущее состояние доски.
     */
    void printBoard();

};


#endif //GO_GOGAME_H
