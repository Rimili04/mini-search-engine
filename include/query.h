#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class QueryEngine {
public:
    void search(const std::string& query,
                const std::unordered_map<std::string,
                std::vector<std::pair<int,int>>>& index,
                int totalDocs);
};
