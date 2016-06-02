#include "GoGame.h"

GoGame::GoGame(const int argc, char **argv) noexcept : goEngineInterface{new GoEngineAPI{}},
                                                       help{new Help{}},
                                                       argc{argc},
                                                       argv{argv},
                                                       needMessage{false},
                                                       needHelp{false},
                                                       hasExceptionHandled{false},
                                                       exit{false} { }

GoGame::GoGame(const GoGame &go) noexcept : goEngineInterface{go.goEngineInterface},
                                            help{go.help},
                                            argc{go.argc},
                                            argv{go.argv},
                                            needMessage{go.needMessage},
                                            needHelp{go.needHelp},
                                            hasExceptionHandled{go.hasExceptionHandled},
                                            exit{go.exit} { }

GoGame::~GoGame() {
  delete goEngineInterface;
  delete help;
}

void GoGame::begin() {
  if (argc==2 && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))) {
    printHelp();
    return;
  }
  menu();
}

void GoGame::menu() {
  std::string command;
  printMenu();
  std::getline(std::cin, command);
  switch (parseCommand(command)) {
    case 1 :
    case static_cast<int>(TypeOfCommand::START_GAME) :
      startGame();
      return;
    case 2 :
    case static_cast<int>(TypeOfCommand::HELP) :
      printHelp();
      menu();
      return;
    case 3 :
    case static_cast<int>(TypeOfCommand::EXIT) :
      return;
    case static_cast<int>(TypeOfCommand::ERROR) :
      std::cout << "Command is wrong" << std::endl;
      std::cout << std::endl;
      menu();
      return;
  }
}

void GoGame::printMenu() const noexcept {
  std::cout << "1. Start game" << std::endl;
  std::cout << "2. Help" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cout << "Enter the number that matches a chosen" << std::endl;
  std::cout << "command or enter the command immediately" << std::endl;
}

int GoGame::parseCommand(const std::string &command) const noexcept {
  std::string tempCommand{command};
  std::transform(tempCommand.begin(), tempCommand.end(), tempCommand.begin(), toupper);
  if (MENU_COMMANDS.find(tempCommand)!=MENU_COMMANDS.end()) {
    return MENU_COMMANDS.at(tempCommand);
  }
  return static_cast<int>(TypeOfCommand::ERROR);
}

void GoGame::startGame() {
  if (configureGame()) {
    play();
    printWhoSurrendered();
    printWhoWon();
    if (!static_cast<bool>(whoWon()) && !exit) {
      printCalculateScores();
    }
    if (goEngineInterface->isGameOver()) {
      std::cout << "Game is over!!!" << std::endl;
      std::cout << std::endl;
      std::cout << "Would you like to play again? [y/n]" << std::endl;
      std::cout << "n - for quit to menu" << std::endl;
      std::string command;
      std::getline(std::cin, command);
      if (!command.compare("y")) {
        delete goEngineInterface;
        goEngineInterface = new GoEngineAPI{};
        startGame();
        return;
      }
      else if (!command.compare("n")) {
        delete goEngineInterface;
        goEngineInterface = new GoEngineAPI{};
        menu();
        return;
      }
    }
  }
}

bool GoGame::configureGame() {
  int diagonal;
  if (parseDiagonal(diagonal)) {
    initBoard(diagonal);
    goEngineInterface->startGame(diagonal, JAPANESE, AGREEMENT);
    return true;
  }
  return false;
}

void GoGame::initBoard(int diagonal) noexcept {
  board.resize((diagonal + 2)*(diagonal*2 + 5));
  switch (diagonal) {
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
      std::cout << "BUG" << std::endl;
      break;
  }
}

void GoGame::play() {
  int first, second;
  std::string command;
  startGameCycle(command, first, second);
}

void GoGame::startGameCycle(std::string &command, int &first, int &second) {
  while (!(goEngineInterface->isGameOver() || exit)) {
    ifNeedPrintHelp();
    printEatenStonesStat();
    printBoard();
    ifNeedPrintMessage();
    printWhoseMove();
    std::getline(std::cin, command);
    switchParsedCommand(command, first, second);
    if (hasExceptionHandled) {
      hasExceptionHandled = false;
      return;
    }
    if (goEngineInterface->isGameOver()) {
      needMessage = false;
    }
  }
}

void GoGame::ifNeedPrintMessage() noexcept {
  if (needMessage) {
    needMessage = false;
    printMessage();
  }
}

