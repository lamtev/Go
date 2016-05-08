#ifndef GO_ENUMS_H
#define GO_ENUMS_H

//todo лучше раскидать все енамы и константы по соответсвующим классам, а этот файл удалить
enum class TypeOfCommand
{
    ERROR = 0,
    EXIT,
    MOVE,
    PASS,
    SURRENDER,
    HELP
};

#endif //GO_ENUMS_H
