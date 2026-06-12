project(lab3)

add_executable(lab3)

target_compile_features(lab3  PUBLIC cxx_std_23)
target_sources(
	lab3 
	PRIVATE 
		main.cpp
	PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES 
		"Character.cppm"
		"gamelib.cppm"
)