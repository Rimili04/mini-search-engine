#include "ranker.h"
#include <cmath>
#include <vector>

std::vector<std::pair<int,double>> Ranker::rank(
    const std::string& term,
    const std::unordered_map<std::string,
        std::vector<std::pair<int,int>>>& index,
    int totalDocs
) {
    std::vector<std::pair<int,double>> results;

    if (index.find(term) == index.end())
        return results;

    int docsWithTerm = index.at(term).size();
    double idf = log((double)totalDocs / docsWithTerm);

    for (auto& p : index.at(term)) {
        double tf = p.second;
        results.push_back(std::make_pair(p.first, tf * idf));
    }

    return results;
}
