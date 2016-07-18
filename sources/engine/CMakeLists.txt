#engine

set(ENGINE_SOURCE_FILES
        API.cpp API.h
        Stone.h
        PointLocation.h
        Point.h Point.cpp
        StoneGettingException.h Board.cpp Board.h Move.h PointLocationGettingException.h Moves.cpp Moves.h LastMovePoppingException.h PenultimateMoveGettingException.h LastMoveGettingException.h StoneSettingException.h StoneRemovingException.h)

add_library(engine STATIC ${ENGINE_SOURCE_FILES})