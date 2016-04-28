#ifndef GO_STONE_H
#define GO_STONE_H

#include "enums.h"

class Stone
{

public:

    /**
     * Конструктор.
     */
    Stone( const int color, const int first, const int second, const int breaths ) noexcept;

    /**
     * Получить цвет.
     * @return цвет
     */
    int getColor() const noexcept;

    /**
     * Получить первую координату.
     * @return первую координату
     */
    int getFirst() const noexcept;

    /**
     * Получить вторую координату.
     * @return вторую координату
     */
    int getSecond() const noexcept;

    /**
     * Получить число дыханий.
     * @return число дыханий
     */
    int getBreaths() const noexcept;

private:

    int color; /**< Цвет */
    int first; /**< Первая координата */
    int second; /**< Вторая координата */
    int breaths; /**< Число дыханий */

};


#endif //GO_STONE_H
