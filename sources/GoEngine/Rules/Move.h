#ifndef GO_MOVE_H
#define GO_MOVE_H

/**
 * Ход.
 */
class Move
{
public:

    /**
     * Конструктор.
     */
    Move();

    /**
     * Конструктор.
     */
    Move( int first, int second );

    /**
     * Задать первую координату.
     * @param first первая координата
     */
    void putFirst( int first ) noexcept;

    /**
     * Задать вторую координату.
     * @param second вторая координата
     */
    void putSecond( int second ) noexcept;

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
     * Перегруженный оператор равенства
     */
    bool operator==( const Move& move ) const noexcept;

    /**
     * Перегруженный оператор неравенства
     */
    bool operator!=( const Move& move ) const noexcept;

private:
    int first;
    int second;
};


#endif //GO_MOVE_H
