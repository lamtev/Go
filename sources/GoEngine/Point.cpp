#include "Point.h"

Point::Point( int status ) : status(status)
{

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
