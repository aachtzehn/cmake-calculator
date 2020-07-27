find_package(GTest REQUIRED)
find_package(Threads)
enable_testing()

add_executable(LibTest
	LibTest.cpp ${PROJECT_SOURCE_DIR}/src/pg/Adder.cpp ${PROJECT_SOURCE_DIR}/src/pg/Terminal.cpp )
				
target_link_libraries(LibTest gtest gtest_main gmock gmock_main Threads::Threads)
add_test(NAME MyLibTest COMMAND LibTest)

install(TARGETS LibTest COMPONENT QualityArtefacts DESTINATION share/test)
