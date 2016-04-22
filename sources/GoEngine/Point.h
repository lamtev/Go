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
     * @param status целочисленный тип - цвет камня
     * @return ссылка на объект данного класса
     */
    Point& operator=( const int status ) noexcept;

    /**
     * Получить статус.
     * Метод для получения статуса пункта.
     * @return целочисленный тип - статус пункта
     */
    int getStatus() const noexcept;

    /**
     * Свободный пункт?
     * return true, если свободный, и false - в противном случае
     */
    bool isEmpty() const noexcept;

    /**
     * Несвободный пункт?
     * return true, если несвободный, и false - в противном случае
     */
    bool isNotEmpty() const noexcept;

private:

    int status; /**< статус пункта */

};


#endif //GO_POINT_H
