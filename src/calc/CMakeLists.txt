add_executable(Calc Calc.cpp)

target_link_libraries(Calc ${CONAN_LIBS})

install(TARGETS Calc COMPONENT Main DESTINATION bin)
