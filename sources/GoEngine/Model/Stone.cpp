#include "Stone.h"

Stone::Stone( const int color, const int first, const int second, const int breaths ) noexcept :
        color(color), first(first), second(second), breaths(breaths){}

int Stone::getColor() const noexcept
{
    return color;
}

int Stone::getFirst() const noexcept
{
    return first;
}

int Stone::getSecond() const noexcept
{
    return second;
}

int Stone::getBreaths() const noexcept
{
    return breaths;
}
