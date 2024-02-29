#include "Dictionary.h"

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
