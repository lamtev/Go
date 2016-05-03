#include <iostream>

#include "../GoEngine/Model/GoEngineInterface.h"
#include "InitBoards.h"
#include "GoGame.h"

int main( int argc, char* argv[] )
{
    GoGame game{ argc, argv };
    game.begin();
    return 0;
}
