#GoGUI

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)

set(src
        main.cpp
        Windows/Menu.cpp Windows/Menu.h
        Windows/StartGame.cpp Windows/StartGame.h
        Windows/Settings.cpp Windows/Settings.h
        Windows/Help.cpp Windows/Help.h Windows/Game.cpp Windows/Game.h Windows/Board.cpp Windows/Board.h)


qt5_add_resources(qrsrc
                        Resources/resources.qrc)
qt5_add_translation(i18n
                         Internationalization/i18n_ru.ts)

add_executable(GoGUI ${src} ${qrsrc} ${i18n})

target_link_libraries(GoGUI GoEngine)
target_link_libraries(GoGUI Qt5::Core)
target_link_libraries(GoGUI Qt5::Widgets)