cmake_minimum_required(VERSION 4.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)
set(CMAKE_CXX_MODULE_STD ON)

project("task1" LANGUAGES CXX)

add_library(interface STATIC)
target_sources(interface
    PUBLIC
    FILE_SET CXX_MODULES
    FILES
    interfaces/interface.cppm
    interfaces/ICollection.cppm
    interfaces/IEnumerable.cppm
    interfaces/IEnumerator.cppm
)

add_library(collections STATIC)
target_sources(collections
    PUBLIC
    FILE_SET CXX_MODULES
    FILES
    collections/collections.cppm
    collections/Dictionary.cppm
    collections/HashSet.cppm
    collections/List.cppm
    collections/Queue.cppm
    collections/Stack.cppm
)
target_link_libraries(collections PUBLIC interface)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    collections
)
