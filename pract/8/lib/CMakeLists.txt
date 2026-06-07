cmake_minimum_required(VERSION 4.3.2)

set(CMAKE_CXX_MODULE_STD)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)

project("lib" CXX)

add_executable("${PROJECT_NAME}")

target_sources("${PROJECT_NAME}" 
	PRIVATE 
		"main.cpp" 
	PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
		"collections.api.cppm" 
		"collections.list.cppm" 
		"collections.hash-set.cppm" 
		"collections.dictionary.cppm" 
		"collections.stack.cppm" 
		"collections.queue.cppm"
)