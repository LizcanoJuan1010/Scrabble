#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <functional>
#include <vector>
#include "Dictionary.h" // Si el archivo real se llama así
#include "Trie.h"
#include <unordered_map>

class Scrabble {
private:

Trie trie;
Trie trie_inverse;

public:

    Scrabble();
     std::unordered_map<char, int> letterValues;
    int getLetterValue(char letter);
    void initializeFunction(const std::string& filepath, Dictionary& dictionary);
    void startInverseFunction(const std::string& filePath, Dictionary& dictionary);
    void result(const std::string& palabra, const Dictionary& dictionary) const ;
    void help(const std::string& argument) const;
    void ShowHelp() const;
    void InitizalizeTrie(const std::string& filePath);
    void InitizalizeTrieInverse(const std::string& filePath);
    bool WordValid(const std::string& palabra) const;
    void palabras_por_prefijo(const std::string& prefijo, const Dictionary& dictionary);
    void palabras_por_sufijo(const std::string& sufijo, const Dictionary& dictionary);
    void mostrarPalabrasNodo(TrieNode* node, const std::string& currentWord, const Dictionary& dictionary);
    void mostrarPalabrasInv(TrieNode* node, const std::string& currentWord, const Dictionary& dictionary); 

};






#endif 
