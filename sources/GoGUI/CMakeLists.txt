#GoGUI

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(src 
    main.cpp
    Counter.cpp Counter.h)

add_executable(GoGUI ${src})

target_link_libraries(GoGUI GoEngine)
target_link_libraries(GoGUI Qt5::Core)
target_link_libraries(GoGUI Qt5::Widgets)