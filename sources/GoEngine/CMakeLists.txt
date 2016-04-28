#GoEngine

set(srcFiles
        enums.h
        GoEngineInterface.cpp GoEngineInterface.h
        Point.cpp Point.h
        Board.cpp Board.h


        Exceptions/IncorrectDiagonalException.h

        Rules/Move.cpp Rules/Move.h
        Rules/Motion.cpp Rules/Motion.h
        Rules/ScoreCalculator.cpp Rules/ScoreCalculator.h

        Rules/Exceptions/MoveException.h
        Rules/Exceptions/MoveOutsideTheBoardException.h
        Rules/Exceptions/MoveToNotEmtyPointException.h
        Rules/Exceptions/MoveRepeatException.h
        Rules/Exceptions/MoveToDieException.h Stone.cpp Stone.h)

add_library(GoEngine STATIC ${srcFiles})