#GoGUI

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(src
        main.cpp
        Windows/Menu.cpp Windows/Menu.h
        Windows/Game.cpp Windows/Game.h
        Windows/Settings.cpp Windows/Settings.h
        Windows/Help.cpp Windows/Help.h)


qt5_add_resources(qrsrc Resources/resources.qrc)

add_executable(GoGUI ${src} ${qrsrc})

target_link_libraries(GoGUI GoEngine)
target_link_libraries(GoGUI Qt5::Core)
target_link_libraries(GoGUI Qt5::Widgets)