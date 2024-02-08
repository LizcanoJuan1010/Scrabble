#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <cstdlib>
#include "Scrabble.cpp"
using namespace std;
int main(int argc, char *argv[])
{
    system("color 02");
    string comandos[10] = {"inicializar", "iniciar_inverso", "puntaje", "salir", "iniciar_arbol",
                           "iniciar_arbol_inverso", "palabras_por_prefijo", "palabras_por_sufijo",
                           "grafo_de_palabras", "posibles_palabras"};

    string input_usuario;
    vector<string> diccionario;
    string comando;
    do
    {
        cout << "PS C:/Users/> $ ";
        getline(cin, input_usuario);

        istringstream isstream(input_usuario);

        // Extrae el primer token (comando) de la línea de entrada
        isstream >> comando;

        string argumento;
        isstream >> argumento;

        if (comando == "inicializar")
        {
            inicializarFuncion(argumento, diccionario);
        }
        else if (comando == "iniciar_inverso")
        {
            iniciarInversoFuncion(argumento);
        }
        else if (comando == "puntaje")
        {
            puntajeFuncion(argumento, diccionario);
        }
        else if (comando == "iniciar_arbol")
        {
            iniciararbolFuncion(argumento);
        }
        else if (comando == "iniciar_arbol_inverso")
        {
            iniciararbolinversoFuncion(argumento);
        }
        else if (comando == "palabras_por_prefijo")
        {
            palabrasporprefijoFuncion(argumento, diccionario);
        }
        else if (comando == "palabras_por_sufijo")
        {
            palabrasporsufijoFuncion(argumento, diccionario);
        }
        else if (comando == "grafo_de_palabras")
        {
            grafodepalabrasFuncion(argumento);
        }
        else if (comando == "posibles_palabras")
        {
            posiblespalabrasFuncion(argumento);
        }
        else
        {
            cout << "Comando inexistente\n";
        };

    } while (comando != "salir");

    return 0;
}
