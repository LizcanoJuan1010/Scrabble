#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Word.h"
#include "letter.h"
#include "Graph.h"
#include <list>
#include <math.h>
#include <map>
#include <unordered_map>
#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m" 
using namespace std;
Graph::Graph(): words() {
   
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            matrix[i][j] = -1;
        }
    }
}

void Graph::addWord(Word word){
  this->words.push_back(word);
}

int Graph::getLetterValue(char let) {
    let=toupper(let);

  ifstream flujo("LetterValues.txt", ios::in);

    if (flujo.fail()) {
        cerr << "Error al abrir el archivo\n";
        return -1;
    } else {
        char letter;
        int valor=0;
        string linea;
        map<char, int> mapa;
        while (getline(flujo, linea)) {
            stringstream ss(linea);
            ss >> letter;  
            ss.ignore(); 
            ss >> valor; 

            if (ss.fail()) {
                cerr << "Formato de línea no válido: " << linea << endl;
            } else {
                mapa[letter] = valor;
            }
        }
        flujo.close(); 
        for (const auto& entry : mapa) {
            if(entry.first== let){
                return entry.second;
            }
        }
    }

  
    return 0;
}

void Graph::addListWord(std::string file){
  
  std::ifstream f(file);

  if (!f.is_open()) {
    std::cerr << "Error al abrir el archivo " << file << std::endl;
  } else {

    f.seekg(0, ios::end); 
    if (f.tellg() == 0) {
        std::cout << "El archivo está vacío." << endl;
        return;
    }
    f.seekg(0, ios::beg);

    std::string line;

    bool anywordadded = false; 
    while (std::getline(f, line)) {
        std::stringstream lineStream(line); 
        std:: string wordtext;

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
    if (!anywordadded )
    {
        cout << "No se encontraron palabras en el archivo." << endl;
    }
  }
}
 bool Graph::calculateDistance(Word word1, Word word2)
 {
    std::string w1=word1.toString();
    std::string w2=word2.toString();
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

    
    return difference== 1;
}   
 
 void Graph::addMatrixDistance(){
    int index1=0,index2=0;;
    for(Word w1:words){
        index2=0;
        for(Word w2:words){
            if(calculateDistance(w1,w2))
            this->matrix[index1][index2]=1;

            index2++;
        }
        index1++;
        
    }
 }
 void Graph::printMatrix(){
  for(int i=0;i<200;i++){
    for(int j=0;j<200;j++){
        if(this->matrix[i][j]==1){
      std::cout<< GREEN <<this->matrix[i][j]<<" "<< RESET ;}
      else{
        cout<<this->matrix[i][j]<<" ";
      }
  }
    std::cout<<std::endl;
  }
}