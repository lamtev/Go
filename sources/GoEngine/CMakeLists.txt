#GoEngine

set(srcFiles

        GoEngineInterface.h

        GoEngineAPI.cpp GoEngineAPI.h

        Model/Stone.cpp Model/Stone.h
        Model/Point.cpp Model/Point.h
        Model/Board.cpp Model/Board.h

        Model/Exceptions/IncorrectDiagonalException.h

        Rules/Move.cpp Rules/Move.h
        Rules/GameProcess.cpp Rules/GameProcess.h

        Rules/Exceptions/MoveException.h
        Rules/Exceptions/MoveOutsideTheBoardException.h
        Rules/Exceptions/MoveToNotEmtyPointException.h
        Rules/Exceptions/MoveRepeatException.h
        Rules/Exceptions/MoveToDieException.h)

add_library(GoEngine STATIC ${srcFiles})