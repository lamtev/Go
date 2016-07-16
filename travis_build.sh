#!/usr/bin/env bash

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

cd .. && cloc CMakeLists.txt sources
cd sources && cppcheck -v -f --enable=warning,performance,portability,style --language=c++ *
cd ../build/sources/tests && valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./GoTest
ctest -VV

