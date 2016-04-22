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
    bool isCommandIncorrect = false;
    int first, second;
    std::string command;
    startGameCycle(command, first, second, isExit, isCommandIncorrect);

}

void GoGame::startGameCycle( std::string& command, int& first, int& second, bool& isExit, bool& isCommandIncorrect )
{
    //BUG
    while( !goEngineInterface->isGameOver() && !isExit )
    {
        printEatenStonesStat();
        printBoard();
        ifNeedPrintCommandIncorrect(isCommandIncorrect);
        printWhoseMove();
        std::getline(std::cin, command);
        switchParsedCommand(command, first, second, isCommandIncorrect, isExit);
        if( goEngineInterface->isGameOver() )
        {
            std::cout << "BUG DETECTED" << std::endl;
        }
    }
    switchWhoSurrendered();
}

void GoGame::ifNeedPrintCommandIncorrect( bool& isCommandIncorrect ) const noexcept
{
    if( isCommandIncorrect )
    {
        printUnknownCommand();
        isCommandIncorrect = false;
    }
}


void GoGame::switchParsedCommand( const std::string& command, int& first, int& second, bool& isCommandIncorrect, bool& isExit )
{
    switch( parseCommand(command, first, second, isCommandIncorrect) )
    {
    case MOVE :
        putStone(first-1, second-1);
        break;
    case PASS :
        pass();
        break;
    case SURRENDER :
        surrender();
        break;
    case EXIT :
        isExit = this->isExit(command);
        break;
    default :
        break;
    }
}

int GoGame::parseCommand( const std::string& command, int& first, int& second, bool& isCommandIncorrect ) const noexcept
{
    if( !command.compare("pass") )
    {
        return PASS;
    }
    else if( !command.compare("surrender") )
    {
        return SURRENDER;
    }
    else if( isExit(command) )
    {
        return EXIT;
    }
    else
    {
        parseFirstCoordinate(command, first, isCommandIncorrect);
        parseSecondCoordinate(command, second, isCommandIncorrect);
        return MOVE;
    }
}

void GoGame::parseFirstCoordinate( const std::string& command, int& first, bool& isCommandIncorrect ) const noexcept
{
    switch( command[0] )
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
        isCommandIncorrect = true;
        break;
    }
}

void GoGame::parseSecondCoordinate( const std::string& command, int& second, bool& isCommandIncorrect ) const noexcept
{
    if( isCommandIncorrect )
    {
        return;
    }
    std::string number;
    number = command.substr(1);
    std::istringstream iss(number, std::istringstream::in);
    int coordinate;
    iss >> coordinate;
    !iss ? (isCommandIncorrect = true) : (second = coordinate);
}

void GoGame::putStone( const int first, const int second )
{
    //TODO exception handling
    try
    {
        goEngineInterface->putStone(first, second);
    }
    catch( BoundsViolationException& e )
    {

    }
    catch( MoveToNotEmptyPointException& e )
    {

    }
    catch( MoveRepeatException& e )
    {

    }
    catch( MoveToDieException& e )
    {

    }

}

void GoGame::pass() const noexcept
{
    goEngineInterface->pass();
}

void GoGame::surrender() const noexcept
{
    goEngineInterface->surrender();
}

int GoGame::whoSurrendered() const noexcept
{
    return goEngineInterface->whoSurrendered();
}

void GoGame::switchWhoSurrendered() const noexcept
{
    switch( whoSurrendered() )
    {
    case EMPTY :
        break;
    case BLACK :
        printBlackSurrendered();
        break;
    case WHITE :
        printWhiteSurrendered();
    default :
        break;
    }
}

void GoGame::printUnknownCommand() const noexcept
{
    std::cout <<  "Previous command was unknown" << std::endl;
}

void GoGame::printWhoseMove() const noexcept
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

void GoGame::printBlackSurrendered() const noexcept
{
    std::cout << "Black player has surrendered" <<std::endl;
}

void GoGame::printWhiteSurrendered() const noexcept
{
    std::cout << "White player has surrendered" <<std::endl;
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
    //TODO
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

void GoGame::printEatenStonesStat() const noexcept
{
    printStonesEatenByBlack();
    printStonesEatenByWhite();
}


