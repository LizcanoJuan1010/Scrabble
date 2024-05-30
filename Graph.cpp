#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

Graph::Graph() {
    // Inicializa la matriz con 8 para representar que no hay conexiones al inicio
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            matrix[i][j] = 8;
        }
    }
}

void Graph::addWord(Word word) {
    this->words.push_back(word);
}

int Graph::getLetterValue(char let) {
    let = toupper(let);
    std::ifstream flujo("LetterValues.txt", std::ios::in);
    if (flujo.fail()) {
        std::cerr << "Error al abrir el archivo\n";
        return -1;
    } else {
        char letter;
        int valor = 0;
        std::string linea;
        std::map<char, int> mapa;
        while (getline(flujo, linea)) {
            std::stringstream ss(linea);
            ss >> letter;
            ss.ignore();
            ss >> valor;

            if (ss.fail()) {
                std::cerr << "Formato de línea no válido: " << linea << std::endl;
            } else {
                mapa[letter] = valor;
            }
        }
        flujo.close();
        for (const auto& entry : mapa) {
            if (entry.first == let) {
                return entry.second;
            }
        }
    }
    return 0;
}

void Graph::addListWord(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo " << filePath << std::endl;
        return;
    }

    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        std::cerr << "El archivo está vacío." << std::endl;
        return;
    }
    file.seekg(0, std::ios::beg);

    std::string line;
    bool anywordadded = false;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string wordtext;

        while (std::getline(lineStream, wordtext, ',')) {
            wordtext.erase(0, wordtext.find_first_not_of(" \t\n\r\f\v"));
            wordtext.erase(wordtext.find_last_not_of(" \t\n\r\f\v") + 1);

            if (!wordtext.empty()) {
                Word word;
                std::vector<char> letters(wordtext.begin(), wordtext.end());
                for (char c : letters) {
                    if (c != '-') {
                        int value = getLetterValue(c);
                        Letter letter(c, value);
                        word.addLetter(letter);
                    }
                }
                addWord(word);
                anywordadded = true;
            }
        }
    }
    if (!anywordadded) {
        std::cerr << "No se encontraron palabras en el archivo." << std::endl;
    } else {
        std::cout << "Palabras añadidas correctamente.\n";
    }
}

bool Graph::calculateDistance(const Word& word1, const Word& word2) {
    std::string w1 = word1.toString();
    std::string w2 = word2.toString();
    if (w1.length() != w2.length()) {
        return false;
    }

    int difference = 0;
    for (size_t i = 0; i < w1.length(); ++i) {
        if (w1[i] != w2[i]) {
            ++difference;
        }
        if (difference > 1) {
            return false;
        }
    }
    return difference == 1;
}

void Graph::addMatrixDistance() {
    int index1 = 0, index2 = 0;
    for (const Word& w1 : words) {
        index2 = 0;
        for (const Word& w2 : words) {
            if (calculateDistance(w1, w2)) {
                this->matrix[index1][index2] = 1; // Conexión entre las palabras
            } else {
                this->matrix[index1][index2] = 0; // Sin conexión entre las palabras
            }
            index2++;
        }
        index1++;
    }
}

void Graph::printMatrix() {
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (this->matrix[i][j] == 1) {
                std::cout << GREEN << this->matrix[i][j] << " " << RESET;
            } else {
                std::cout << this->matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

std::list<Word> Graph::getWords() {
    return words;
}
