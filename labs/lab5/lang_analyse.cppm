export module lang_analyse;
import std;

export struct freq_vector {
    int freq;
    std::vector<std::string> words;
};

export std::unordered_map<std::string, int> get_freq(
    const std::vector<std::string>& words,
    const std::unordered_set<std::string>& stop_words
) {
    std::unordered_map<std::string, int> freq;
    for (const auto& w : words) {
        if (!stop_words.count(w)) {
            freq[w]++;
        }
    }
    return freq;
}

std::string normalyse(const std::string& string) {
    std::string result;
    for (char c : string) {
        result += std::tolower(unsigned char(c));
    }
    while (!result.empty() && !std::isalpha(unsigned char(result.front()))) {
        result.erase(result.begin());
    }
    while (!result.empty() && !std::isalpha(unsigned char(result.back()))) {
        result.pop_back();
    }
    return result;
}

export std::vector<std::string> load_words(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::println("failed to open file: {}", path);
        return {};
    }
    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        std::string norm = normalyse(word);
        if (!norm.empty()) {
            words.push_back(norm);
        }
    }
    return words;
}

export size_t count_unique(
    const std::vector<std::string>& words,
    const std::unordered_set<std::string>& stop_words
) {
    std::unordered_set<std::string> unique;
    for (const std::string& w : words) {
        if (!stop_words.contains(w)) {
            unique.insert(w);
        }
    }
    return unique.size();
}

export freq_vector most_common(
    const std::vector<std::string>& words,
    const std::unordered_set<std::string>& stop_words
) {
    auto freq = get_freq(words, stop_words);
    int max = 0;
    for (const auto& [word, count] : freq) {
        if (count > max) max = count;
    }
    std::vector<std::string> result;
    for (const auto& [word, count] : freq) {
        if (count == max) result.push_back(word);
    }
    std::sort(result.begin(), result.end());
    return {max, result};
}

export std::vector<freq_vector> top_n_words(
    const std::vector<std::string>& words,
    const std::unordered_set<std::string>& stop_words,
    int n
) {
    if (n <= 0) return {};
    
    auto freq = get_freq(words, stop_words);
    
    std::unordered_map<int, std::vector<std::string>> grouped;
    for (const auto& [word, count] : freq) {
        grouped[count].push_back(word);
    }
    
    std::vector<int> counts;
    for (const auto& [count, _] : grouped) {
        counts.push_back(count);
    }
    std::sort(counts.begin(), counts.end(), std::greater<>());
    
    int limit = std::min(n, (int)counts.size());
    std::vector<freq_vector> result;
    result.reserve(limit);
    for (int i = 0; i < limit; ++i) {
        int count = counts[i];
        auto words_group = grouped[count];
        std::sort(words_group.begin(), words_group.end());
        result.push_back({count, std::move(words_group)});
    }
    return result;
}