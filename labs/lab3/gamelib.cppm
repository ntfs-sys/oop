export module gamelib;
import std;


export bool prob_aprox(int prob) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0, 10);
    return dis(gen) < prob;
}

export int int_input() {
    int result = 0;
    std::string buffer;
    while(std::getline(std::cin, buffer)) {
        std::stringstream ss(buffer);
        if (ss >> result && ss.eof()) {
            break;
        }
    }
    return result;
}
export void hello(int num){
		std::println("--------------------\n\
      LW: {}\n\
   Group: 6112\n\
  Author: Kirill Rezepkin\n\
  Option: 18\n\
--------------------", num);
}

