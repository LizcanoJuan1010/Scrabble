#include "Dictionary.h"
#include <iostream>
#include <algorithm>
Dictionary::Dictionary() {}

void Dictionary::addWord(const Word& word) {
    words.push_back(word);
}


  void Dictionary::addinverseWords(const Word& word) {
    inverseWords.push_back(word); // Añade la palabra a la lista de palabras inversas
}

bool Dictionary::IsinverseInitialized() const {
    return !inverseWords.empty(); // Verifica si la lista de palabras inversas no está vacía
}

void Dictionary::printWords() const {
    for (const Word& word : words) {
        std::cout << word.toString() << std::endl; // Asume que Word tiene un método toString()
    }
}

void Dictionary::printInverseWords() const {
    for (const Word& word : inverseWords) {
        std::cout << word.toString() << std::endl; // Asume que Word tiene un método toString()
    }

}

bool Dictionary::wordExists(const std::string& word) const {
    auto wordFinder = [&word](const std::list<Word>& wordList) {
        return std::find_if(wordList.begin(), wordList.end(), 
                            [&word](const Word& w) { return w.toString() == word; }) != wordList.end();
    };

    return wordFinder(words) || wordFinder(inverseWords);
}

int Dictionary::getWordScore(const std::string& word) const {
    for (const auto& w : words) {
        if (w.toString() == word) 
        return w.calculateScore();
    }
    for (const auto& w : inverseWords) {
        if (w.toString() == word) 
        return w.calculateScore();
    }
    return 0; 
}