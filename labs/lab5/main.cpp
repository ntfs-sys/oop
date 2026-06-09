import std;
import lang_analyse;
import stop_words;

int main() {
    std::string filename;

    std::println("Введите путь к файлу:");
    std::getline(std::cin, filename);

    if (filename.empty()) {
        std::println("Файл не выбран");
        return 1;
    }
	
    auto words = load_words(filename);

    std::println("Всего слов: {}", words.size());

    std::size_t unique = count_unique(words, stop_words);
    std::println("Уникальных слов (без стоп-слов): {}", unique);

    auto freq = get_freq(words, stop_words);
	
    std::vector<std::pair<std::string, int>> vec(freq.begin(), freq.end());

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    int amount = 0;
    std::println("Сколько топ слов вывести?");
    
    if (!(std::cin >> amount) || amount <= 0) {
        std::println("Некорректный ввод");
        return 1;
    }

    int limit = std::min(amount, (int)vec.size());

    std::println("\nТоп-{} слов:\n", limit);

	auto top = top_n_words(words, stop_words, amount);

	for (const auto& [count, group] : top) {
		std::print("{}: ", count);
		for (const auto& w : group) {
			std::print("\"{}\" ", w);
		}
		std::println("");
	}
	return 0;
}