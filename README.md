# Production-Grade Mini Search Engine (C++)

This project implements a production-grade **mini search engine** in **C++** that indexes a collection of text documents and retrieves relevant results for user queries using efficient data structures and ranking techniques.
The project focuses on core search engine fundamentals such as inverted indexing, query processing, and relevance-based ranking, similar to how real-world search systems operate at a foundational level.

---
## Project Objective

The objective of this project is to understand and implement the internal working of a search engine by building a complete end-to-end system that:

- Processes raw text documents
- Builds an efficient index for fast searching
- Ranks documents based on relevance
- Provides meaningful search results to users

---
## Key Features

- Indexes multiple text documents
- Uses an **Inverted Index** for fast keyword lookup
- Accepts search queries from the command line
- Ranks documents using **TF-IDF**
- Modular C++ design with clear separation of responsibilities
- Version controlled using Git and GitHub

---
## How the System Works

1. **Document Loading**  
   Text files are read from the `data/` directory.

2. **Tokenization**  
   Each document is split into individual words.

3. **Inverted Index Construction**  
   An inverted index maps each word to the documents in which it appears, along with frequency counts.

4. **Query Processing**  
   The user provides a search term via the command line.

5. **TF-IDF Scoring**  
   Each document containing the query term is scored using TF-IDF.

6. **Ranking and Output**  
   Documents are sorted by relevance and displayed in descending order of score.

---

## Build and Run Instructions

### Prerequisites
- C++17 compatible compiler (g++)
- Git
- Standard C++ STL
- Windows/Linux terminal environment

### Compile
```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/search.exe
```
##Run
```bash
./build/search.exe
```
##Project Structure
```
mini-search-engine/
├── data/
│   ├── doc1.txt
│   ├── doc2.txt
│   └── doc3.txt
├── include/
│   ├── indexer.h
│   ├── query.h
│   └── ranker.h
├── src/
│   ├── indexer.cpp
│   ├── query.cpp
│   ├── ranker.cpp
│   └── main.cpp
├── build/
│   └── search.exe
├── .gitignore
└── README.md
```

**SAMPLE OUTPUT**
```
Total documents indexed: 3
Enter search word: search

Document 2 (score: 0.92)
Document 1 (score: 0.45)
```

##**Technical Concepts Used**

- C++ (STL, object-oriented programming, file handling)
- Data Structures: unordered_map, vector, pair
- Algorithms: Inverted Index, TF-IDF
- Search engine fundamentals
- Command-line application development

##**Design Decisions**

- Inverted index enables fast keyword lookup without scanning all documents
- TF-IDF improves relevance-based ranking
- Modular design improves readability and maintainability
- Text-based interface keeps focus on backend logic
- Clear separation of indexing, ranking, and query handling

##**Limitations**
- Supports single-word queries only
- No stop-word removal or stemming
- No phrase or boolean queries
- Command-line interface only

##**Future Improvements**

- Multi-word and phrase search
- Stop-word filtering and stemming
- Boolean queries (AND, OR, NOT)
- File-based persistence of index
- Web or GUI-based interface

----

## Author
**Rimili Dutta**  
B.Tech (CSE) Student  
GitHub: https://github.com/Rimili04

