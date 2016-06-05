#FunctionalTest

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(FTest functionalTest.cpp InitBoards.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)

target_link_libraries(FTest Qt5::Core)
find_library(FTest GoEngine)
target_link_libraries(FTest Qt5::Test)
target_link_libraries(FTest GoEngine)