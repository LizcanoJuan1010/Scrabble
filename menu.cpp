#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
using namespace std;



void inicializarFuncion(const string& argumento) {


    ifstream archivoEntrada(argumento);

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
       
        string palabra;

        while (getline(archivoEntrada, palabra))
        {
            cout << palabra << endl;
        }
        
        
        archivoEntrada.close();
         cout << " El diccionario se ha inicializado correctamente" << endl;
    } else {
        cout << " El archivo diccionario.txt no existe o no puede ser leído." << endl;
    }

}

void iniciarInversoFuncion(const string& argumento) {
     ifstream archivoEntrada(argumento);

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
       
        string palabra;

        while (getline(archivoEntrada, palabra))
        {
            cout << palabra << endl;
        }
        
        
        archivoEntrada.close();
         cout << " El diccionario se ha inicializado correctamente" << endl;
    } else {
        cout << " El archivo diccionario.txt no existe o no puede ser leído." << endl;
    }
}

void puntajeFuncion(const string& argumento) {
   
}

void exitfuncion(const string& argumento) {

    exit(0);
}

void iniciararbolFuncion(const string& argumento) {
  
}

void iniciararbolinversoFuncion(const string& argumento) {
  
}

void palabrasporprefijoFuncion(const string& argumento) {
  
}

void palabrasporsufijoFuncion(const string& argumento) {
  
}

void grafodepalabrasFuncion(const string& argumento) {
  
}

void posiblespalabrasFuncion(const string& argumento) {
  
}

int main(int argc, char *argv[]) {
    string comandos[10] = {"inicializar", "iniciar_inverso", "puntaje", "salir", "iniciar_arbol",
                           "iniciar_arbol_inverso", "palabras_por_prefijo", "palabras_por_sufijo",
                           "grafo_de_palabras", "posibles_palabras"};

    string input_usuario;

    while (true) {
        cout << "$ ";
        getline(cin, input_usuario);

        istringstream isstream(input_usuario);
        string comando;

        // Extrae el primer token (comando) de la línea de entrada
        isstream >> comando;

        unordered_map<string, function<void(const string&)>> funciones = {
            {"inicializar", inicializarFuncion},
            {"iniciar_inverso", iniciarInversoFuncion},
            {"puntaje", puntajeFuncion},
            {"iniciar_arbol", iniciararbolFuncion},
            {"iniciar_arbol_inverso", iniciararbolinversoFuncion},
            {"palabras_por_prefijo", palabrasporprefijoFuncion},
            {"palabras_por_sufijo", palabrasporsufijoFuncion},
            {"grafo_de_palabras", grafodepalabrasFuncion},
            {"posibles_palabras", posiblespalabrasFuncion}
        };

         auto it = funciones.find(comando);
        if (it != funciones.end()) {
            string argumento;
            while (isstream >> argumento) {
                it->second(argumento);
            }
        } else {
          
        }

        if (comando == "salir")
        {
          break;
        }
        
    }

    return 0;
}

