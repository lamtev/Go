#ifndef GO_POINT_H
#define GO_POINT_H

#include "enums.h"

class Point
{

public:

    /**
     * Конструктор.
     * @param status статус пункта.
     */
    Point( int status = EMPTY );

    /**
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param stone ссылка на константный объект класса Stone
     * @return ссылка на объект данного класса
     */
    Point& operator=( const Point& stone ) noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания. Позволяет присваивать объекту данного
     * класса целочисленное значение - цвет камня.
     * @param color целочисленный тип - цвет камня
     * @return ссылка на объект данного класса
     */
    Point& operator=( const int status ) noexcept;

    /**
     * Получить цвет.
     * Метод для получения цвета камня.
     * @return целочисленный тип - цвет камня.
     */
    int getStatus() const noexcept;
private:

    int status;


};


#endif //GO_POINT_H
