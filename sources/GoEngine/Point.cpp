#include "Point.h"

Point::Point( int status ) noexcept : status(status)
{

}

Point::Point( const Point& point ) noexcept
{
    this->status = point.status;
}

Point& Point::operator=( const Point& point ) noexcept
{
    this->status = point.status;
    return *this;
}

Point& Point::operator=( const int status ) noexcept
{
    this->status = status;
    return *this;
}

int Point::getStatus() const noexcept
{
    return status;
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


