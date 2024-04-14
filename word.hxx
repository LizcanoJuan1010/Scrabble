#include "Word.h"
#include <algorithm>
#include <sstream>

Word::Word() {}

void Word::addLetter(Letter letter) {
    letters.push_back(letter);
}

int Word::calculateScore() const {
    int score = 0;
    for (const auto& letter : letters) {
        score += letter.getValue();
    }
    return score;
}

std::string Word::toString() const {
    std::stringstream word;
    for (const auto& letter : letters) {
        word << letter.getCharacter();
    }
    return word.str();
}
