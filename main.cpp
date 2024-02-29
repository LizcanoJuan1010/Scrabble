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
 
    string comando;
    do
    {
        cout << "$";
        getline(cin, input_usuario);

        istringstream isstream(input_usuario);

        // Extrae el primer token (comando) de la línea de entrada
        isstream >> comando;
        cout << "Comando: " << comando << endl;

        string filepath;
        isstream >> filepath;
        cout << "Argumento: " << filepath << endl;

        if (comando == "inicializar")
        {
            cout << "inicializando" << endl;
            scrabble.inicializarFuncion(filepath,dictionary);
        }
        else if (comando == "iniciar_inverso")
        {
            scrabble.inicializarFuncion(filepath,dictionary);
        }
        else if (comando == "puntaje")
        {
            //puntajeFuncion(argumento);
        }
        else if (comando == "iniciar_arbol")
        {
           // iniciararbolFuncion(argumento);
        }
        else if (comando == "iniciar_arbol_inverso")
        {
           // iniciararbolinversoFuncion(argumento);
        }
        else if (comando == "palabras_por_prefijo")
        {
           // palabrasporprefijoFuncion(argumento, dictionary);
        }
        else if (comando == "palabras_por_sufijo")
        {
            //palabrasporsufijoFuncion(argumento, dictionary);
        }
        else if (comando == "grafo_de_palabras")
        {
           // grafodepalabrasFuncion(argumento);
        }
        else if (comando == "posibles_palabras")
        {
            //posiblespalabrasFuncion(argumento);
        }
        else
        {
            cout << "Comando inexistente\n";
        };

    } while (comando != "salir");

    return 0;
}
