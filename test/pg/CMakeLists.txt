#add_subdirectory(/usr/src/googletest gtest)
#include_directories(/usr/local/include)

find_package(GTest REQUIRED)
find_package(Threads)
enable_testing()

add_executable(LibTest
				LibTest.cpp)
				
target_link_libraries(LibTest CalcLib gtest gtest_main gmock gmock_main Threads::Threads)