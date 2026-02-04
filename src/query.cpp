#include "query.h"
#include <iostream>

void QueryEngine::search(const std::string& query,
    const std::unordered_map<std::string,
    std::vector<std::pair<int,int>>>& index,
    int) {

    auto it = index.find(query);
    if (it == index.end()) {
        std::cout << "No results found\n";
        return;
    }

    std::cout << "Found in documents:\n";
    for (auto &p : it->second) {
        std::cout << "DocID: " << p.first
                  << " Count: " << p.second << "\n";
    }
}
