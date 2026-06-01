export module odd_vector;
import std;

export std::vector<int> input_rand_vector(int amount){
	std::random_device rng;
	std::vector<int> v;
	for(int i = 0; i < amount; i++){
		v.push_back(rng()%100);
	}
	return v;
}

export std::vector<int> input_vector(int amount){
	std::vector<int> v;
	for(int i = 0; i < amount; i++){
		int argument = 0;
		std::cin >> argument;
		v.push_back(argument);
	}
	return v;
}
export void print_vector(std::vector<int> v){
	for(int i = 0; i < v.size(); i++){
		std::print("{} ", v[i]);
	}
	std::print("\n");
}
export bool v_odd(std::vector<int> v){
	for(int i = 0; i < v.size(); i++){
		if(v[i]%2==0){
			return 0;
		}
	}
	return 1;
}