#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>
#include <cmath>

#include "BoundsViolationException.h"
#include "IncorrectDiagonalException.h"

using std::vector;

//TODO noecept swap
//TODO high performance =
class Board
{
public:
    Board( int diagonal );
    Board( const vector<int>& board );
    int& operator()( const int i, const int j );
    int getDiagonal() const noexcept;
    Board& operator=( const vector<int>& board ) noexcept;

private:
    int diagonal;
    vector<int> board;
};


#endif //GO_BOARD_H
