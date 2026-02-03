#include "query.h"
#include "ranker.h"
#include <iostream>
#include <queue>

void QueryEngine::search(
    const std::string& query,
    const std::unordered_map<std::string,
        std::vector<std::pair<int,int>>>& index,
    int totalDocs
) {
    Ranker ranker;
    auto rankedDocs = ranker.rank(query, index, totalDocs);

    std::priority_queue<std::pair<double,int>> pq;
    for (auto r : rankedDocs) {
        pq.push(std::make_pair(r.second, r.first));
    }

    std::cout << "Search Results:\n";
    while (!pq.empty()) {
        std::cout << "DocID: " << pq.top().second
                  << " Score: " << pq.top().first << "\n";
        pq.pop();
    }
}
