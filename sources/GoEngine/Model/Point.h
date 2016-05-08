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
    //todo почему бы сразу не использовать enum как тип переменной?
    //explicit Point( Status status = Status::EMPTY ) noexcept;
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
    //todo почему бы сразу не использовать enum как тип переменной?
    Point& operator=( const int status ) noexcept;

    /**
     * Создать камень.
     * @param color цвет
     * @param first первая координата
     * @param second вторая координата
     * @param breaths число дыханий
     */
    //todo first и second вводят в заблуждение
    void createStone( const int color, const int first, const int second, const int breaths ) noexcept;
    //todo предложение:
    //может попробовать что-нибуль типа
    //void setStone(const Stone& stone) noexcept; ?
    //Возможно, синтаксис типа addStone(Stone( 2, 5, 6, 3)) был бы более понятен
    //Я не настаиваю, дело вкуса.
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
    //todo может, лучше использовать только isEmpty (с !), похожие методы создают путаницу
    //может не хорошо получится, если где то пишут isNotEmpty(), а где то !isEmpty().
    // ИМХО: учше не давать клиенту возможности выбора, чтобы избежать путаницы.
    bool isNotEmpty() const noexcept;

private:
    //todo почему бы сразу не использовать enum как тип переменной?
    //Status status;
    int status; /**< Статус пункта */
    Stone* stone; /**< Указатель на камень */
    bool isStoneDeleted; /**< Камень удалён? */

};

#endif //GO_POINT_H
