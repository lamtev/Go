#ifndef GO_MOVES_H
#define GO_MOVES_H

/**
 * Ходы.
 */
class Moves
{
public:

    /**
     * Перегруженный оператор равенства
     */
    bool operator==( const Moves& moves ) const noexcept;

    /**
     * Перегруженный оператор неравенства
     */
    bool operator!=( const Moves& moves ) const noexcept;

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

private:
    int first;
    int second;
};


#endif //GO_MOVES_H
