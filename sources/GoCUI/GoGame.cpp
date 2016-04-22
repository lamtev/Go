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
    configureGame();
    play();

}

void GoGame::configureGame()
{
    int diagonal;
    inputDiagonal(diagonal);
    goEngineInterface->startGame(diagonal, JAPANESE, AGREEMENT);
}

void GoGame::play()
{
    bool isExit = false;
    bool isInputIncorrect = false;
    int first, second;
    std::string input;
    startGameCycle(input, first, second, isExit, isInputIncorrect);

}

void GoGame::startGameCycle( std::string& input, int& first, int& second, bool& isExit, bool& isInputIncorrect )
{
    while( !goEngineInterface->isGameOver() || isExit )
    {
        printEatenStonesStat();
        printBoard();

        printWhoseMove();
        std::getline(std::cin, input);
        parseInput(input, first, second, isInputIncorrect);
        if( isInputIncorrect )
        {

        }
        isExit = this->isExit(input);
    }
}

void GoGame::parseInput( const std::string& input, int& first, int& second, bool& isInputIncorrect ) const noexcept
{
    if( !input.compare("pass") )
    {

    }
    else if( !input.compare("surrender") )
    {

    }
    else if( !input.compare("exit") )
    {

    }
    else
    {
        parseFirstCoordinate(input, first, isInputIncorrect);
        parseSecondCoordinate(input, second, isInputIncorrect);
    }



}

void GoGame::parseFirstCoordinate( const std::string& input, int& first, bool& isInputIncorrect ) const noexcept
{
    switch( input[0] )
    {
    case 'a' :
        first = A;
        break;
    case 'b' :
        first = B;
        break;
    case 'c' :
        first = C;
        break;
    case 'd' :
        first = D;
        break;
    case 'e' :
        first = E;
        break;
    case 'f' :
        first = F;
        break;
    case 'g' :
        first = G;
        break;
    case 'h' :
        first = H;
        break;
    case 'i' :
        first = I;
        break;
    case 'j' :
        first = J;
        break;
    case 'k' :
        first = K;
        break;
    case 'l' :
        first = L;
        break;
    case 'm' :
        first = M;
        break;
    case 'n' :
        first = N;
        break;
    case 'o' :
        first = O;
        break;
    case 'p' :
        first = P;
        break;
    case 'q' :
        first = Q;
        break;
    case 'r' :
        first = R;
        break;
    case 's' :
        first = S;
        break;
    default :
        isInputIncorrect = true;
        break;
    }
}

void GoGame::parseSecondCoordinate( const std::string& input, int& second, bool& isInputIncorrect ) const noexcept
{
    std::string number;
    number = input.substr(1);
    std::istringstream iss(number, std::istringstream::in);
    iss >> second;
    if( !iss )
    {
        isInputIncorrect = true;
    }
}

void GoGame::printWhoseMove() const
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





void GoGame::printBoard()
{
    for( int i = 0; i < 21 * 43; ++ i )
    {
        if (i % 43 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << BOARD19[i];
    }
    std::cout << std::endl;
}
void GoGame::printStonesEatenByBlack() const noexcept
{

}

void GoGame::printStonesEatenByWhite() const noexcept
{
    //TODO
}

void GoGame::inputDiagonal( int& diagonal )
{
    bool isIncorrectInput = true;
    std::string input;
    while( isIncorrectInput )
    {
        printDiagonalInputMessage();
        std::getline(std::cin, input);
        isIncorrectInput = !isDiagonalCorrect(input);
    }
    diagonal = getDiagonal(input);
}

void GoGame::printDiagonalInputMessage()
{
    std::cout << "Chose board diagonal" << std::endl;
    std::cout << "   (7, 13 or 19)" << std::endl;
}

bool GoGame::isDiagonalN( const int n, const std::string& input ) const noexcept
{
    std::ostringstream ss;
    ss.str("");
    ss << n;
    return !input.compare(ss.str());
}

bool GoGame::isDiagonalCorrect( const std::string& input ) const noexcept
{
    return isDiagonalN(7, input) || isDiagonalN(13, input) || isDiagonalN(19, input);
}

int GoGame::getDiagonal( const std::string& input ) const noexcept
{
    if( isDiagonalN(7, input) )
    {
        return 7;
    }
    else if( isDiagonalN(13, input) )
    {
        return 13;
    }
    else if( isDiagonalN(19, input) )
    {
        return 19;
    }
    return 0;
}

bool GoGame::isExit( const std::string& input ) const noexcept
{
    return !input.compare("exit");
}

void GoGame::printEatenStonesStat() const
{
    printStonesEatenByBlack();
    printStonesEatenByWhite();
}


















































