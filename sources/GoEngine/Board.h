#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>
#include "Stone.h"
#include "BoundsViolationException.h"
#include "IncorrectDiagonalException.h"

using std::vector;

class Board
{
public:
    Board( const int diagonal = 19 );
    int& operator()( const int i, const int j );
    int getDiagonal() const noexcept;
private:
    int diagonal;
    vector<int> board;
};


#endif //GO_BOARD_H
