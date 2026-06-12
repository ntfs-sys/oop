project(lab2)
add_executable(Practice3)
target_compile_features(Practice3 PUBLIC cxx_std_23)
target_sources(Practice3
	PRIVATE
		"main.cpp"
)
