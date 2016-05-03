#include "Move.h"

Move::Move( const int first, const int second ) noexcept : first(first), second(second){}

Move::Move( const Move& move ) noexcept
{
    this->first = move.first;
    this->second = move.second;
}

Move& Move::operator=( const Move& move ) noexcept
{
    this->first = move.first;
    this->second = move.second;
    return *this;
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
    return this->first == move.first && this->second == move.second;
}

bool Move::operator!=( const Move& move ) const noexcept
{
    return !(*this == move);
}

bool Move::isNotPass() const noexcept
{
    return *this != Move{ PASS_COORD, PASS_COORD };
}
