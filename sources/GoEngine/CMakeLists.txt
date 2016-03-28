#GoEngine

set(src
        enums.h
        GoEngineInterface.h
        GoEngineInterface.cpp Stone.cpp Stone.h Board.cpp Board.h)

add_library(GoEngine STATIC ${src})