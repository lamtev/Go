#tests
cmake_minimum_required(VERSION 3.2.2)

enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME}Test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

set(TEST_SRC_FILES
        TestPoint.cpp
        TestBoard.cpp
        TestMoves.cpp
        TestMoveAnalyser.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)

if(NOT WIN32)
    target_link_libraries(${PROJECT_TEST_NAME}
            ${GTEST_LIBS_DIR}/libgtest.a
            ${GTEST_LIBS_DIR}/libgtest_main.a
            engine
            )
else()
    target_link_libraries(${PROJECT_TEST_NAME}
            debug
            ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
            optimized
            ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
            engine
            )
    target_link_libraries(${PROJECT_TEST_NAME}
            debug
            ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
            optimized
            ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
            engine
            )
endif()

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(test ${PROJECT_TEST_NAME})