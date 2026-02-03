#include <iostream>
#include "indexer.h"
#include "query.h"

int main() {
    Indexer indexer;
    indexer.buildIndex();

    std::cout << "Total documents indexed: "
              << indexer.getTotalDocs() << std::endl;

    QueryEngine engine;
    std::string query;

    std::cout << "Enter search word: ";
    std::cin >> query;

    engine.search(query, indexer.getIndex(), indexer.getTotalDocs());
    return 0;
}
