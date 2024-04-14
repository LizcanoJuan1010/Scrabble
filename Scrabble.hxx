#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include <cctype> 
#include <map>
#include <algorithm>
#include "Scrabble.h"
#include <cctype> 
using namespace std;


    Scrabble::Scrabble() {
    
    }

int Scrabble::getLetterValue(char let) {
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

bool Scrabble::WordValid(const string& Word) const {

    for (char c : Word) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {  
            return false;  
        }
    }
    return true; 
}

void Scrabble::InitizalizeTrie(const string& filePath) {
    

    ifstream file(filePath);
    if (!file.is_open()) {
        return;
    }

    file.seekg(0, ios::end); 
    if (file.tellg() == 0) {
       
        return;
    }
    file.seekg(0, ios::beg);

     std::string line;

     while (file >> line) {
         if (WordValid(line)) {
             trie.insert(line);
         }   
     }

     file.close();
}

void Scrabble::initializeFunction(const string& filepath,Dictionary& dictionary) {

    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Archivo no encontrado" << endl;
        return;
    }
    
    file.seekg(0, ios::end); 
    if (file.tellg() == 0) {
        cout << "El archivo está vacío." << endl;
        return;
    }
    file.seekg(0, ios::beg);

    std::string line;

    bool anywordadded = false; 
    while (std::getline(file, line)) {
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
                dictionary.addWord(word);
                anywordadded = true;
                
            }
        }
       
    } 
    if (!anywordadded )
    {
        cout << "No se encontraron palabras en el archivo." << endl;
    }
    

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
                    int value = getLetterValue(c);
                    word.addLetter(Letter(c, value));
                    
                }
                dictionary.addinverseWords(word);
                anywordadded = true;
                
            }
            
        }
       
    }
}

void Scrabble::result(const std::string& palabra, const Dictionary& dictionary) const {

    std::string palabraMayusculas;
    std::transform(palabra.begin(), palabra.end(), std::back_inserter(palabraMayusculas),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });

    if (!std::all_of(palabraMayusculas.begin(), palabraMayusculas.end(), [](char c){ return std::isalpha(c); })) {
        std::cout << "(Letras invalidas) La palabra contiene simbolos invalidos." << std::endl;
        return;
    }

    if (!dictionary.wordExists(palabraMayusculas)) {
        std::cout << "(Palabra no existe) La palabra no existe en el diccionario." << std::endl;
        return;
    }


    int puntaje = dictionary.getWordScore(palabraMayusculas); 
    std::cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << std::endl;
}


void Scrabble::help(const std::string& argument)const{

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


    void Scrabble::ShowHelp() const {
    cout << "Comandos disponibles:\n";
    cout << "  inicializar [archivo] - Carga un diccionario desde un archivo.\n";
    cout << "  iniciar_inverso [archivo] - Función para iniciar algo en modo inverso.\n";
    cout << "  puntaje [palabra] - Muestra el puntaje de una palabra.\n";
    cout << "  salir - Sale del programa.\n";
    cout << "  iniciar_arbol [archivo] - Inicia un árbol con datos del archivo.\n";
    cout << "  iniciar_arbol_inverso [archivo] - Inicia un árbol en modo inverso.\n";
    cout << "  palabras_por_prefijo [prefijo] - Muestra palabras con un prefijo dado.\n";
    cout << "  palabras_por_sufijo [sufijo] - Muestra palabras con un sufijo dado.\n";
    cout << "  grafo_de_palabras [archivo] - Inicia un grafo de palabras.\n";
    cout << "  posibles_palabras [letras] - Muestra posibles palabras con las letras dadas.\n";
    cout << "  ayuda - Muestra este menu de ayuda.\n";
}