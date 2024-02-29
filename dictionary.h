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
   
};

#endif // DICTIONARY_H
