#include "Move.h"

Move::Move()
{

}

Move::Move( int first, int second ) : first(first), second(second)
{

}

void Move::putFirst( int first ) noexcept
{
    this->first = first;
}

void Move::putSecond( int second ) noexcept
{
    this->second = second;
}

int Move::getFirst() const noexcept
{
    return first;
}

int Move::getSecond() const noexcept
{
    return second;
}

bool Move::operator==( const Move& move ) const noexcept
{
    return this->first == move.first && this->second == second;
}

bool Move::operator!=( const Move& move ) const noexcept
{
    return !(*this == move);
}



















