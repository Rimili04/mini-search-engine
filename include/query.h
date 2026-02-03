#ifndef QUERY_H
#define QUERY_H

#include <unordered_map>
#include <vector>
#include <string>

class QueryEngine {
public:
    void search(
        const std::string& query,
        const std::unordered_map<std::string,
            std::vector<std::pair<int,int>>>& index,
        int totalDocs
    );
};

#endif
