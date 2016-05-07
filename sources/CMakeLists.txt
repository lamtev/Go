cmake_minimum_required(VERSION 2.8.12.2)

project(Go)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++14 -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} -std=c++14")

add_subdirectory(GoEngine)
add_subdirectory(GoCUI)
add_subdirectory(GoGUI)
add_subdirectory(GoTests)

