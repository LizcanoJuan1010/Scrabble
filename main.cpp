#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include "Scrabble.h"
#include "Dictionary.h"
using namespace std;
int main(int argc, char *argv[])
{
   
    string comandos[10] = {"inicializar", "iniciar_inverso", "puntaje", "salir", "iniciar_arbol",
                           "iniciar_arbol_inverso", "palabras_por_prefijo", "palabras_por_sufijo",
                           "grafo_de_palabras", "posibles_palabras"};
    Dictionary dictionary;
    Scrabble scrabble;
    string input_usuario;
 
    string command;
    do
    {
        cout << "$";
        getline(cin, input_usuario);

        istringstream isstream(input_usuario);

        // Extrae el primer token (comando) de la línea de entrada
        isstream >> command;
        cout << "Comando: " << command << endl;

        string argument;
        isstream >> argument;
        cout << "Argumento: " << argument << endl;

        if (command == "inicializar")
        {
            cout << "inicializando" << endl;
            scrabble.initializeFunction(argument,dictionary);
        }
        else if (command == "iniciar_inverso")
        {
            scrabble.startInverseFunction(argument,dictionary);
        }
        else if (command == "puntaje")
        {
            scrabble.result(argument, dictionary);
        }
        else if (command == "iniciar_arbol")
        {
           // iniciararbolFuncion(argumento);
        }
        else if (command == "iniciar_arbol_inverso")
        {
           // iniciararbolinversoFuncion(argumento);
        }
        else if (command == "palabras_por_prefijo")
        {
           // palabrasporprefijoFuncion(argumento, dictionary);
        }
        else if (command == "palabras_por_sufijo")
        {
            //palabrasporsufijoFuncion(argumento, dictionary);
        }
        else if (command == "grafo_de_palabras")
        {
           // grafodepalabrasFuncion(argumento);
        }
        else if (command == "posibles_palabras")
        {
            //posiblespalabrasFuncion(argumento);
        }
        else
        {
            cout << "Comando inexistente\n";
        };

    } while (command != "salir");

    return 0;
}
