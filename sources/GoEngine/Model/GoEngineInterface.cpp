#include "GoEngineInterface.h"

GoEngineInterface::GoEngineInterface() noexcept
{
    gameProcess = nullptr;
}

void GoEngineInterface::startGame( const int diagonal, const int rules, const int colorDistribution ) noexcept
{
    gameProcess = new GameProcess { diagonal };
}

GoEngineInterface::~GoEngineInterface()
{
    delete gameProcess;
}

void GoEngineInterface::putStone( const int first, const int second )
{
    gameProcess->putStone(first, second);
}

void GoEngineInterface::pass() noexcept
{
    gameProcess->pass();
}

void GoEngineInterface::surrender() noexcept
{
    gameProcess->surrender();
}

int GoEngineInterface::whoseMove() const noexcept
{
    return gameProcess->whoseMove();
}

bool GoEngineInterface::isGameOver() const noexcept
{
    return gameProcess->isGameOver();
}

int GoEngineInterface::whoSurrendered() const noexcept
{
    return gameProcess->whoSurrendered();
}

int GoEngineInterface::whoWon() const noexcept
{
    return gameProcess->whoWon();
}

int GoEngineInterface::getStonesEatenByBlack() const noexcept
{
    return gameProcess->getStonesEatenByBlack();
}

int GoEngineInterface::getStonesEatenByWhite() const noexcept
{
    return gameProcess->getStonesEatenByWhite();
}

std::vector<Move>& GoEngineInterface::getMoves() const noexcept
{
    return gameProcess->getMoves();
}

Move& GoEngineInterface::getLastMove() const noexcept
{
    return gameProcess->getLastMove();
}

Move& GoEngineInterface::getPenultMove() const noexcept
{
    return gameProcess->getPenultMove();
}

int GoEngineInterface::getMoveIndex() const noexcept
{
    return gameProcess->getMoveIndex();
}


int GoEngineInterface::getDiagonal() const noexcept
{
    return gameProcess->getBoard().getDiagonal();
}

int GoEngineInterface::getIJPointsStatus( const int i, const int j ) const noexcept
{
    return gameProcess->getBoard().operator()(i, j).getStatus();
}
