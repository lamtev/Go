#ifndef GO_STONE_H
#define GO_STONE_H


class Stone
{

public:

    /**
     * Конструктор.
     */
    Stone() noexcept;

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
     * Получить цвет.
     * @return цвет
     */
    int getColor() const noexcept;

    /**
     * Получить число дыханий.
     * @return число дыханий
     */
    int getBreaths() const noexcept;

private:

    int first; /**< Первая координата */
    int second; /**< Вторая координата */
    int color; /**< Цвет */
    int breaths; /**< Число дыханий */

    /**
     * Посчитать число дыханий.
     * @return число дыханий
     */
    int calculateBreaths() const noexcept;

};


#endif //GO_STONE_H
