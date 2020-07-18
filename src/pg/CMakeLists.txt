add_library(CalcLib
			Terminal.cpp
			Adder.cpp)

set_property(TARGET CalcLib PROPERTY POSITION_INDEPENDENT_CODE TRUE)