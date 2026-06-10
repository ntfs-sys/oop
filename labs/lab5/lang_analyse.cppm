export module lang_analyse;
import std;

export struct freq_vector {
    int freq;
    std::vector<std::string> words;
};

export void freq_printer(const freq_vector& vector){
    std::print("{} : ", vector.freq);
    for(const auto& word : vector.words){
        std::print("{} ", word);
    }
    std::println("");
}

export std::unordered_map<std::string, int> get_freq(const std::vector<std::string>& words, const std::unordered_set<std::string>& stop_set){
    std::unordered_map<std::string, int> result;
    for(const auto& word: words){
        if(stop_set.find(word) == stop_set.end()){
            result[word]++;
        }
    }
    return result;
}

export freq_vector most_common(const std::vector<std::string>& words, const std::unordered_set<std::string>& stop_set){
    auto freq = get_freq(words, stop_set);
    int max = 0;
    for(const auto & [word, count] : freq){
        if(count > max){max = count;}
    }
    std::vector<std::string> max_words;
    for(const auto & [word, count] : freq){
        if(count == max){max_words.push_back(word);}
    }
    std::sort(max_words.begin(), max_words.end());
    return {max, max_words};
}

export std::vector<freq_vector> top_n_words(const std::vector<std::string>& words, const std::unordered_set<std::string>& stop_set, int n
){
    if (n <= 0) { return {}; }
    auto freq = get_freq(words, stop_set);
    std::map<int, std::vector<std::string>, std::greater<int>> grouped;
    for (const auto& [word, count] : freq) {
        grouped[count].push_back(word);
    }
    std::vector<freq_vector> result;
    result.reserve(std::min(std::size_t(n), grouped.size()));
    for (const auto& [count, words_group] : grouped) {
        if (result.size() >= std::size_t(n)) { break; }   
        auto sorted_words = words_group;
        std::sort(sorted_words.begin(), sorted_words.end());
        result.push_back({count, std::move(sorted_words)});
    }
    return result;
}

export int count_unique(const std::vector<std::string>& words, const std::unordered_set<std::string>& stop_set){
    std::unordered_set<std::string> set;
    for(const auto& word: words){
        if(stop_set.find(word) == stop_set.end()){
            set.insert(word);
        }
    }
    return set.size();
}

export std::string normalyse(std::string& word){
    std::string result;
    for(auto& ch : word){
        if(std::isalpha(ch)){
            result.push_back(std::tolower(ch));
        }
        if(ch == '-'){
            result.push_back(ch);
        }
    }
    return result;
}

export std::vector<std::string> load_words( const std::string& path){
    std::ifstream file(path);
    if (!file.is_open()){
        return {};
    }
    std::vector<std::string> result;
    std::string word;
    while(file >> word){
        std::string norm = normalyse(word);
        if(!norm.empty()){
            result.push_back(norm);
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