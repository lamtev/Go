#include "GoEngineInterface.h"

void GoEngineInterface::startGame(const int diagonal, const int rules, const int colorDistribution)
{
    board = new Board(diagonal);
}

GoEngineInterface::~GoEngineInterface()
{
    delete board;
}

Board GoEngineInterface::getBoard() const noexcept
{
    return *board;
}

void GoEngineInterface::putStone( const int color, const int first, const int second )
{
    //TODO
    //board->operator()(first, second) = color;
}

void GoEngineInterface::pass( int color )
{
    //TODO
}

int GoEngineInterface::whoseMove() const
{
    //TODO
    return 0;
}








