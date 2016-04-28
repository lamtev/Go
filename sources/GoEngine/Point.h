#ifndef GO_POINT_H
#define GO_POINT_H

#include "enums.h"
#include "Stone.h"

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
    Point( int status = EMPTY ) noexcept;

    /**
     * Копирующий конструктор.
     * @param point ссылка на константный объект класса Point
     */
    Point( const Point& point ) noexcept;

    /**
     * Деструктор.
     */
    ~Point() noexcept;

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
     * Создать камень.
     * @param color цвет
     * @param first первая координата
     * @param second вторая координата
     * @
     */
    void createStone( const int color, const int first, const int second, const int breaths ) noexcept;

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

    /**
     * Равенство.
     * Перегруженный оператор равенства.
     * @param point ссылка на константный объект класса Point, с которым сравнивается данный объект
     * @return true, если объекты равны, и false - в противном случае
     */
    bool operator==( const Point& point ) const noexcept;

    /**
     * Неравенство.
     * Перегруженный оператор неравенства.
     * @param point ссылка на константный объект класса Point, с которым сравнивается данный объект
     * @return true, если объекты не равны, и false - в противном случае
     */
    bool operator!=( const Point& point ) const noexcept;

private:

    int status; /**< Статус пункта */
    Stone* stone; /**< Указатель на объект класса Stone */

    /**
     * Удалить камень.
     */
    void deleteStone() noexcept;

};

#endif //GO_POINT_H
