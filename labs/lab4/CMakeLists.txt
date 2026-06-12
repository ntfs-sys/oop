project(lab4)

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
