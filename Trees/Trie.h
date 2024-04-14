#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"

class Trie {
private:

TrieNode *root;

   

public:

    Trie();

    void insert(std::string word);

    TrieNode *search(std::string word);
    void PrintLexical(TrieNode *current, std::String prefix, std::string suffix);
}





#endif // TRIE_H