#ifndef GO_STONE_H
#define GO_STONE_H

//TODO noexcept swap && high performance operator=
//проверка на присваивавание самому себе

enum class Status
{
    EMPTY = 0,
    BLACK,
    WHITE
};

enum class Color
{
    BLACK = 1,
    WHITE
};

enum LiteralCoordinate
{
    A = 1,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

enum Rules
{
    JAPANESE = 0,
    CHINESE
};

enum ColorDistribution
{
    NIGIRI = 0,
    AGREEMENT
};

/**
 * Камень.
 */
class Stone
{

public:

    /**
     * Конструктор.
     * @param color цвет
     * @param first первая координата
     * @param second вторая координата
     * @param breaths число дыханий
     */
    //todo почему бы не использовать enum для цвета?
    Stone( const Color color, const int first, const int second, const int breaths ) noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param stone ссылка на константный объект класса Stone - камень
     * @return ссылку на объект
     */
    Stone& operator=( const Stone& stone ) noexcept;

    /**
     * Получить цвет.
     * @return цвет
     */
    Color getColor() const noexcept;

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

    Color color; /**< Цвет */
    int first; /**< Первая координата */
    int second; /**< Вторая координата */
    int breaths; /**< Число дыханий */

};


#endif //GO_STONE_H
