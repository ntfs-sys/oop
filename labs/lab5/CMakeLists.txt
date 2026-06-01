cmake_minimum_required(VERSION 3.20)

project(awesome)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(awesome main.cpp lang_analyse.cppm stop_words.cppm)