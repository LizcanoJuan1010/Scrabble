#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include "Word.h"

class Dictionary {
private:
    std::list<Word> words;
    std::list<Word> inverseWords;

public:
    Dictionary();
    void addWord(const Word& word);
    void addinverseWords(const Word& word);
    bool IsinverseInitialized() const;
    void printWords() const; // Nuevo método para imprimir las palabras normales
    void printInverseWords() const;
    bool wordExists(const std::string& word) const;
    int getWordScore(const std::string& word) const;
};

#endif // DICTIONARY_H
