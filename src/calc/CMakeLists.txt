add_executable(Calc Calc.cpp)

target_link_libraries(Calc CalcLib)

install(TARGETS Calc COMPONENT Main DESTINATION bin)
