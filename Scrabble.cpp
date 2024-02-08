#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include <cctype> 
using namespace std;



void inicializarFuncion(const string& argumento,vector<string>& diccionario) {


    ifstream archivoEntrada(argumento);

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
       
        string palabra;

        while (getline(archivoEntrada, palabra))
        {
            diccionario.push_back (palabra);
        }
        
        
        archivoEntrada.close();
         cout << " El diccionario se ha inicializado correctamente" << endl;
    } else {
        cout << " El archivo diccionario.txt no existe o no puede ser leído." << endl;
    }

}

void iniciarInversoFuncion(const string& argumento) {
     ifstream archivoEntrada(argumento);
     vector<string> palabras;
    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
       string palabra;
        while (getline(archivoEntrada, palabra)) {
            palabras.push_back(palabra);
        }
        archivoEntrada.close();
    
         cout << " El diccionario se ha inicializado correctamente" << endl;
    } else {
        cerr << " El archivo diccionario.txt no existe o no puede ser leído." << endl;
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
