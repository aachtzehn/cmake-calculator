cmake_minimum_required (VERSION 3.1)

project (Calc)

# not the most elegant way - replace by inplace replacement
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	conan_basic_setup()
endif()

include(CTest)

include_directories(include)

option(BUILD_CALCULATOR "Build the calculator" OFF)
option(BUILD_CALCULATORLIB "Build calculator library" OFF)


if (BUILD_CALCULATORLIB)
	add_subdirectory(src/pg)
	add_subdirectory(include)
endif()

if (BUILD_CALCULATOR)
	add_subdirectory(src/calc)
endif()

if (BUILD_CALCULATORLIB AND BUILD_TESTING)
	add_subdirectory(test/pg)
endif()

