#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <functional>
#include <vector>
#include "Dictionary.h" // Si el archivo real se llama así

class Scrabble {
private:
 

public:

    Scrabble();
     std::unordered_map<char, int> letterValues;

    int getLetterValue(char letter);
    void initializeFunction(const std::string& filepath, Dictionary& dictionary);
    void startInverseFunction(const std::string& filePath, Dictionary& dictionary);
    void result(const std::string& palabra, const Dictionary& dictionary) const ;
    void help(const std::string& argument) const;

    void mostrarMenuAyuda() const;

   

};






#endif 