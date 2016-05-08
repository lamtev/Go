#ifndef GO_ENUMS_H
#define GO_ENUMS_H

#include <map>
#include <string>

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

typedef bool (*pfunc)( const std::string& );

const std::map<std::string, int> MENU_COMMANDS{
        { "1",          1 },
        { "2",          2 },
        { "3",          3 },
        { "Start game", static_cast<int>(TypeOfCommand::START_GAME) },
        { "Help",       static_cast<int>(TypeOfCommand::HELP) },
        { "Exit",       static_cast<int>(TypeOfCommand::EXIT) },
};

#endif //GO_ENUMS_H
