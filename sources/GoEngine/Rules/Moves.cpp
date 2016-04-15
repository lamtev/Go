#include "Moves.h"

bool Moves::operator==( const Moves moves ) const noexcept
{
    return this->first == moves.first && this->second == second;
}

bool Moves::operator!=(const Moves moves) const noexcept
{
    return !(*this == moves);
}

void Moves::putFirst( int first ) noexcept
{
    this->first = first;
}

void Moves::putSecond( int second ) noexcept
{
    this->second = second;
}










