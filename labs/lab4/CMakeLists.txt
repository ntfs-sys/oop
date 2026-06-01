cmake_minimum_required(VERSION 4.1.1)

project(my-awesome-project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_STD 1)

add_executable(awesome)

target_sources(awesome
  PRIVATE
    main.cpp
)

target_sources(awesome
  PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
      Character.cppm
      gamelib.cppm
	  V_model.cppm
	  Earthmover.cppm
	  Angel.cppm
	  Something_wicked.cppm
)
