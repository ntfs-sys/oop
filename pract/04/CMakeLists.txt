project(lab2)
add_executable(Practice4)
target_compile_features(Practice4 PUBLIC cxx_std_23)

target_sources(Practice4
	PRIVATE
		"main.cpp"
)
