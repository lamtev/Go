#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>
#include <cmath>

#include "BoundsViolationException.h"
#include "IncorrectDiagonalException.h"

using std::vector;

template<class T>
class Board
{
public:
    Board( int diagonal ) : diagonal( diagonal )
    {
        if ( diagonal != 7 && diagonal != 13 && diagonal != 19 )
        {
            throw IncorrectDiagonalException(diagonal);
        }
        board.resize(diagonal * diagonal);
    }

    Board(const vector<T>& board)
    {
        this->board.resize(board.size());
        this->board = board;
        this->diagonal = static_cast<int>(sqrt(board.size()));
    }

    T& operator()( const int i, const int j )
    {
        if( i < 0 || i >= diagonal || j < 0 || j >= diagonal )
        {
            throw BoundsViolationException();
        }
        return board[i * diagonal + j];
    }

    int getDiagonal() const noexcept
    {
        return diagonal;
    }

    Board<T>& operator=( const vector<T>& newBoard ) noexcept
    {
        this->board = newBoard;
        return *this;
    }

private:
    int diagonal;
    vector<T> board;
};


#endif //GO_BOARD_H
