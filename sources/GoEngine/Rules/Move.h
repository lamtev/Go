#ifndef GO_MOVE_H
#define GO_MOVE_H

#include "../Model/enums.h"

/**
 * Ход.
 */
class Move
{

public:

    /**
     * Конструктор.
     * @param first первая координата
     * @param second вторая координата
     */
    Move( const int first = -2, const int second = -2 ) noexcept;

    /**
     * Копирующий конструктор.
     * @param move ссылка на константный объект класса Move
     */
    Move( const Move& move ) noexcept;

    /**
     * Присваивание.
     * Перегруженный оператор присваивания.
     * @param move ссылка на присваиваемый константный объект класса Move
     * @return ссылку на объект
     */
    Move& operator=( const Move& move ) noexcept;

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
     * Равенство.
     * Перегруженный оператор равенства.
     * @param move ссылка на константный объект класса Move, с которым сравнивается данный объект
     * @return true, если объекты равны, и false - в противном случае
     */
    bool operator==( const Move& move ) const noexcept;

    /**
     * Неравенство.
     * Перегруженный оператор неравенства.
     * @param move ссылка на константный объект класса Move, с которым сравнивается данный объект
     * @return true, если объекты не равны, и false - в противном случае
     */
    bool operator!=( const Move& move ) const noexcept;

private:

    int first; /**< Первая координата */
    int second; /**< Вторая координата */

};


#endif //GO_MOVE_H
