project(lab2)
add_executable(lab2)
target_compile_features(lab2 PUBLIC cxx_std_23)

target_sources(lab2
	PRIVATE
		"main.cpp"
	PRIVATE FILE_SET odd_vector TYPE CXX_MODULES FILES
		"odd_vector.cppm"
)
