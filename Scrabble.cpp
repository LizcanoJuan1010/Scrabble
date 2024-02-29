#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include <cctype> 
#include <algorithm>
#include "Scrabble.h"
using namespace std;


    Scrabble::Scrabble() {
    
    }

    std::unordered_map<char, int> letterValues = {
    {'E', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'N', 1}, {'R', 1}, {'T', 1}, {'L', 1}, {'S', 1}, {'U', 1},
    {'D', 2}, {'G', 2},
    {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
    {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
    {'K', 5},
    {'J', 8}, {'X', 8},
    {'Q', 10}, {'Z', 10}
};
int Scrabble::getLetterValue(char letter) {
   // Convertir a mayúscula para manejar uniformemente minúsculas y mayúsculas
    letter = std::toupper(letter);

    // Buscar la letra en el mapa y devolver su valor.
    auto it = letterValues.find(letter);
    if (it != letterValues.end()) {
        cout << "Value: " << it->second << endl;
        return it->second;
    }

    // Si la letra no está en el mapa, podrías devolver 0 o manejar el error como prefieras.
    return 0;
}

void Scrabble::initializeFunction(const string& filepath,Dictionary& dictionary) {

    ifstream file(filepath);
    if (!file.is_open()) {
        //cout << "File not found." << endl;
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
                std::vector<char> letters(wordtext.begin(), wordtext.end());
                for (char c : letters) {
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
        
       dictionary.printWords(); 
    }


void Scrabble::startInverseFunction(const std::string& filePath, Dictionary& dictionary) {
    std::ifstream file(filePath);
    std::string line;
    bool anywordadded = false;
    if (dictionary.IsinverseInitialized())
     {
      cout << "Inverse words already initialized." << endl;
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

void Scrabble::result(const std::string& palabra, const Dictionary& dictionary) const {


    if (!std::all_of(palabra.begin(), palabra.end(), [](char c){ return std::isalpha(c); })) {
        std::cout << "(Letras inválidas) La palabra contiene símbolos inválidos." << std::endl;
        return;
    }

    if (!dictionary.wordExists(palabra)) {
        std::cout << "(Palabra no existe) La palabra no existe en el diccionario." << std::endl;
        return;
    }

    // Asumiendo que necesitas encontrar la palabra en el diccionario para obtener su puntaje:
    int puntaje = dictionary.getWordScore(palabra); // Este es un método hipotético que necesitarías implementar.
    std::cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << std::endl;
}


void help(std::string& argument){

    if(argument == "inicializar" ){
        cout<<'\t' <<"- $inicializar (Fomato: $inicializar [nombre_archivo]) Descripcion: Inicializa el sistema a partir del archivo, que contiene un diccionario de palabras aceptadas en el idioma ingles." <<endl;

    }else if(argument == "inicializar_inverso"){
        cout<<'\t' <<"- $inicializar_inverso (Fomato: $iniciar_inverso [nombre_archivo]) Descripcion: Inicializa el sistema a partir del archivo que contiene un diccionario de palabras aceptadas en el idioma ingles. A diferencia del comando inicializar, este almacena las palabras en sentido inverso (leídas de derecha a izquierda "<<endl;
    
    }else if(argument == "puntaje"){
        cout<<'\t' <<"- $puntaje (Fomato: $puntaje [palabra]) Descripcion: El comando permite conocer la puntuacion que puede obtenerse con una palabra dada, de acuerdo a la tabla de puntuación de cada letra presentada anteriormente"<<endl;
    
    }else if(argument == "iniciar_arbol"){
        cout<<'\t' <<"- $iniciar_arbol (Fomato: $iniciar_arbol [archivo]) Descripcion: Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma inglés (idioma original del juego)"<<endl;
    
    }else if(argument == "iniciar_arbol_inverso "){
        cout<<'\t' <<"- $iniciar_arbol_inverso (Formato: $iniciar_arbol_inverso [archivo]) Descripcion: Inicializa el sistema a partir del archivo diccionario.txt, que contiene un diccionario de palabras aceptadas en el idioma inglés (idioma original del juego). A diferencia de los comandosiniciar_inverso e iniciar_arbol, este comando almacena las palabras en uno o más árboles de letras,pero en sentido inverso (leídas de derecha a izquierda)"<<endl;
   
   }else if(argument == "palabras_por_prefijo"){
        cout<<'\t' <<"- $palabras_por_prefijo  (Fomato: palabras_por_prefijo [prefijo]) Descripcion: Dado un prefijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el comando iniciar_arbol) para ubicar todas las palabras posibles a construir a partir de ese prefijo "<<endl;
   
   }else if(argument == "palabras_por_sufijo"){
        cout<<'\t' <<"- $palabras_por_sufijo  (Fomato: $palabras_por_sufijo [sufijo]) Descripcion: Dado un sufijo de pocas letras, el comando recorre el(los) árbol(es) de letras (construído(s) con el comando iniciar_arbol_inverso) para ubicar todas las palabras posibles a construir que terminan con ese sufijo"<<endl;
   
}else if(argument == "grafo_de_palabras"){
        cout<<'\t' <<"- $grafo_de_palabras  (Fomato: $grafo_de_palabras) Descripcion: Con las palabras ya almacenadas en el diccionario (luego de ejecutar el comando inicializar), el comando construye un grafo de palabras, en donde cada palabra se conecta a las demás si y sólo sí difieren en un única letra (con las demás letras iguales y en las mismas posiciones)."<<endl;
   
   }else if(argument == " posibles_palabras"){
        cout<<'\t' <<"- $posibles_palabras  (Fomato: $posibles_palabras [letras]) Descripcion: Dadas ciertas letras en una cadena de caracteres (sin importar su orden), el comando debe presentar en pantalla todas las posibles palabras válidas a construir, indicando la longitud de cada una y la puntuación que se puede obtener con cada una"<<endl;   

    }else if(argument == "salir"){
        cout<<'\t' <<"- $salir (Fomato: $salir) Descripcion: Termina la ejecución de la aplicación."<<endl;

    }else if(argument == "ayuda"){
        cout<<'\t' << "- $ayuda (Fomato: $ayuda nombre_comando)"<<endl;
        
    }else{
        cout<<'\t' << " Comando " << argument << " no conocido :(" << endl;
    }
    
    }