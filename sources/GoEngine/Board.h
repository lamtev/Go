#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <vector>
#include "Stone.h"

using std::vector;

class Board
{
public:
    Board( int diagonal = 19 );
private:
    vector<vector<int>> board;
};


#endif //GO_BOARD_H
