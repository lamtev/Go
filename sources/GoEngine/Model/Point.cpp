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
    delete stone;
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
    //TODO fix leak or fix double delete
    stone = new Stone{ color, first, second, breaths };
}

void Point::deleteStone() noexcept
{
    //TODO fix leak or fix double delete
    stone = nullptr;
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
    return status == static_cast<int>(Status::EMPTY);
}

bool Point::isNotEmpty() const noexcept
{
    return !isEmpty();
}
