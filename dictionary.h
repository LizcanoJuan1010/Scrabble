#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include "Word.h"

class Dictionary {
private:
    std::list<Word> words;

public:
    Dictionary();
    void addWord(const Word& word);
    // Métodos adicionales según sea necesario, como buscar palabras, imprimir el diccionario, etc.
};

#endif // DICTIONARY_H
