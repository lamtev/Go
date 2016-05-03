#ifndef GO_HELP_H
#define GO_HELP_H

#include <iostream>

class Help
{

public :

    /**
     * Вывести на экран Help
     */
    void printHelp() const noexcept;

private :

    void printConsoleArgs() const noexcept;
    void printCommandsForConsoleArgs() const noexcept;
    void printTitle() const noexcept;
    void printAllStepsOfGame() const noexcept;
    void printGameProcessOnly() const noexcept;
    void printExit() const noexcept;
    void printPass() const noexcept;
    void printSurrender() const noexcept;
    void printMove() const  noexcept;
    void emptyLine() const noexcept;
};


#endif //GO_HELP_H
