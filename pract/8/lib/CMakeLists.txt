cmake_minimum_required(VERSION 4.3.2)

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