void GoGame::ifNeedPrintHelp() noexcept {
  if (needHelp) {
    needHelp = false;
    printHelp();
  }
}

void GoGame::switchParsedCommand(const std::string &command, int &first, int &second) {
  switch (parseCommand1(command, first, second)) {
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

int GoGame::parseCommand1(const std::string &command, int &first, int &second) noexcept {
  if (isHelp(command)) {
    return static_cast<int>(TypeOfCommand::HELP);
  }
  else if (isPass(command)) {
    return static_cast<int>(TypeOfCommand::PASS);
  }
  else if (isSurrender(command)) {
    return static_cast<int>(TypeOfCommand::SURRENDER);
  }
  else if (isExit(command)) {
    return static_cast<int>(TypeOfCommand::EXIT);
  }
  else {
    parseFirstCoordinate(command, first);
    parseSecondCoordinate(command, second);
    return !needMessage ? static_cast<int>(TypeOfCommand::MOVE) : static_cast<int>(TypeOfCommand::ERROR);
  }
}

void GoGame::parseFirstCoordinate(const std::string &command, int &first) noexcept {
  switch (command[0]) {
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
      turnOnMessage("Command is wrong: use help");
      break;
  }
}

void GoGame::parseSecondCoordinate(const std::string &command, int &second) noexcept {
  if (needMessage) {
    return;
  }
  std::string number;
  number = command.substr(1);
  std::istringstream iss{number, std::istringstream::in};
  int coordinate;
  iss >> coordinate;
  if (!iss) {
    turnOnMessage("Command is wrong: use help");
  }
  else {
    second = coordinate;
  }
}

void GoGame::putStone(const int first, const int second) {
  try {
    goEngineInterface->putStone(first, second);
  }
  catch (const MoveException &e) {
    hasExceptionHandled = true;
    turnOnMessage(e.what());
    //todo опа! рекусия и без выхода. Привет переполенному стэку! СПОРНО!!!
    play();
  }
}

void GoGame::turnOnMessage(const char *message) noexcept {
  needMessage = true;
  MESSAGE = std::string{message};
}

void GoGame::pass() const noexcept {
  goEngineInterface->pass();
}

void GoGame::surrender() const noexcept {
  goEngineInterface->surrender();
}

Status GoGame::whoSurrendered() const noexcept {
  return goEngineInterface->whoSurrendered();
}

Status GoGame::whoWon() const noexcept {
  return goEngineInterface->whoWon();
}

void GoGame::printWhoSurrendered() const noexcept {
  switch (whoSurrendered()) {
    case Status::BLACK :
      printBlackSurrendered();
      break;
    case Status::WHITE :
      printWhiteSurrendered();
    default :
      break;
  }
}

void GoGame::printWhoWon() const noexcept {
  switch (whoWon()) {
    case Status::BLACK :
      printBlackWon();
      break;
    case Status::WHITE :
      printWhiteWon();
      break;
    default :
      break;
  }
}

void GoGame::printMessage() const noexcept {
  std::cout << MESSAGE << std::endl;
}

void GoGame::printWhoseMove() const noexcept {
  if (goEngineInterface->whoseMove()==Status::BLACK) {
    std::cout << "Black's move" << std::endl;
  }
  else if (goEngineInterface->whoseMove()==Status::WHITE) {
    std::cout << "White's move" << std::endl;
  }
}

void GoGame::printBlackSurrendered() const noexcept {
  std::cout << "Black player has surrendered" << std::endl;
}

void GoGame::printWhiteSurrendered() const noexcept {
  std::cout << "White player has surrendered" << std::endl;
}

void GoGame::printBlackWon() const noexcept {
  std::cout << "Black player has won" << std::endl;
}

void GoGame::printWhiteWon() const noexcept {
  std::cout << "White player has won" << std::endl;
}

void GoGame::printBoard() {
  updateBoard();
  int diagonal = goEngineInterface->getDiagonal();
  for (int i = 0; i < (diagonal + 2)*(diagonal*2 + 5); ++i) {
    if (i%(diagonal*2 + 5)==0) {
      std::cout << std::endl;
    }
    std::cout << board[i];
  }
  std::cout << std::endl;
}

void GoGame::updateBoard() noexcept {
  int diagonal = goEngineInterface->getDiagonal();
  for (int i = 1; i <= diagonal; ++i) {
    for (int j = 1; j <= diagonal; ++j) {
      switch (goEngineInterface->getPointsStatus(i, j)) {
        case Status::EMPTY :
          board[j*(diagonal*2 + 5) + 1 + 2*i] = '.';
          break;
        case Status::BLACK :
          board[j*(diagonal*2 + 5) + 1 + 2*i] = 'X';
          break;
        case Status::WHITE :
          board[j*(diagonal*2 + 5) + 1 + 2*i] = 'O';
          break;
        default :
          break;
      }
    }
  }
  unmarkPenultMove();
  markLastMove();
}

void GoGame::unmarkPenultMove() noexcept {
  //TODO подумать об выделении метода
  Move penultMove{goEngineInterface->getPenultMove()};
  if (penultMove.isNotPass() && goEngineInterface->getMoveIndex() >= 3) {

    int leftCursorIndex = penultMove.getSecond()*(goEngineInterface->getDiagonal()*2 + 5) + 2*penultMove.getFirst();
    board[leftCursorIndex] = ' ';
    int rightCursorIndex =
        penultMove.getSecond()*(goEngineInterface->getDiagonal()*2 + 5) + 2 + 2*penultMove.getFirst();
    board[rightCursorIndex] = ' ';
  }
}

void GoGame::markLastMove() noexcept {
  Move lastMove{goEngineInterface->getLastMove()};
  if (lastMove.isNotPass() && goEngineInterface->getMoveIndex() >= 2) {
    int leftCursorIndex = lastMove.getSecond()*(goEngineInterface->getDiagonal()*2 + 5) + 2*lastMove.getFirst();
    board[leftCursorIndex] = '[';
    int rightCursorIndex = lastMove.getSecond()*(goEngineInterface->getDiagonal()*2 + 5) + 2 + 2*lastMove.getFirst();
    board[rightCursorIndex] = ']';
  }
}

bool GoGame::parseDiagonal(int &diagonal) noexcept {
  bool isInputIncorrect = true;
  std::string input;
  while (isInputIncorrect) {
    ifNeedPrintHelp();
    printDiagonalInputMessage();
    std::getline(std::cin, input);
    if (isExit(input)) {
      return false;
    }
    isInputIncorrect = !isDiagonalCorrect(input);
    if (isHelp(input)) {
      needHelp = true;
    }
  }
  diagonal = getDiagonal(input);
  return true;
}

void GoGame::printDiagonalInputMessage() {
  std::cout << "Chose board diagonal" << std::endl;
  std::cout << "   (7, 13 or 19)" << std::endl;
}

bool GoGame::isDiagonalN(const std::string &input, const int n) const noexcept {
  std::ostringstream ss;
  ss.str("");
  ss << n;
  return !input.compare(ss.str());
}

bool GoGame::isDiagonalCorrect(const std::string &input) const noexcept {
  return isDiagonalN(input, 7) || isDiagonalN(input, 13) || isDiagonalN(input, 19);
}

int GoGame::getDiagonal(const std::string &input) const noexcept {
  if (isDiagonalN(input, 7)) {
    return 7;
  }
  else if (isDiagonalN(input, 13)) {
    return 13;
  }
  else if (isDiagonalN(input, 19)) {
    return 19;
  }
  return 0;
}

bool GoGame::isCommand(const std::string &input, const char *const command) const noexcept {
  std::string s{input};
  std::transform(s.begin(), s.end(), s.begin(), toupper);
  return !s.compare(command);
}

bool GoGame::isExit(const std::string &input) const noexcept {
  return isCommand(input, "EXIT");
}

bool GoGame::isPass(const std::string &input) const noexcept {
  return isCommand(input, "PASS");
}

bool GoGame::isSurrender(const std::string &input) const noexcept {
  return isCommand(input, "SURRENDER");
}

bool GoGame::isHelp(const std::string &input) const noexcept {
  return isCommand(input, "HELP");
}
void GoGame::printEatenStonesStat() const noexcept {
  std::cout << std::endl;
  std::cout << "Stones eaten by black: " << goEngineInterface->getStonesEatenByBlack() << std::endl;
  std::cout << "Stones eaten by white: " << goEngineInterface->getStonesEatenByWhite() << std::endl;
}


void GoGame::printCalculateScores() const noexcept {
  std::cout << "Calculate your scores" << std::endl;
}

void GoGame::printHelp() const noexcept {
  help->printHelp();
}
