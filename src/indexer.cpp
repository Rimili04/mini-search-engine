#include "indexer.h"
#include <fstream>
#include <cctype>

void Indexer::buildIndex() {
    std::string files[] = {
        "data/doc1.txt",
        "data/doc2.txt",
        "data/doc3.txt"
    };

    int docID = 0;

    for (const std::string& fileName : files) {
        std::ifstream file(fileName);
        if (!file.is_open()) continue;

        std::unordered_map<std::string, int> wordCount;
        std::string word;

        while (file >> word) {
            for (char &c : word)
                c = std::tolower(c);
            wordCount[word]++;
        }

        for (const auto& p : wordCount) {
            invertedIndex[p.first].push_back({docID, p.second});
        }

        docID++;
        totalDocs++;
    }
}

const std::unordered_map<std::string,
    std::vector<std::pair<int,int>>>& Indexer::getIndex() const {
    return invertedIndex;
}

int Indexer::getTotalDocs() const {
    return totalDocs;
}
