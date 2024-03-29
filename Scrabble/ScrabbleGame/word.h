#ifndef WORD_H
#define WORD_H

#include <list>
#include "Letter.h"

class Word {
private:
    std::list<Letter> letters;

public:
    Word();
    void addLetter(Letter letter);
    int calculateScore() const;
    std::string toString() const; //get the word as a string
};

#endif // WORD_H
