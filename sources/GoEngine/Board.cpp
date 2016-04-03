#include "Board.h"

Board::Board( const int diagonal ) : diagonal( diagonal )
{
    board.resize( diagonal * diagonal );
}

int& Board::operator()( const int i, const int j )
{
    return board[i * diagonal + j];
}

const int Board::getDiagonal() const noexcept
{
    return diagonal;
}





