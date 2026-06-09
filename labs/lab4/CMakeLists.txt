cmake_minimum_required(VERSION 4.3.2)

set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)

project(lab4 CXX)

add_executable(lab4)

target_compile_features(lab4 PUBLIC cxx_std_23)
target_sources(lab4
  PRIVATE
    main.cpp
  PRIVATE
    FILE_SET "modules" TYPE CXX_MODULES
    FILES
    Character.cppm
    gamelib.cppm
	  V_model.cppm
	  Earthmover.cppm
	  Angel.cppm
	  Something_wicked.cppm
)
