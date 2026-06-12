project(lab2)
add_executable(Practice5)
target_compile_features(Practice5 PUBLIC cxx_std_23)

target_sources(Practice5
	PRIVATE
		"main.cpp"
)
