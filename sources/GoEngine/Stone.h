#ifndef GO_STONE_H
#define GO_STONE_H

//TODO noexcept swap
//TODO high performance operator=

/**
 * Класс камень.
 */
class Stone
{
public:

    /**
     * Конструктор.
     * @param color целочисленный тип - цвет камня.
     */
    Stone( int color = 0 );

    /**
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param stone ссылка на константный объект класса Stone
     * @return ссылка на объект данного класса
     */
    Stone& operator=( const Stone& stone ) noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания. Позволяет присваивать объекту данного
     * класса целочисленное значение - цвет камня.
     * @param color целочисленный тип - цвет камня
     * @return ссылка на объект данного класса
     */
    Stone& operator=( const int color ) noexcept;

    /**
     * Получить цвет.
     * Метод для получения цвета камня.
     * @return целочисленный тип - цвет камня.
     */
    int getColor() const noexcept;
private:

    /**
     * Поле класса - цвет камня.
     */
    int color;
};


#endif //GO_STONE_H
