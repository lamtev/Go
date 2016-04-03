#ifndef GO_INCORRECTDIAGONALEXCEPTION_H
#define GO_INCORRECTDIAGONALEXCEPTION_H

#include <exception>

class IncorrectDiagonalException : public std::exception
{
public:
    IncorrectDiagonalException( const int diagonal ) : diagonal(diagonal){}
    const int getDiagonal() const noexcept
    {
        return diagonal;
    }
private:
    const int diagonal;
};

#endif //GO_INCORRECTDIAGONALEXCEPTION_H
