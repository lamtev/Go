#include "Point.h"

Point::Point( int status ) noexcept : status(status)
{
    this->stone = nullptr;
}

Point::Point( const Point& point ) noexcept : status(point.status)
{
    this->stone = nullptr;
}

Point::~Point()
{
    deleteStone();
}

Point& Point::operator=( const Point& point ) noexcept
{
    this->status = point.status;
    this->stone = point.stone;
    return *this;
}

Point& Point::operator=( const int status ) noexcept
{
    this->status = status;
    this->stone = nullptr;
    return *this;
}

void Point::createStone( const int color, const int first, const int second, const int breaths ) noexcept
{
    stone = new Stone{ color, first, second, breaths };
}

void Point::deleteStone() noexcept
{
    delete stone;
}

int Point::getStatus() const noexcept
{
    return status;
}

Stone& Point::getStone() const noexcept
{
    return *stone;
}


bool Point::isEmpty() const noexcept
{
    return status == EMPTY;
}

bool Point::isNotEmpty() const noexcept
{
    return status != EMPTY;
}

bool Point::operator==( const Point& point ) const noexcept
{
    return this->status == point.status;
}

bool Point::operator!=( const Point& point ) const noexcept
{
    return !(*this == point);
}
