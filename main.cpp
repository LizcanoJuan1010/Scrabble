#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include "Scrabble.h"
#include "Dictionary.h"
#include <map>

using namespace std;
int main(int argc, char *argv[])
{
   
    string comandos[11] = {"inicializar", "iniciar_inverso", "puntaje", "salir", "iniciar_arbol",
                           "iniciar_arbol_inverso", "palabras_por_prefijo", "palabras_por_sufijo",
                           "grafo_de_palabras", "posibles_palabras", "ayuda"};
    Dictionary dictionary;
    Scrabble scrabble;
    string command, input_user;


    do
    {
        cout << "$";
        getline(cin, input_user);

        istringstream isstream(input_user);

       
        isstream >> command;
      

        string argument;
        isstream >> argument;
       

        if (command == "inicializar")
    {   
        if(argument.empty())
        {
            cout << "No hay argumento para poder inicializar\n";
        }
        else
        {
            scrabble.initializeFunction(argument, dictionary);
        }
    }
    else if (command == "iniciar_inverso")
    {
         if(argument.empty())
        {
            cout << "No hay argumento para poder inicializar\n";
        }
        else
        {
           scrabble.startInverseFunction(argument, dictionary);
        }
        
    }
    else if (command == "puntaje")
    {
        if(argument.empty())
        {
            cout << "No hay argumento para poder inicializar\n";
        }
        else
        {
            scrabble.result(argument, dictionary);
        }
       
    }
    else if (command == "iniciar_arbol")
    {
        scrabble.InitizalizeTrie(argument);
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
        // palabrasporsufijoFuncion(argumento, dictionary);
    }
    else if (command == "grafo_de_palabras")
    {
       // grafodepalabrasFuncion(argumento);
    }
    else if (command == "posibles_palabras")
    {
        // posiblespalabrasFuncion(argumento);
    }
    else if (command == "ayuda")
    {
        if (argument.empty())
        {
            scrabble.ShowHelp();
        }
        else
        {
            scrabble.help(argument);
        }
    }
    else if (command == "salir")
    {
        cout << "\n";
    }
    else 
    {
        cout << "Comando inexistente\n";
    }
} while (command != "salir");

    return 0;
}
