add_executable(Calc Calc.cpp)

if (${CONAN_LIBS})
	target_link_libraries(Calc ${CONAN_LIBS})
else()
	target_link_libraries(Calc CalcLib)
endif()

install(TARGETS Calc COMPONENT Main DESTINATION bin)
