project(lab5)

add_executable(lab5)

target_compile_features(lab5 PUBLIC cxx_std_23)

target_sources(lab5 
    PRIVATE 
        main.cpp 
    PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES 
        "lang_analyse.cppm" 
        "stop_words.cppm"
        )