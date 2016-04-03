#GoCUI

set(srcFiles main.cpp)

add_executable(GoCUI main.cpp InitBoards.h)

target_link_libraries(GoCUI GoEngine)