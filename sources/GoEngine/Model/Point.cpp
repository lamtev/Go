#include "Point.h"

Point::Point( int status ) noexcept : status{ status },
                                      stone{nullptr },
                                      isStoneDeleted{ true }{}

Point::Point( const Point& point ) noexcept : status(point.status),
                                              stone{ point.stone },
                                              isStoneDeleted{ point.isStoneDeleted }{}

Point::~Point() noexcept
{
    if( !isStoneDeleted )
    {
        deleteStone();
    }
}

Point& Point::operator=( const Point& point ) noexcept
{
    //todo проверка на присваивание самому себе
    this->status = point.status;
    this->stone = point.stone;
    this->isStoneDeleted = point.isStoneDeleted;
    return *this;
}

Point& Point::operator=( const int status ) noexcept
{
    this->status = status;
    this->stone = nullptr;
    this->isStoneDeleted = true;
    return *this;
}

void Point::createStone( const int color, const int first, const int second, const int breaths ) noexcept
{
    stone = new Stone{ color, first, second, breaths };
    isStoneDeleted = false;
}

void Point::deleteStone() noexcept
{
    delete stone;
    isStoneDeleted = true;
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
    //todo я уже писал про тип в хедере
    return status == static_cast<int>(Status::EMPTY);
}

bool Point::isNotEmpty() const noexcept
{
    return !isEmpty();
}
