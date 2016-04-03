#GoEngine

set(srcFiles
        enums.h
        GoEngineInterface.h
        GoEngineInterface.cpp
        Stone.cpp
        Stone.h
        Board.cpp
        Board.h
        BoundsViolationException.h
        IncorrectDiagonalException.h)

add_library(GoEngine STATIC ${srcFiles})