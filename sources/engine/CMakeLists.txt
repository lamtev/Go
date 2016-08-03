#engine

set(ENGINE_SOURCE_FILES
        API.h
        Stone.h
        PointLocation.h
        Point.h Point.cpp
        exceptions/StoneGettingException.h
        Board.cpp Board.h
        Move.h
        exceptions/PointLocationGettingException.h
        Moves.cpp Moves.h
        exceptions/LastMovePoppingException.h
        exceptions/PenultimateMoveGettingException.h
        exceptions/LastMoveGettingException.h
        exceptions/StoneSettingException.h
        exceptions/StoneRemovingException.h
        exceptions/GameIsOverException.h
        exceptions/MoveToNotEmptyPointException.h
        exceptions/MoveOutsideTheBoardException.h
        exceptions/MoveRepeatException.h
        exceptions/MoveToDieException.h
        Engine.cpp Engine.h)

add_library(engine STATIC ${ENGINE_SOURCE_FILES})