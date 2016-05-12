#GoCUI

set(srcFiles main.cpp)

add_executable(GoCUI main.cpp InitBoards.h GoGame.cpp GoGame.h Help.cpp Help.h)

target_link_libraries(GoCUI GoEngine)