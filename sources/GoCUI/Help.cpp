#include "Help.h"

void Help::printHelp() const noexcept {
  emptyLine();
  printTitle();
  printConsoleArgs();
  std::cout << "-h, --help    Open help only" << std::endl;
  emptyLine();
  printAllStepsOfGame();
  printExit();
  emptyLine();
  printGameProcessOnly();
  printMove();
  printPass();
  printSurrender();
  emptyLine();
  printSmthAbtGame();
}

void Help::printConsoleArgs() const noexcept {
  printCommandsForConsoleArgs();
}

void Help::printCommandsForConsoleArgs() const noexcept {
  std::cout << "For console arguments:" << std::endl;
}

void Help::printTitle() const noexcept {
  std::cout << "Go Help" << std::endl;
  emptyLine();
  std::cout << "Every command you can write by lower-case or upper-case" << std::endl;
  std::cout << "Commands:" << std::endl;
  emptyLine();
}

void Help::printAllStepsOfGame() const noexcept {
  std::cout << "For all steps of game:" << std::endl;
}

void Help::printExit() const noexcept {
  std::cout << "exit          Exit Go" << std::endl;
}

void Help::printGameProcessOnly() const noexcept {
  std::cout << "For game process only:" << std::endl;
}

void Help::printPass() const noexcept {
  std::cout << "pass          Pass on your move" << std::endl;
}

void Help::printSurrender() const noexcept {
  std::cout << "surrender     Surrender this game" << std::endl;
}

void Help::printMove() const noexcept {
  std::cout << "<move>        A move of the format <litera><number>" << std::endl;
}

void Help::emptyLine() const noexcept {
  std::cout << std::endl;
}

void Help::printSmthAbtGame() const noexcept {
  std::cout << "X - black" << std::endl;
  std::cout << "O - white" << std::endl;
  emptyLine();
}



