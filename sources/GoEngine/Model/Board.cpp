#include "Board.h"

Board::Board( const int diagonal ) noexcept : diagonal(diagonal)
{
    board.resize(diagonal * diagonal);
}

Point& Board::operator()( const int first, const int second ) noexcept
{
    return board[(second-1) * diagonal + (first-1)];
}

Board& Board::operator=( const Board& board ) noexcept
{
    this->diagonal = board.diagonal;
    this->board = board.board;
    return *this;
}

int Board::getDiagonal() const noexcept
{
    return diagonal;
}

std::vector<Point>& Board::get() const noexcept
{
    return const_cast<std::vector<Point>&>(board);
}
