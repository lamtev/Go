#UnitTests

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(BoardTest BoardTest.cpp)
target_link_libraries(BoardTest Qt5::Core)
target_link_libraries(BoardTest Qt5::Test)
target_link_libraries(BoardTest GoEngine)

add_executable(StoneTest StoneTest.cpp)
target_link_libraries(StoneTest Qt5::Core)
target_link_libraries(StoneTest Qt5::Test)
target_link_libraries(StoneTest GoEngine)