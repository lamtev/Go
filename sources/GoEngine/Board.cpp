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

Point& Board::operator()( const int i, const int j ) noexcept
{
    return board[i * diagonal + j];
}

Board& Board::operator=( const Board& board ) noexcept
{
    this->diagonal = board.diagonal;
    this->board = board.board;
    return *this;
}



