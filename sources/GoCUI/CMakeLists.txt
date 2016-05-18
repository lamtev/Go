#GoCUI

set(src
        main.cpp
        InitBoards.h
        GoGame.cpp GoGame.h
        Help.cpp Help.h)

add_executable(GoCUI ${src})

target_link_libraries(GoCUI GoEngine)