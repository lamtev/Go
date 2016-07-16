#engine

set(ENGINE_SOURCE_FILES
        API.cpp API.h
        Stone.h
        PointLocation.h
        Point.h Point.cpp)

add_library(engine STATIC ${ENGINE_SOURCE_FILES})