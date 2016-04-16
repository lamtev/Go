#GoEngine

set(srcFiles
        enums.h
        GoEngineInterface.cpp GoEngineInterface.h
        Stone.cpp Stone.h
        Board.cpp Board.h
        BoundsViolationException.h
        IncorrectDiagonalException.h
        Rules/Motion.cpp Rules/Motion.h
        Rules/ScoreCalculator.cpp Rules/ScoreCalculator.h
        Rules/MoveRepeatException.h
        Rules/MoveBeyondBoardException.h
        Rules/MoveToDieException.h
        Rules/Moves.cpp Rules/Moves.h
        Rules/MoveToNotEmtyPointException.h)

add_library(GoEngine STATIC ${srcFiles})