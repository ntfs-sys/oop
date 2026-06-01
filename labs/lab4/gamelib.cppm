export module gamelib;
import std;

export namespace color {
    constexpr std::string_view red     = "\033[31m";
    constexpr std::string_view green   = "\033[32m";
    constexpr std::string_view yellow  = "\033[33m";
    constexpr std::string_view blue    = "\033[34m";
    constexpr std::string_view magenta = "\033[35m";
    constexpr std::string_view cyan    = "\033[36m";
    constexpr std::string_view reset   = "\033[0m";
}
export std::string input_string(const std::string& prompt) {
    std::string value;

    while (true) {
        std::println("{}", prompt);
        std::getline(std::cin >> std::ws, value);

        if (!value.empty())
            return value;

        std::println("Invalid input, try again");
    }
}
export int input_int(const std::string& prompt, int min, int max) {
    std::string line;

    while (true) {
        std::println("{}", prompt);
        std::getline(std::cin >> std::ws, line);

        std::stringstream ss(line);
        int value;
        char extra;

        if (!(ss >> value) || (ss >> extra)) {
            std::println("Invalid number, try again");
            continue;
        }

        if (value < min || value > max) {
            std::println("Value must be between {} and {}", min, max);
            continue;
        }

        return value;
    }
}

std::mt19937 rng{std::random_device{}()};

export int random_int(int min, int max) {
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}
export void hello(int num){
		std::println("--------------------\n\
      LW: {}\n\
   Group: 6112\n\
  Author: Kirill Rezepkin\n\
  Option: 18\n\
--------------------", num);
}