cmake_minimum_required(VERSION 4.3.2)
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
project(lab1 CXX)
add_executable(lab1)
target_compile_features(lab1 PUBLIC cxx_std_23)

target_sources(lab1
	PRIVATE
		"main.cpp"
)
