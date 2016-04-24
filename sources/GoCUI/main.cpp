#include <iostream>
using namespace std;

#include "../GoEngine/GoEngineInterface.h"
#include "InitBoards.h"
#include "GoGame.h"

void menu();
void paintBoard(int d);

int main( int argc, char* argv[] )
{
    GoGame game;
    game.begin();
    return 0;
}