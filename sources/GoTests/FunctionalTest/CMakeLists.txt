#FunctionalTest

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(functionalTest functionalTest.cpp)

#find_package(Qt5Core REQUIRED)
#find_package(Qt5Test REQUIRED)

#target_link_libraries(functionalTest Qt5::Core)
#target_link_libraries(functionalTest Qt5::Test)
target_link_libraries(functionalTest GoEngine)