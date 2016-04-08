#include "Board.h"

Board::Board( int diagonal ) : diagonal(diagonal)
{
    if ( diagonal != 7 && diagonal != 13 && diagonal != 19 )
    {
        throw IncorrectDiagonalException(diagonal);
    }
    board.resize(diagonal * diagonal);
}

Stone& Board::operator()( const int i, const int j )
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

Board& Board::operator=(const Board& board) noexcept
{
    this->diagonal = board.diagonal;
    this->board = board.board;
    return *this;
}


