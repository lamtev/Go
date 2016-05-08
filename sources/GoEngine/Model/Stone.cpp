#include "Stone.h"

Stone::Stone( const int color, const int first, const int second, const int breaths ) noexcept : color{ color },
                                                                                                 first{ first },
                                                                                                 second{ second },
                                                                                                 breaths{ breaths }{}

Stone& Stone::operator=( const Stone& stone ) noexcept
{
    //todo добавить проверку на присваивание самому себе.
    this->color = stone.color;
    this->first = stone.first;
    this->second = stone.second;
    this->breaths = stone.breaths;
    return *this;
}

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
