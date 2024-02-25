#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype> 
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
    vector<string> diccionarioInv;
    string comando;
    do
    {
        cout << " $ ";
        getline(cin, input_usuario);

        istringstream isstream(input_usuario);

        // Extrae el primer token (comando) de la línea de entrada
        isstream >> comando;

        string argumento;
        isstream >> argumento;

        if (comando == "inicializar")
        {
            if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else            
            inicializarFuncion(argumento, diccionario);
        }
        else if (comando == "iniciar_inverso")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            iniciarInversoFuncion(argumento,diccionarioInv);
        }
        else if (comando == "puntaje")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            puntajeFuncion(argumento, diccionario,diccionarioInv);
        }
        else if (comando == "iniciar_arbol")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            iniciararbolFuncion(argumento);
        }
        else if (comando == "iniciar_arbol_inverso")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            iniciararbolinversoFuncion(argumento);
        }
        else if (comando == "palabras_por_prefijo")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            palabrasporprefijoFuncion(argumento, diccionario);
        }
        else if (comando == "palabras_por_sufijo")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            palabrasporsufijoFuncion(argumento, diccionario);
        }
        else if (comando == "grafo_de_palabras")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            grafodepalabrasFuncion(argumento);
        }
        else if (comando == "posibles_palabras")
        {   if(argumento.empty()){
                cout<<"No hay argumento para poder inializar\n";
            }else
            posiblespalabrasFuncion(argumento);
        }
        else if(comando=="salir"){
                cout<<"\n";
        }else
        {
            cout << "Comando inexistente\n";
        };

    } while (comando != "salir");

    return 0;
}
