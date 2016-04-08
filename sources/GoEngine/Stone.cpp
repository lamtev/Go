#include "Stone.h"

Stone::Stone(int color) : color(color)
{

}

Stone& Stone::operator=(const Stone& stone) noexcept
{
    this->color = stone.color;
    return *this;
}

Stone& Stone::operator=(const int color) noexcept
{
    this->color = color;
    return *this;
}

int Stone::getColor() const noexcept
{
    return color;
}







