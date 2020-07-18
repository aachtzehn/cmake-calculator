cmake_minimum_required (VERSION 3.1)

project (Calc)

include_directories(include)

add_subdirectory(src/pg)

add_subdirectory(src/calc)

add_subdirectory(test/pg)
