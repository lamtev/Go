#include "GoGame.h"

GoGame::GoGame()
{
    goEngineInterface = new GoEngineInterface{};
}

GoGame::~GoGame()
{
    delete goEngineInterface;
}

void GoGame::begin()
{
    if( configureGame() )
    {
        play();
        printWhoSurrendered();
        printWhoWon();
    }
}

bool GoGame::configureGame()
{
    int diagonal;
    if( parseDiagonal(diagonal) )
    {
        initBoard(diagonal);
        goEngineInterface->startGame(diagonal, JAPANESE, AGREEMENT);
        return true;
    }
    return false;
}

void GoGame::initBoard( int diagonal ) noexcept
{
    board.resize((diagonal + 2) * (diagonal * 2 + 5));
    switch( diagonal )
    {
    case 7 :
        board = BOARD7;
        break;
    case 13 :
        board = BOARD13;
        break;
    case 19 :
        board = BOARD19;
        break;
    default :
        break;
    }
}

void GoGame::play()
{
    int first, second;
    std::string command;
    startGameCycle(command, first, second);
}

void GoGame::startGameCycle( std::string& command, int& first, int& second )
{
    while( !(goEngineInterface->isGameOver() || exit) )
    {
        printEatenStonesStat();
        printBoard();
        ifNeedPrintMessage();
        printWhoseMove();
        std::getline(std::cin, command);
        switchParsedCommand(command, first, second);
        if( hasExceptionThrown )
        {
            hasExceptionThrown = false;
            return;
        }
    }
}

void GoGame::ifNeedPrintMessage() noexcept
{
    if( needMessage )
    {
        printMessage();
        needMessage = false;
    }
}


void GoGame::switchParsedCommand( const std::string& command, int& first, int& second )
{
    switch( parseCommand(command, first, second) )
    {
    case MOVE :
        putStone(first, second);
        break;
    case PASS :
        pass();
        break;
    case SURRENDER :
        surrender();
        break;
    case EXIT :
        exit = this->isExit(command);
        break;
    case ERROR :
        return;
    default :
        break;
    }
}

int GoGame::parseCommand( const std::string& command, int& first, int& second ) noexcept
{
    if( isPass(command) )
    {
        return PASS;
    }
    else if( isSurrender(command) )
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
    case 'A' :
        first = A;
        break;
    case 'b' :
    case 'B' :
        first = B;
        break;
    case 'c' :
    case 'C' :
        first = C;
        break;
    case 'd' :
    case 'D' :
        first = D;
        break;
    case 'e' :
    case 'E' :
        first = E;
        break;
    case 'f' :
    case 'F' :
        first = F;
        break;
    case 'g' :
    case 'G' :
        first = G;
        break;
    case 'h' :
    case 'H' :
        first = H;
        break;
    case 'i' :
    case 'I' :
        first = I;
        break;
    case 'j' :
    case 'J' :
        first = J;
        break;
    case 'k' :
    case 'K' :
        first = K;
        break;
    case 'l' :
    case 'L' :
        first = L;
        break;
    case 'm' :
    case 'M' :
        first = M;
        break;
    case 'n' :
    case 'N' :
        first = N;
        break;
    case 'o' :
    case 'O' :
        first = O;
        break;
    case 'p' :
    case 'P' :
        first = P;
        break;
    case 'q' :
    case 'Q' :
        first = Q;
        break;
    case 'r' :
    case 'R' :
        first = R;
        break;
    case 's' :
    case 'S' :
        first = S;
        break;
    case 't' :
    case 'T' :
        first = T;
        break;
    case 'u' :
    case 'U' :
        first = U;
        break;
    case 'v' :
    case 'V' :
        first = V;
        break;
    case 'w' :
    case 'W' :
        first = W;
        break;
    case 'x' :
    case 'X' :
        first = X;
        break;
    case 'y' :
    case 'Y' :
        first = Y;
        break;
    case 'z' :
    case 'Z' :
        first = Z;
        break;
    default :
        needMessage = true;
        MESSAGE = std::string{"Command is wrong"};
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
    std::istringstream iss{number, std::istringstream::in};
    int coordinate;
    iss >> coordinate;
    if( !iss )
    {
        needMessage = true;
        MESSAGE = std::string{"Command is wrong"};
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
    catch( const MoveException& e )
    {
        hasExceptionThrown = true;
        needMessage = true;
        MESSAGE = std::string(e.what());
        play();
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

int GoGame::whoWon() const noexcept
{
    return goEngineInterface->whoWon();
}

void GoGame::printWhoSurrendered() const noexcept
{
    switch( whoSurrendered() )
    {
    case BLACK :
        printBlackSurrendered();
        break;
    case WHITE :
        printWhiteSurrendered();
    default :
        break;
    }
}

void GoGame::printWhoWon() const noexcept
{
    switch( whoWon() )
    {
    case BLACK :
        printBlackWon();
        break;
    case WHITE :
        printWhiteWon();
        break;
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

void GoGame::printBlackWon() const noexcept
{
    std::cout << "Black player has won" <<std::endl;
}

void GoGame::printWhiteWon() const noexcept
{
    std::cout << "White player has won" <<std::endl;
}

void GoGame::printBoard()
{
    int diagonal = goEngineInterface->getBoard().getDiagonal();
    for( int i = 0; i < (diagonal + 2) * (diagonal * 2 + 5); ++ i )
    {
        if (i % (diagonal * 2 + 5) == 0)
        {
            std::cout << std::endl;
        }
        std::cout << board[i];
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

bool GoGame::parseDiagonal( int& diagonal )
{
    bool isInputIncorrect = true;
    std::string input;
    while( isInputIncorrect )
    {
        printDiagonalInputMessage();
        std::getline(std::cin, input);
        if( isExit(input) )
        {
            return false;
        }
        isInputIncorrect = !isDiagonalCorrect(input);
    }
    diagonal = getDiagonal(input);
    return true;
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
    return !input.compare("exit") || !input.compare("EXIT");
}

bool GoGame::isPass( const std::string& input ) const noexcept
{
    return !input.compare("pass") || !input.compare("PASS");
}

bool GoGame::isSurrender( const std::string& input ) const noexcept
{
    return !input.compare("surrender") || !input.compare("SURRENDER");
}

void GoGame::printEatenStonesStat() const noexcept
{
    std::cout << std::endl;
    printStonesEatenByBlack();
    printStonesEatenByWhite();
}

