#!/bin/bash

rm build/ -R
mkdir build
rm stage/ -R
mkdir stage
cd build
cmake .. -DBUILD_SHARED_LIBS=On -DBUILD_CALCULATORLIB=On -DCMAKE_INSTALL_PREFIX=$(pwd)/../stage
cmake --build .
cmake -P cmake_install.cmake 
