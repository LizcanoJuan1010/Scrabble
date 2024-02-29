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
    void inicializarFuncion(const std::string& filepath, Dictionary& dictionary);
    void iniciarInversoFuncion(const std::string& filePath, Dictionary& dictionary);
};






#endif 