#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {

struct TextStats {
    std::size_t lines{};
    std::size_t words{};
    std::size_t bytes{};
};

TextStats analyze_text(const std::string& text) {
    TextStats stats;
    stats.bytes = text.size();

    std::istringstream input(text);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    stats.lines = lines.size();

    for (const auto& current_line : lines) {
        std::istringstream words(current_line);
        std::string word;

        while (words >> word) {
            ++stats.words;
        }
    }

    return stats;
}

} // namespace

int main() {
    const auto stats = analyze_text("one two\nthree four\n");

    std::cout << "lines: " << stats.lines << '\n';
    std::cout << "words: " << stats.words << '\n';
    std::cout << "bytes: " << stats.bytes << '\n';
}
