#GoGUI

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)

set(src
        main.cpp
        Windows/MenuWindow.cpp Windows/MenuWindow.h
        Windows/SettingsWindow.cpp Windows/SettingsWindow.h
        Windows/HelpWindow.cpp Windows/HelpWindow.h
        Windows/GameWindow.cpp Windows/GameWindow.h Windows/Widgets/BoardWidget.cpp Windows/Widgets/BoardWidget.h)


qt5_add_resources(qrsrc
                        Resources/resources.qrc)
qt5_add_translation(i18n
                         Internationalization/i18n_ru.ts)

add_executable(GoGUI ${src} ${qrsrc} ${i18n})

target_link_libraries(GoGUI GoEngine)
target_link_libraries(GoGUI Qt5::Core)
target_link_libraries(GoGUI Qt5::Widgets)