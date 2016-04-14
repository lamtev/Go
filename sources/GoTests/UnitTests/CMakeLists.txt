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

add_executable(MotionTest MotionTest.cpp)
target_link_libraries(MotionTest Qt5::Core)
target_link_libraries(MotionTest Qt5::Test)
target_link_libraries(MotionTest GoEngine)

add_executable(ScoreCalculatorTest ScoreCalculatorTest.cpp)
target_link_libraries(ScoreCalculatorTest Qt5::Core)
target_link_libraries(ScoreCalculatorTest Qt5::Test)
target_link_libraries(ScoreCalculatorTest GoEngine)