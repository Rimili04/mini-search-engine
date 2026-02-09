// Final verification commit – BM25 + OCR stable
#include "indexer.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <unordered_map>

void Indexer::buildIndex() {
    std::ifstream listFile("data_clean/files.txt");
    if (!listFile.is_open()) {
        std::cerr << "Failed to open data_clean/files.txt\n";
        return;
    }

    std::string filename;
    int docID = 0;

    while (std::getline(listFile, filename)) {
        std::ifstream file("data_clean/" + filename);
        if (!file.is_open()) {
            std::cerr << "Could not open: " << filename << "\n";
            continue;
        }

        std::unordered_map<std::string, int> wordCount;
        std::string word;

        while (file >> word) {
            for (char &c : word)
                c = std::tolower(c);
            wordCount[word]++;
        }

        for (const auto &p : wordCount) {
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
