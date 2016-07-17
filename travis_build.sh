#!/usr/bin/env bash

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

cd .. && cloc CMakeLists.txt sources
cd sources && cppcheck -v -f --enable=all --language=c++ .
cd ../build/sources/tests && valgrind --leak-check=full --show-leak-kinds=all ./GoTest
./GoTest

