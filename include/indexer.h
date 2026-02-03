#ifndef INDEXER_H
#define INDEXER_H

#include <unordered_map>
#include <vector>
#include <string>

class Indexer {
public:
    void buildIndex();

    const std::unordered_map<std::string,
        std::vector<std::pair<int,int>>>& getIndex() const;

    int getTotalDocs() const;

private:
    std::unordered_map<std::string,
        std::vector<std::pair<int,int>>> invertedIndex;

    int totalDocs = 0;
};

#endif
