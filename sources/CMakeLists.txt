cmake_minimum_required(VERSION 2.8.11)

project(Go)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(GoEngine)
add_subdirectory(GoCUI)
add_subdirectory(GoTests)

