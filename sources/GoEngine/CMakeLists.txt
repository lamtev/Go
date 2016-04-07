#GoEngine

set(srcFiles
        enums.h
        GoEngineInterface.h
        GoEngineInterface.cpp
        Board.cpp
        Board.h
        BoundsViolationException.h
        IncorrectDiagonalException.h)

add_library(GoEngine STATIC ${srcFiles})