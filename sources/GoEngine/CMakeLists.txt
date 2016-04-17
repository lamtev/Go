#GoEngine

set(srcFiles
        enums.h
        GoEngineInterface.cpp GoEngineInterface.h
        Point.cpp Point.h
        Board.cpp Board.h
        BoundsViolationException.h
        IncorrectDiagonalException.h
        Rules/Motion.cpp Rules/Motion.h
        Rules/Moves.cpp Rules/Moves.h
        Rules/ScoreCalculator.cpp Rules/ScoreCalculator.h
        Rules/MoveRepeatException.h
        Rules/MoveBeyondBoardException.h
        Rules/MoveToDieException.h
        Rules/MoveToNotEmtyPointException.h )

add_library(GoEngine STATIC ${srcFiles})