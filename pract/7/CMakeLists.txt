cmake_minimum_required(VERSION 4.3.2)                                       
set(CMAKE_CXX_MODULE_STD ON)                                                
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
project(lab2 CXX)                                                           
add_executable(awesome)                                                     
target_compile_features(awesome PUBLIC cxx_std_23)                          
target_sources(awesome                                                      
PRIVATE                                                                     "main.cpp") 