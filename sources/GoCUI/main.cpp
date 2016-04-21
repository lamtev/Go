#include <iostream>
using namespace std;

#include "../GoEngine/GoEngineInterface.h"
#include "InitBoards.h"
#include "GoGame.h"

void menu();
void paintBoard(int d);

int main( /*int argc, char* argv[]*/ )
{
    GoGame game;

    game.begin();
    //menu();
    return 0;
}

void menu()
{
    cout << "Choose board size" << endl;
    cout << "1. 19 X 19" << endl;
    cout << "2. 13 X 13" << endl;
    cout << "3.  7 X 7" << endl;
    int key;
    cin >> key;
    switch(key)
    {
        case 1 :
            paintBoard(19);
            break;
        case 2 :
            paintBoard(13);
            break;
        case 3 :
            paintBoard(7);
            break;
    }
}

void paintBoard(int d)
{
    switch(d)
    {
        case 19 :
            for( int i = 0; i < 21 * 43; ++ i )
            {
                if (i % 43 == 0)
                {
                    cout << endl;
                }
                cout << BOARD19[i];
            }
            break;
        case 13:
            for( int i = 0; i < 15 * 31; ++ i )
            {
                if (i % 31 == 0)
                {
                    cout << endl;
                }
                cout << BOARD13[i];
            }
            break;
        case 7 :
            for( int i = 0; i < 9 * 19; ++ i )
            {
                if (i % 19 == 0)
                {
                    cout << endl;
                }
                cout << BOARD7[i];
            }
            break;
    }
}