import lang_analyse;
import stop_words;
import std;

int main(){
    hello(5);
    std::println("do you know the way?");
    std::string path;
    std::getline(std::cin, path);
    std::vector<std::string> words = load_words(path);
    std::println("unique:{}", count_unique(words, stop_words));
    freq_printer(most_common(words, stop_words));
    int amount = 0;
    std::cin >> amount;
    auto top = top_n_words(words, stop_words, amount);
    for(const auto& freq : top){
        freq_printer(freq);
    }
    return 0;
}