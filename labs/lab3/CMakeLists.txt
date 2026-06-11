cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)


project(lab3, CXX)

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