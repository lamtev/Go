#include "GoGame.h"

GoGame::GoGame()
{
    goEngineInterface = new GoEngineInterface();
}

GoGame::~GoGame()
{
    delete goEngineInterface;
}

void GoGame::begin()
{
    //TODO
}

void GoGame::printWhoseMove()
{
    if( goEngineInterface->whoseMove() == BLACK )
    {
        std::cout << "Black's move" << std::endl;
    }
    else
    {
        std::cout << "White's move" << std::endl;
    }
}

void GoGame::printStonesEatenByBlack()
{
    //TODO
}

void GoGame::printStonesEatenByWhite()
{
    //TODO
}

void GoGame::printBoard()
{
    //TODO
}














