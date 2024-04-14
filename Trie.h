#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>

class Trie {
private:

TrieNode *root;

public:

    Trie(); 
    ~Trie();

    void insert(std::string word);

    TrieNode *search(std::string word);
    void PrintLexical(TrieNode *current, std::string prefix, std::string suffix);
};





#endif // TRIE_H