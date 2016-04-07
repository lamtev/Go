#include "Board.h"

Board::Board( int diagonal ) : diagonal(diagonal)
{
    if ( diagonal != 7 && diagonal != 13 && diagonal != 19 )
    {
        throw IncorrectDiagonalException(diagonal);
    }
    board.resize(diagonal * diagonal);
}

Board::Board(const vector<int>& board)
{
    if( board.size() != 7*7 && board.size() != 13*13 && board.size() != 19*19 )
    {
        throw IncorrectDiagonalException(static_cast<int>(sqrt(board.size())));
    }
    this->board.resize( board.size() );
    this->board = board;
    this->diagonal = static_cast<int>(sqrt(board.size()));
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

Board& Board::operator=( const vector<int>& board ) noexcept
{
    this->board = board;
    return *this;
}
