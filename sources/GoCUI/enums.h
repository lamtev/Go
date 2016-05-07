#ifndef GO_ENUMS_H
#define GO_ENUMS_H

#include <vector>
#include <map>

enum class TypeOfCommand
{
    ERROR = 4,
    EXIT,
    MOVE,
    PASS,
    SURRENDER,
    HELP,
    START_GAME
};

const std::map<std::string, int> map{
        { "1", 1 },
        { "2", 2 },
        { "3", 3 },
        { "Start game", static_cast<int>(TypeOfCommand::START_GAME) },
        { "Help", static_cast<int>(TypeOfCommand::HELP) },
        { "Exit", static_cast<int>(TypeOfCommand::EXIT) },
        { "pass", static_cast<int>(TypeOfCommand::PASS) },
        { "surrender", static_cast<int>(TypeOfCommand::SURRENDER) }

};

const std::vector<std::string> mainMenuCommands{
        "1",
        "2",
        "3",
        "Start",
        "Start game",
        "Help",
        "Exit"
};

#endif //GO_ENUMS_H
