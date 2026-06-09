cmake_minimum_required(VERSION 4.3.2)

set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)

project(lab5 CXX)

add_executable(lab5)

target_compile_features(lab5 PUBLIC cxx_std_23)

target_sources(lab5 
    PRIVATE 
        main.cpp 
    PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES 
        "lang_analyse.cppm" 
        "stop_words.cppm"
        )