#include <iostream>
#include <set>
//
//bool compareLength(const std::string& lhs, const std::string& rhs) {
//    return std::size(rhs) < std::size(lhs);
//}
//
//int main() {
//    int N;
//    std::set<std::string, decltype(compareLength)*> words(compareLength);
//    std::cin >> N;
//    for(auto i = 0; i < N; i++) {
//        std::string tmp;
//        std::cin >> tmp;
//        words.insert(tmp);
//    }
//    for(const auto& element: words) {
//        std::cout << element << std::endl;
//    }
//}

#include <unordered_set>
#include <map>

int main() {
    int N;
    std::cin >> N;
    std::map<size_t, std::unordered_set<std::string>, std::greater<>> lengths_to_words;
    for(auto i = 0; i < N; i++) {
        std::string tmp;
        std::cin >> tmp;
        lengths_to_words[tmp.size()].insert(tmp);
    }
    for(const auto& [length, words]: lengths_to_words) {
        for(const auto& element: words) {
            std::cout << element << std::endl;
        }
    }
}
