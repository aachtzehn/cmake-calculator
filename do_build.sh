#!/bin/bash -x

rm build/ -R
mkdir build
rm stage/ -R
mkdir stage
cd build
cmake .. -DBUILD_SHARED_LIBS=On -DBUILD_CALCULATORLIB=On -DCMAKE_INSTALL_PREFIX=$(pwd)/../stage -DBUILD_TESTING=On -DCMAKE_VERBOSE_MAKEFILE=On
cmake --build .
ctest .
cmake -P cmake_install.cmake

