#include "GoEngineInterface.h"

void GoEngineInterface::startGame(const int diagonal, const Rules rules, const ColorDistribution colorDistribution)
{
    board = new Board(diagonal);
}

Board GoEngineInterface::getBoard() const noexcept
{
    return *board;
}

GoEngineInterface::~GoEngineInterface()
{
    delete board;
}



