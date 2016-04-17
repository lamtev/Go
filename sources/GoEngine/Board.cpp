#include "Board.h"

Board::Board( int diagonal ) : diagonal(diagonal)
{
    if ( diagonal != 7 && diagonal != 13 && diagonal != 19 )
    {
        throw IncorrectDiagonalException();
    }
    board.resize(diagonal * diagonal);
}

int Board::getDiagonal() const noexcept
{
    return diagonal;
}

vector<Point>& Board::get() const noexcept
{
    return const_cast<vector<Point>&>(board);
}

Point& Board::operator()( const int i, const int j )
{
    if( i < 0 || i >= diagonal || j < 0 || j >= diagonal )
    {
        throw BoundsViolationException();
    }
    return board[i * diagonal + j];
}

Board& Board::operator=( const Board& board ) noexcept
{
    this->diagonal = board.diagonal;
    this->board = board.board;
    return *this;
}

void Board::getFirstAndSecond( int vectorIndex, int& first, int& second ) const noexcept
{
    for( int i = 0; i < vectorIndex; ++i )
    {
        for( int j = 0; j < vectorIndex; ++j )
        {
            if( first * diagonal == vectorIndex - second && (vectorIndex - second) % diagonal == 0 )
            {
                first = i;
                second = j;
                break;
            }
        }
    }
}


