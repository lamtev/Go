cmake_minimum_required(VERSION 3.0)
project(Go)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11")

add_subdirectory(GoEngine)
add_subdirectory(GoCUI)
add_subdirectory(GoGUI)
add_subdirectory(GoTests)








