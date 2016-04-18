#include "GoEngineInterface.h"

void GoEngineInterface::startGame(const int diagonal, const int rules, const int colorDistribution)
{
    board = new Board(diagonal);
    motion = new Motion();
    scoreCalculator = new ScoreCalculator();
}

GoEngineInterface::~GoEngineInterface()
{
    delete board;
    delete motion;
    delete scoreCalculator;
}

Board& GoEngineInterface::getBoard() const noexcept
{
    return *board;
}

void GoEngineInterface::putStone( const int first, const int second )
{
    motion->putStone(board, first, second);
}

void GoEngineInterface::pass()
{
    motion->pass();
}

int GoEngineInterface::whoseMove() const noexcept
{
    return motion->whoseMove();
}








