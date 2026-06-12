project(Practice9)                                                           

find_package(libzip CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(Practice9 PUBLIC cxx_std_23)

target_link_libraries(${PROJECT_NAME} PRIVATE libzip::zip)