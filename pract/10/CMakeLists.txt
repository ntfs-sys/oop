project(Practice10)                                                           

find_package(SFML CONFIG REQUIRED Graphics)
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
)
