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

}




