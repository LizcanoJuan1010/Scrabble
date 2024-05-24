#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <vector>
#include "Dictionary.h"

class Trie {
private:

TrieNode root;

public:

    void insert(std::string word);

    TrieNode *search(std::string word);
    void PrintLexical(TrieNode *current, std::string prefix, std::string suffix);
void recolectarPalabras(TrieNode* start, const std::string& prefix, std::vector<std::string>& palabras, const Dictionary& dictionary) const;
 void recolectarPalabrasInversas(TrieNode* node, const std::string& acumulado, std::vector<std::string>& palabras) const;
};





#endif // TRIE_H


