#engine

set(ENGINE_SOURCE_FILES
        API.cpp API.h
        Stone.h
        PointLocation.h
        Point.h Point.cpp
        StoneNotFoundException.h Board.cpp Board.h Move.h PointLocationNotFoundException.h Moves.cpp Moves.h EmptyMovesListException.h PenultimateMoveNotFoundException.h LastMoveNotFoundException.h)

add_library(engine STATIC ${ENGINE_SOURCE_FILES})