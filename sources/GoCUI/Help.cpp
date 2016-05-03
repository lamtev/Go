#include "Help.h"

void Help::printHelp() const noexcept
{
    printTitle();
    printConsoleArgs();
    emptyLine();
    printAllStepsOfGame();
    printExit();
    emptyLine();
    printGameProcessOnly();
    printMove();
    printPass();
    printSurrender();
    emptyLine();
}

void Help::printConsoleArgs() const noexcept
{
    printCommandsForConsoleArgs();
}

void Help::printCommandsForConsoleArgs() const noexcept
{
    std::cout << "For console arguments:" << std::endl;
}

void Help::printTitle() const noexcept
{
    std::cout << "Go Help" <<std::endl;
    std::cout << "Every command you can write by lower-case or upper-case" <<std::endl;
    std::cout << "Commands:" <<std::endl;
}

void Help::printAllStepsOfGame() const noexcept
{
    std::cout << "For all steps of game:" <<std::endl;
}

void Help::printExit() const noexcept
{
    std::cout << "exit          Exit Go" <<std::endl;
}

void Help::printGameProcessOnly() const noexcept
{
    std::cout <<  "For game process only:" <<std::endl;
}

void Help::printPass() const noexcept
{
    std::cout << "pass          Pass on your move" <<std::endl;
}

void Help::printSurrender() const noexcept
{
    std::cout << "surrender     Surrender this game" <<std::endl;
}

void Help::printMove() const noexcept
{
    std::cout << "<move>        A move of the format <littera><number>" <<std::endl;
}

void Help::emptyLine() const noexcept
{
    std::cout << std::endl;
}

