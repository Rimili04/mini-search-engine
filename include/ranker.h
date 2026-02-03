#ifndef RANKER_H
#define RANKER_H

#include <unordered_map>
#include <vector>
#include <string>

class Ranker {
public:
    std::vector<std::pair<int,double>> rank(
        const std::string& term,
        const std::unordered_map<std::string,
            std::vector<std::pair<int,int>>>& index,
        int totalDocs
    );
};

#endif

