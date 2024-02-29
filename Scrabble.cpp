#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include <cctype> 
#include <algorithm>
#include "ScrabbleFirmas.h"
using namespace std;

std::unordered_map<char, int> letterValues = {
    {'E', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'N', 1}, {'R', 1}, {'T', 1}, {'L', 1}, {'S', 1}, {'U', 1},
    {'D', 2}, {'G', 2},
    {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
    {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
    {'K', 5},
    {'J', 8}, {'X', 8},
    {'Q', 10}, {'Z', 10}
};

int getLetterValue(char letter) {
   // Convertir a mayúscula para manejar uniformemente minúsculas y mayúsculas
    letter = std::toupper(letter);

    // Buscar la letra en el mapa y devolver su valor.
    auto it = letterValues.find(letter);
    if (it != letterValues.end()) {
        return it->second;
    }

    // Si la letra no está en el mapa, podrías devolver 0 o manejar el error como prefieras.
    return 0;
}

void inicializarFuncion(const string& filepath,Dictionary& dictionary) {

    ifstream file(filepath);
    if (!file) {
        //toca mostrar en pantalla que no funciona pero sin cout, con loggers eso dijo el profe
        return;
    }

    std::string line;
    bool anywordadded = false; // Flag to indicate if any word was added to the dictionary

    while (std::getline(file, line)) {
        std::stringstream lineStream(line); // Create a stringstream from the line
        std:: string wordtext;

        while (std::getline(lineStream, wordtext, ',')) {
            wordtext.erase(0, wordtext.find_first_not_of(" \t\n\r\f\v"));
            wordtext.erase(wordtext.find_last_not_of(" \t\n\r\f\v") + 1);

            if (!wordtext.empty()) {
                Word word;
                for (char c : wordtext) {
                    if (c != '-') {
                        int value = getLetterValue(c); // Usa la función para obtener el valor de la letra.
                        Letter letter(c, value);
                         word.addLetter(letter);
                    }
                    
                }
                dictionary.addWord(word);
                anywordadded = true;
            }
        }
    }
        
    }


void iniciarInversoFuncion(const std::string& filePath, Dictionary& dictionary) {
    std::ifstream file(filePath);
    std::string line;
    bool anywordadded = false;
    if (dictionary.IsinverseInitialized())
     {
    //sigue que ya esta inicializado
     return;
    }

    if (!file) {
    //toca mostrar en pantalla que no existe el archivo pero sin cout, con loggers eso dijo el profe
    return;
    }  

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string wordText;
        while (getline(ss, wordText, ',')){
            wordText.erase(0, wordText.find_first_not_of(" \t\n\r\f\v"));
            wordText.erase(wordText.find_last_not_of(" \t\n\r\f\v") + 1);
            if (!wordText.empty() )
            {
                std::reverse(wordText.begin(), wordText.end());
                Word word;
                for (char c : wordText) {
                    int value = getLetterValue(c); // Asume que esta función retorna el valor correcto de cada letra
                    word.addLetter(Letter(c, value));
                }
                dictionary.addinverseWords(word);
                anywordadded = true;

            }
            
        }
        
    }
 
 
  
}

void puntajeFuncion(const string& argumento, vector<string>& diccionario) {
    bool palabraEnDiccionario = false;
    for (const auto& palabraDic : diccionario) {
        if (palabraDic == argumento) {
            palabraEnDiccionario = true;
            break;  // No es necesario continuar verificando el diccionario si ya encontramos la palabra
        }
    }

    if (!palabraEnDiccionario) {
        cout << "La palabra no existe en el diccionario" << endl;
    } else {
        for (char c : argumento) {
            // Verifica si el carácter no es una letra o un espacio en blanco
            if (!isalpha(c) && !isspace(c)) {
                cout << "La palabra contiene símbolos inválidos" << endl;
                return;  // Sale de la función si se encuentra un carácter inválido
            }
        }

        // Si no se encontraron caracteres inválidos, imprime el mensaje de puntaje
       cout << "La palabra tiene un puntaje de puntaje" <<endl;
    }
}


void exitfuncion(const string& argumento) {

    exit(0);
}

void iniciararbolFuncion(const string& argumento) {
    ifstream archivoEntrada(argumento);

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
       
        string palabra;

        while (getline(archivoEntrada, palabra))
        {
           
        }
        
        
        archivoEntrada.close();
         cout << " El árbol del diccionario ya ha sido inicializado.\n" << endl;
    } else {
        cout << " El archivo diccionario.txt no existe o no puede ser leído.\n" << endl;
    }
  
}

void iniciararbolinversoFuncion(const string& argumento) {
      ifstream archivoEntrada(argumento);
     vector<string> palabras;
    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
       string palabra;
        while (getline(archivoEntrada, palabra)) {
            palabras.push_back(palabra);
        }
        archivoEntrada.close();
    
         cout << " El árbol del diccionario inverso se ha inicializado correctamente.\n" << endl;
    } else {
        cerr << " El archivo diccionario.txt no existe o no puede ser leído.\n" << endl;
    }
}

void palabrasporprefijoFuncion(const string& argumento, vector<string>& diccionario) {
 
    bool existepref;
    int contador=0;
    // Utiliza la función find para buscar la parte en la palabra
    for (const auto& palabraDic : diccionario) {
        existepref=false;
      existepref= palabraDic.find(argumento) == 0;
    if(existepref)
    contador++;
       }
       if(contador==0){
        cout<<"Prefijo prefijo no pudo encontrarse en el diccionario.\n";
       }else{
        cout<<"Las palabras que inician con este prefijo son:\n";
       }

}

void palabrasporsufijoFuncion(const string& argumento, vector<string>& diccionario) {
   bool existesuf;
    int contador=0;
    // Utiliza la función find para buscar la parte en la palabra
    for (const auto& palabraDic : diccionario) {
        existesuf=false;
        size_t posicion = palabraDic.rfind(argumento);
      existesuf= posicion != string::npos && posicion == palabraDic.length() - argumento.length();//string::npos para cosas no enconradas o invalidas
    if(existesuf)
    contador++;
       }
       if(contador==0){
        cout<<" Sufijo sufijo no pudo encontrarse en el diccionario.\n";
       }else{
        cout<<"Las palabras que terminan con este sufijo son:\n";
       }
}

void grafodepalabrasFuncion(const string& argumento) {
  cout<<"Grafo construído correctamente.\n";
}

void posiblespalabrasFuncion(const string& argumento) {
  for (char c : argumento) {
            // Verifica si el carácter no es una letra o un espacio en blanco
            if (!isalpha(c) && !isspace(c)) {
                cout << "La cadena letras contiene símbolos inválidos" << endl;
                return;  // Sale de la función si se encuentra un carácter inválido
            }
} cout<<"Las posibles palabras a construir con las letras letras son:\n";
}
