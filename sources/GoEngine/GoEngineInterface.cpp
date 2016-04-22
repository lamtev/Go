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


void GoEngineInterface::putStone( const int first, const int second )
{
    motion->putStone(board, first, second);
}

void GoEngineInterface::pass() noexcept
{
    motion->pass();
}

void GoEngineInterface::surrender() noexcept
{
    motion->surrender();
}

Board& GoEngineInterface::getBoard() const noexcept
{
    return *board;
}

int GoEngineInterface::whoseMove() const noexcept
{
    return motion->whoseMove();
}

bool GoEngineInterface::isGameOver() const
{
    return motion->isGameOver();
}












