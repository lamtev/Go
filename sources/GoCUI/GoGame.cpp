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
    int diagonal;
    inputDiagonal(diagonal);
    goEngineInterface->startGame(diagonal, JAPANESE, AGREEMENT);

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



void GoGame::printStonesEatenByWhite() const noexcept
{
    //TODO
}

void GoGame::printBoard()
{
    //TODO
}
void GoGame::printStonesEatenByBlack() const noexcept
{

}

void GoGame::inputDiagonal( int& diagonal )
{
    bool isCorrectInput = true;
    std::string input;
    while( isCorrectInput )
    {
        printDiagonalInputMessage();
        std::getline(std::cin, input);
        isCorrectInput = !isDiagonalCorrect(input);
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






























