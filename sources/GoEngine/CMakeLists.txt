#GoEngine

set(srcFiles
        enums.h
        GoEngineInterface.cpp GoEngineInterface.h
        Point.cpp Point.h
        Board.cpp Board.h


        IncorrectDiagonalException.h

        Rules/Moves.cpp Rules/Moves.h
        Rules/Motion.cpp Rules/Motion.h
        Rules/ScoreCalculator.cpp Rules/ScoreCalculator.h

        Rules/Exceptions/MoveException.h
        Rules/Exceptions/MoveOutsideTheBoardException.h
        Rules/Exceptions/MoveToNotEmtyPointException.h
        Rules/Exceptions/MoveRepeatException.h
        Rules/Exceptions/MoveToDieException.h)

add_library(GoEngine STATIC ${srcFiles})