#ifndef GRAPH_H
#define GRAPH_H
#include "word.h"
#include <string>
#include <list>
#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m" 
  class Graph {
private:
    std::list<Word> words;
    int matrix[500][500];

public:
    Graph();
    void addWord(Word word);
    int getLetterValue(char let);
    void addListWord(const std::string& filePath);
    bool calculateDistance(const Word& word1, const Word& word2);
    void addMatrixDistance();
    void printMatrix();
    std::list<Word> getWords();
};

#endif

