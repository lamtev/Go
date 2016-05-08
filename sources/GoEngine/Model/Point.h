#ifndef GO_POINT_H
#define GO_POINT_H

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
    explicit Point( int status = static_cast<int>(Status::EMPTY) ) noexcept;

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
     * @param breaths число дыханий
     */
    void createStone( const int color, const int first, const int second, const int breaths ) noexcept;

    /**
     * Удалить камень.
     */
    void deleteStone() noexcept;

    /**
     * Получить статус.
     * Метод для получения статуса пункта.
     * @return статус пункта
     */
    int getStatus() const noexcept;

    /**
     * Получить камень.
     * @return ссылку на объект класса Stone
     */
    Stone& getStone() const noexcept;

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

    int status; /**< Статус пункта */
    Stone* stone; /**< Указатель на камень */
    bool isStoneDeleted; /**< Камень удалён? */

};

#endif //GO_POINT_H
