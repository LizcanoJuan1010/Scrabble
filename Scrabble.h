#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <unordered_map>
#include "Dictionary.h"
#include "Trie.h"
#include "Graph.h"
#include <unordered_set>

class Scrabble {
private:
    Trie trie;
    Trie trie_inverse;
    Graph graph;

        void generarCombinaciones(const std::string& letras, std::string palabraActual, size_t pos, std::unordered_set<std::string>& posiblesPalabras, const Dictionary& dictionary);

public:
    Scrabble();
    std::unordered_map<char, int> letterValues;
    int getLetterValue(char letter);
    void initializeFunction(const std::string& filepath, Dictionary& dictionary);
    void startInverseFunction(const std::string& filePath, Dictionary& dictionary);
    void result(const std::string& palabra, const Dictionary& dictionary) const;
    void help(const std::string& argument) const;
    void ShowHelp() const;
    void InitizalizeTrie(const std::string& filePath);
    void InitizalizeTrieInverse(const std::string& filePath);
    bool WordValid(const std::string& palabra) const;
    void palabras_por_prefijo(const std::string& prefijo, const Dictionary& dictionary);
    void palabras_por_sufijo(const std::string& sufijo, const Dictionary& dictionary);
    void CreateGraph(const std::string& filePath);
    void posibles_palabras(const std::string& letras, const Dictionary& dictionary);
};

#endif // SCRABBLE_H
