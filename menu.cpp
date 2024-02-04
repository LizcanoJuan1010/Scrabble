#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;


void Comandos(string auxilar,string argumento);

int main(int argc, char *argv[]) {

string comandos[10] = {"inicializar", "iniciar_inverso", "puntaje", "salir", "iniciar_arbol", 
"iniciar_arbol_inverso", "palabras_por_prefijo", "palabras_por_sufijo", "grafo_de_palabras", 
"posibles_palabras"};
    string input_usuario;
    
    cout << "Ingrese un comando: ";
    getline(cin, input_usuario);

    istringstream isstream(input_usuario);
    string comando;
    
    // Extrae el primer token (comando) de la línea de entrada
    isstream >> comando;

    bool existe = false;


    for (int i = 0; i < 10; i++) {
        if (comandos[i] == comando) {
            existe = true;
            
            string auxilar = comandos[i];
            string argumento;
           
            while (isstream >> argumento) {
                
            }

             Comandos(auxilar, argumento);

            break; // Termina el bucle si encuentra el comando
        }
    }

    if (!existe) {
        cout << "Comando no reconocido. Inténtalo de nuevo." << endl;
    }

}

void Comandos(string auxilar,string argumento){

    if(auxilar == "inicializar"){
        
    }else if (auxilar == "iniciar_inverso")
    {
      /* code */
    }else if (auxilar == "puntaje")
    {
      /* code */
    } else if (auxilar == "salir")
    {
      /* code */
    } else if (auxilar == "iniciar_arbol")
    {
      /* code */
    } else if (auxilar == "iniciar_arbol_inverso")
    {
      /* code */
    } else if (auxilar == "palabras_por_prefijo")
    {
      /* code */
    } else if (auxilar == "palabras_por_sufijo")
    {
      /* code */
    } else if (auxilar == "grafo_de_palabras")
    {
      /* code */
    } else if (auxilar == "posibles_palabras")
    {
      /* code */
    }
}
