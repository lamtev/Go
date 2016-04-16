#include "Moves.h"

Moves::Moves()
{

}

Moves::Moves( int first, int second ) : first(first), second(second)
{

}

void Moves::putFirst( int first ) noexcept
{
    this->first = first;
}

void Moves::putSecond( int second ) noexcept
{
    this->second = second;
}

int Moves::getFirst() const noexcept
{
    return first;
}

int Moves::getSecond() const noexcept
{
    return second;
}

bool Moves::operator==( const Moves& moves ) const noexcept
{
    return this->first == moves.first && this->second == second;
}

bool Moves::operator!=(const Moves& moves) const noexcept
{
    return !(*this == moves);
}



















