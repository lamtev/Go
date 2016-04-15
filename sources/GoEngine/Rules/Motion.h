#ifndef GO_MOTION_H
#define GO_MOTION_H

#include <vector>

#include "../Board.h"

using std::vector;

struct Moves
{
    int firstCoord;
    int secondCoord;
};

//TODO

/**
 * Класс ход.
 * Контролирует правильность совершения ходов.
 */
class Motion
{
public:

    /**
     * Чей ход?
     * Метод определяющий цвет игрока, чей сейчас ход.
     */
    int whoseMove() const noexcept;

    /**
     * Положить камень.
     */
    void putStone() const;

    /**
     * Пропустить ход.
     */
    void pass() const noexcept;

    /**
     * Проверка двух последних ходов на пропуск.
     */
    bool areTwoPasses() const noexcept;

private:

    /**
     * Вектор, хранящий все совершенные ходы
     */
    vector<Moves> moves;

    /**
     * Проверка легитимности хода
     */
    bool isMoveLegit();
};


#endif //GO_MOTION_H
