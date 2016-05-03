#include "GoEngineInterface.h"

GoEngineInterface::GoEngineInterface() noexcept
{
    board = nullptr;
    motion = nullptr;
    scoreCalculator = nullptr;
}

void GoEngineInterface::startGame( const int diagonal, const int rules, const int colorDistribution) noexcept
{
    board = new Board{ diagonal };
    motion = new Motion{};
    scoreCalculator = new ScoreCalculator{};
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

int GoEngineInterface::whoseMove() const noexcept
{
    return motion->whoseMove();
}

bool GoEngineInterface::isGameOver() const noexcept
{
    return motion->isGameOver();
}

int GoEngineInterface::whoSurrendered() const noexcept
{
    return motion->whoSurrendered();
}

int GoEngineInterface::whoWon() const noexcept
{
    return motion->whoWon();
}

Board& GoEngineInterface::getBoard() const noexcept
{
    return *board;
}

int GoEngineInterface::getStonesEatenByBlack() const noexcept
{
    return motion->getStonesEatenByBlack();
}

int GoEngineInterface::getStonesEatenByWhite() const noexcept
{
    return motion->getStonesEatenByWhite();
}

std::vector<Move>& GoEngineInterface::getMoves() const noexcept
{
    return motion->getMoves();
}

Move& GoEngineInterface::getLastMove() const noexcept
{
    return motion->getLastMove();
}
