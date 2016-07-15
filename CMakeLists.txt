cmake_minimum_required(VERSION 3.2.2)
project(Go)
set(PROJECT_NAME_STR Go)

if(UNIX)
    set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ";/opt/qt56/lib/cmake;")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -pedantic -Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -fprofile-arcs")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
    add_definitions(-Wno-deprecated)
endif()

find_package(Threads REQUIRED)

set(EXT_DIR ${PROJECT_SOURCE_DIR}/ext)
add_subdirectory(${EXT_DIR}/googletest)
add_subdirectory(sources)