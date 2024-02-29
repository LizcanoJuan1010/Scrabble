#include "Dictionary.h"

Dictionary::Dictionary() {}

void Dictionary::addWord(const Word& word) {
    words.push_back(word);
}
