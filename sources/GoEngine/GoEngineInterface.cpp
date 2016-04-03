#include "GoEngineInterface.h"

void GoEngineInterface::startGame(const int diagonal, const Rules rules, const ColorDistribution colorDistribution)
{
    board = new Board<int>(diagonal);
}

Board<int> GoEngineInterface::getBoard() const noexcept
{
    return *board;
}

GoEngineInterface::~GoEngineInterface()
{
    delete board;
}



