#include "Board.h"

Board::Board( int diagonal ) : diagonal( diagonal )
{
    if (diagonal != 7 || diagonal != 13 || diagonal != 19)
    {
        throw IncorrectDiagonalException(diagonal);
    }
    board.resize( diagonal * diagonal );
}

int& Board::operator()( const int i, const int j )
{
    if( i < 0 || i >= diagonal || j < 0 || j >= diagonal )
    {
        throw BoundsViolationException();
    }
    return board[i * diagonal + j];
}

int Board::getDiagonal() const noexcept
{
    return diagonal;
}





