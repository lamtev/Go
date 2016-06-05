#UnitTests

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(StoneTest StoneTest.cpp)
find_library(StoneTest GoEngine)
target_link_libraries(StoneTest Qt5::Core)
target_link_libraries(StoneTest Qt5::Test)
target_link_libraries(StoneTest GoEngine)

add_executable(PointTest PointTest.cpp)
find_library(PointTest GoEngine)
target_link_libraries(PointTest Qt5::Core)
target_link_libraries(PointTest Qt5::Test)
target_link_libraries(PointTest GoEngine)

add_executable(BoardTest BoardTest.cpp)
find_library(BoardTest GoEngine)
target_link_libraries(BoardTest Qt5::Core)
target_link_libraries(BoardTest Qt5::Test)
target_link_libraries(BoardTest GoEngine)

add_executable(MoveTest MoveTest.cpp)
find_library(MoveTest GoEngine)
target_link_libraries(MoveTest Qt5::Core)
target_link_libraries(MoveTest Qt5::Test)
target_link_libraries(MoveTest GoEngine)

add_executable(GameProcessTest GameProcessTest.cpp)
find_library(GameProcessTest  GoEngine)
target_link_libraries(GameProcessTest Qt5::Core)
target_link_libraries(GameProcessTest Qt5::Test)
target_link_libraries(GameProcessTest GoEngine)
