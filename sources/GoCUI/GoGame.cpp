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
    parseDiagonal(diagonal);
    goEngineInterface->startGame(diagonal, JAPANESE, AGREEMENT);
}

void GoGame::play()
{
    bool isExit = false;
    int first, second;
    std::string command;
    startGameCycle(command, first, second, isExit);

}

void GoGame::startGameCycle( std::string& command, int& first, int& second, bool& isExit )
{
    while( !goEngineInterface->isGameOver() && !isExit )
    {
        printEatenStonesStat();
        printBoard();
        ifNeedPrintMessage();
        printWhoseMove();
        std::getline(std::cin, command);
        switchParsedCommand(command, first, second, isExit);
    }
    switchWhoSurrendered();
}


void GoGame::ifNeedPrintMessage() noexcept
{
    if( needMessage )
    {
        printMessage();
        needMessage = false;
    }
}


void GoGame::switchParsedCommand( const std::string& command, int& first, int& second, bool& isExit )
{
    switch( parseCommand(command, first, second) )
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
    case ERROR :
        return;
    default :
        break;
    }
}

int GoGame::parseCommand( const std::string& command, int& first, int& second ) noexcept
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
        parseFirstCoordinate(command, first);
        parseSecondCoordinate(command, second);
        return !needMessage ? MOVE : ERROR;
    }
}

void GoGame::parseFirstCoordinate( const std::string& command, int& first ) noexcept
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
        needMessage = true;
        MESSAGE = std::string("wrong command");
        break;
    }
}

void GoGame::parseSecondCoordinate( const std::string& command, int& second ) noexcept
{
    if( needMessage )
    {
        return;
    }
    std::string number;
    number = command.substr(1);
    std::istringstream iss(number, std::istringstream::in);
    int coordinate;
    iss >> coordinate;
    if( !iss )
    {
        needMessage = true;
        MESSAGE = std::string("wrong command");
    }
    else
    {
        second = coordinate;
    }
}

void GoGame::putStone( const int first, const int second )
{
    try
    {
        goEngineInterface->putStone(first, second);
    }
    catch( BoundsViolationException& e )
    {
        needMessage = true;
        MESSAGE = std::string(e.what());
        play();
    }
    catch( MoveToNotEmptyPointException& e )
    {
        //TODO exception handling MoveToNotEmptyPointException
    }
    catch( MoveRepeatException& e )
    {
        //TODO exception handling MoveRepeatException
    }
    catch( MoveToDieException& e )
    {
        //TODO exception handling MoveToDieException
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

void GoGame::printMessage() const noexcept
{
    std::cout <<  MESSAGE << std::endl;
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
    //TODO print interactive board
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
    std::cout << "Stones eaten by black: " << goEngineInterface->getStonesEatenByBlack() << std::endl;
}

void GoGame::printStonesEatenByWhite() const noexcept
{
    std::cout << "Stones eaten by white: " << goEngineInterface->getStonesEatenByWhite() << std::endl;
}

void GoGame::parseDiagonal( int& diagonal )
{
    bool isInputIncorrect = true;
    std::string input;
    while( isInputIncorrect )
    {
        printDiagonalInputMessage();
        std::getline(std::cin, input);
        isInputIncorrect = !isDiagonalCorrect(input);
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


