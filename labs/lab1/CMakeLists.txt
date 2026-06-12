
project(lab1)
add_executable(lab1)
target_compile_features(lab1 PUBLIC cxx_std_23)

target_sources(lab1
	PRIVATE
		"main.cpp"
)
