project(lab2)
add_executable(Practice6)
target_compile_features(Practice6 PUBLIC cxx_std_23)

target_sources(Practice6
	PRIVATE
		"main.cpp"
)
