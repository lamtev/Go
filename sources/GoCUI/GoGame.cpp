#include "GoGame.h"

GoGame::GoGame( const int argc, char** argv ) noexcept : goEngineInterface(new GoEngineInterface{}),
                                                         help(new Help{}),
                                                         argc(argc),
                                                         argv(argv),
                                                         needMessage(false),
                                                         needHelp(false),
                                                         hasExceptionThrown(false),
                                                         exit(false){}

GoGame::GoGame( const GoGame& go ) noexcept : goEngineInterface(go.goEngineInterface),
                                              help(go.help),
                                              argc(go.argc),
                                              argv(go.argv),
                                              needMessage(go.needMessage),
                                              needHelp(go.needHelp),
                                              hasExceptionThrown(go.hasExceptionThrown),
                                              exit(go.exit){}

GoGame::~GoGame()
{
    delete goEngineInterface;
    delete help;
}

void GoGame::begin()
{
    if( configureGame() )
    {
        play();
        printWhoSurrendered();
        printWhoWon();
        if( !whoWon() && !exit )
        {
            printCalculateScores();
        }
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
        ifNeedPrintHelp();
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

void GoGame::ifNeedPrintHelp() noexcept
{
    if( needHelp )
    {
        help->printHelp();
        needHelp = false;
    }
}

void GoGame::switchParsedCommand( const std::string& command, int& first, int& second )
{
    switch( parseCommand(command, first, second) )
    {
    case static_cast<int>(TypeOfCommand::HELP) :
        needHelp = true;
        break;
    case static_cast<int>(TypeOfCommand::MOVE) :
        putStone(first, second);
        break;
    case static_cast<int>(TypeOfCommand::PASS) :
        pass();
        turnOnMessage("Contender passed his move");
        break;
    case static_cast<int>(TypeOfCommand::SURRENDER) :
        surrender();
        break;
    case static_cast<int>(TypeOfCommand::EXIT) :
        exit = this->isExit(command);
        break;
    case static_cast<int>(TypeOfCommand::ERROR) :
        return;
    default :
        break;
    }
}

int GoGame::parseCommand( const std::string& command, int& first, int& second ) noexcept
{
    if( isHelp(command) )
    {
        return static_cast<int>(TypeOfCommand::HELP);
    }
    else if( isPass(command) )
    {
        return static_cast<int>(TypeOfCommand::PASS);
    }
    else if( isSurrender(command) )
    {
        return static_cast<int>(TypeOfCommand::SURRENDER);
    }
    else if( isExit(command) )
    {
        return static_cast<int>(TypeOfCommand::EXIT);
    }
    else
    {
        parseFirstCoordinate(command, first);
        parseSecondCoordinate(command, second);
        return !needMessage ? static_cast<int>(TypeOfCommand::MOVE) : static_cast<int>(TypeOfCommand::ERROR);
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
        turnOnMessage("Command is wrong");
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
    std::istringstream iss{ number, std::istringstream::in };
    int coordinate;
    iss >> coordinate;
    if( !iss )
    {
        turnOnMessage("Command is wrong");
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
        turnOnMessage(e.what());
        play();
    }
}

void GoGame::turnOnMessage( const char* message ) noexcept
{
    needMessage = true;
    MESSAGE = std::string{ message };
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
    case static_cast<int>(Status::BLACK) :
        printBlackSurrendered();
        break;
    case static_cast<int>(Status::WHITE) :
        printWhiteSurrendered();
    default :
        break;
    }
}

void GoGame::printWhoWon() const noexcept
{
    switch( whoWon() )
    {
    case static_cast<int>(Status::BLACK) :
        printBlackWon();
        break;
    case static_cast<int>(Status::WHITE) :
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
    if( goEngineInterface->whoseMove() == static_cast<int>(Status::BLACK) )
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
    updateBoard();
    int diagonal = goEngineInterface->getDiagonal();
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

void GoGame::updateBoard() noexcept
{
    int diagonal = goEngineInterface->getDiagonal();
    for( int i = 1; i <= diagonal; ++i )
    {
        for( int j = 1; j <= diagonal; ++j )
        {
            switch( goEngineInterface->getIJPointsStatus(i, j) )
            {
            case static_cast<int>(Status::EMPTY) :
                board[j * (diagonal * 2 + 5) + 1 + 2 * i] = '.';
                break;
            case static_cast<int>(Status::BLACK) :
                board[j * (diagonal * 2 + 5) + 1 + 2 * i] = 'X';
                break;
            case static_cast<int>(Status::WHITE) :
                board[j * (diagonal * 2 + 5) + 1 + 2 * i] = 'O';
                break;
            default :
                break;
            }
        }
    }
    markLastMove();
}

void GoGame::markLastMove() noexcept
{
    int diagonal = goEngineInterface->getDiagonal();
    int moveIndex = goEngineInterface->getMoveIndex();

    Move penultMove{ goEngineInterface->getPenultMove() };
    if( penultMove.isNotPass() && moveIndex >= 2 )
    {
        board[penultMove.getSecond() * (diagonal * 2 + 5) + 2 * penultMove.getFirst()] = ' ';
        board[penultMove.getSecond() * (diagonal * 2 + 5) + 2 + 2 * penultMove.getFirst()] = ' ';
    }

    Move lastMove{ goEngineInterface->getLastMove() };
    if( lastMove.isNotPass() && moveIndex >= 1 )
    {
        board[lastMove.getSecond() * (diagonal * 2 + 5) + 2 * (lastMove.getFirst())] = '[';
        board[lastMove.getSecond() * (diagonal * 2 + 5) + 2 + 2 * (lastMove.getFirst())] = ']';
    }
}

void GoGame::printStonesEatenByBlack() const noexcept
{
    std::cout << "Stones eaten by black: " << goEngineInterface->getStonesEatenByBlack() << std::endl;
}

void GoGame::printStonesEatenByWhite() const noexcept
{
    std::cout << "Stones eaten by white: " << goEngineInterface->getStonesEatenByWhite() << std::endl;
}

bool GoGame::parseDiagonal( int& diagonal ) noexcept
{
    bool isInputIncorrect = true;
    std::string input;
    while( isInputIncorrect )
    {
        ifNeedPrintHelp();
        printDiagonalInputMessage();
        std::getline(std::cin, input);
        if( isExit(input) )
        {
            return false;
        }
        isInputIncorrect = !isDiagonalCorrect(input);
        if( isHelp(input) )
        {
            needHelp = true;
        }
    }
    diagonal = getDiagonal(input);
    return true;
}

void GoGame::printDiagonalInputMessage()
{
    std::cout << "Chose board diagonal" << std::endl;
    std::cout << "   (7, 13 or 19)" << std::endl;
}

bool GoGame::isDiagonalN( const std::string& input, const int n ) const noexcept
{
    std::ostringstream ss;
    ss.str("");
    ss << n;
    return !input.compare(ss.str());
}

bool GoGame::isDiagonalCorrect( const std::string& input ) const noexcept
{
    return isDiagonalN(input, 7) || isDiagonalN(input, 13) || isDiagonalN(input, 19);
}

int GoGame::getDiagonal( const std::string& input ) const noexcept
{
    if( isDiagonalN(input, 7) )
    {
        return 7;
    }
    else if( isDiagonalN(input, 13) )
    {
        return 13;
    }
    else if( isDiagonalN(input, 19) )
    {
        return 19;
    }
    return 0;
}

bool GoGame::isExit( const std::string& input ) const noexcept
{
    return (input.size() == 4) &&
           (input[0] == 'e' || input[0] == 'E') &&
           (input[1] == 'x' || input[1] == 'X') &&
           (input[2] == 'i' || input[2] == 'I') &&
           (input[3] == 't' || input[3] == 'T');
}

bool GoGame::isPass( const std::string& input ) const noexcept
{
    return (input.size() == 4) &&
           (input[0] == 'p' || input[0] == 'P') &&
           (input[1] == 'a' || input[1] == 'A') &&
           (input[2] == 's' || input[2] == 'S') &&
           (input[3] == 's' || input[3] == 'S');
}

bool GoGame::isSurrender( const std::string& input ) const noexcept
{
    return (input.size() == 9) &&
           (input[0] == 's' || input[0] == 'S') &&
           (input[1] == 'u' || input[1] == 'U') &&
           (input[2] == 'r' || input[2] == 'R') &&
           (input[3] == 'r' || input[3] == 'R') &&
           (input[4] == 'e' || input[4] == 'E') &&
           (input[5] == 'n' || input[5] == 'N') &&
           (input[6] == 'd' || input[6] == 'D') &&
           (input[7] == 'e' || input[7] == 'E') &&
           (input[8] == 'r' || input[8] == 'R');
}

bool GoGame::isHelp( const std::string& input ) const noexcept
{
    return (input.size() == 4) &&
           (input[0] == 'h' || input[0] == 'H') &&
           (input[1] == 'e' || input[1] == 'E') &&
           (input[2] == 'l' || input[2] == 'L') &&
           (input[3] == 'p' || input[3] == 'P');
}
void GoGame::printEatenStonesStat() const noexcept
{
    std::cout << std::endl;
    printStonesEatenByBlack();
    printStonesEatenByWhite();
}



void GoGame::printCalculateScores() const noexcept
{
    std::cout << "Calculate your scores" << std::endl;
}
