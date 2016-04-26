#ifndef GO_POINT_H
#define GO_POINT_H

#include "enums.h"

/**
 * Пункт игровой доски
 */
class Point
{

public:

    /**
     * Конструктор.
     * @param status статус пункта.
     */
    Point( const int status = EMPTY ) noexcept;

    /**
     * Копирующий конструктор.
     * @param point ссылка на константный объект класса Point
     */
    Point( const Point& point) noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания. Позволяет присваивать объекту значение другого объекта.
     * @param point ссылка на присваиваемый константный объект класса Point
     * @return ссылку на объект
     */
    Point& operator=( const Point& point ) noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания. Позволяет присваивать объекту целочисленное значение - статус пункта.
     * @param status присваиваемый статус пункта
     * @return ссылку на объект
     */
    Point& operator=( const int status ) noexcept;

    /**
     * Получить статус.
     * Метод для получения статуса пункта.
     * @return статус пункта
     */
    int getStatus() const noexcept;

    /**
     * Пункт свободен?
     * @return true, если свободен, и false, если несвободен
     */
    bool isEmpty() const noexcept;

    /**
     * Пункт несвободен?
     * @return true, если несвободен, и false, если свободен
     */
    bool isNotEmpty() const noexcept;

private:

    int status; /**< статус пункта */

};

#endif //GO_POINT_H
