cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_MODULE_STD ON)   

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

project(Practice9 LANGUAGES CXX)                                                           

find_package(libzip CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(Practice9 PUBLIC cxx_std_23)

target_link_libraries(${PROJECT_NAME} PRIVATE libzip::zip)