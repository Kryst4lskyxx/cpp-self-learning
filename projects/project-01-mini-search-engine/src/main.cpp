#include "index.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace {

bool load_corpus(const std::string& path, SearchIndex& index) {
    std::ifstream input(path);
    if (!input) {
        std::cerr << "Failed to open corpus: " << path << '\n';
        return false;
    }

    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }

        const auto separator = line.find('\t');
        if (separator == std::string::npos) {
            std::cerr << "Skipping malformed corpus line: " << line << '\n';
            continue;
        }

        index.add_document(line.substr(0, separator), line.substr(separator + 1));
    }

    return true;
}

std::string join_query(int argc, char* argv[]) {
    std::ostringstream output;
    for (int i = 2; i < argc; ++i) {
        if (i > 2) {
            output << ' ';
        }
        output << argv[i];
    }
    return output.str();
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <corpus-file> <query...>\n";
        return 1;
    }

    SearchIndex index;
    if (!load_corpus(argv[1], index)) {
        return 1;
    }

    const auto results = index.search(join_query(argc, argv));
    for (const auto& result : results) {
        std::cout << result.document_id << " score=" << result.score << '\n';
    }

    return 0;
}
