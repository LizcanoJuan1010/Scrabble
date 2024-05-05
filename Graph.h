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

public:
  int matrix[200][200];

  Graph();
  void addWord(Word word);
  int getLetterValue(char let);
  void addListWord(std::string dicctionary);
  bool calculateDistance(Word word1, Word word2);
  void addMatrixDistance();
  void printMatrix();
};

#endif
