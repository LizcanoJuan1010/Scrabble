#include <iostream>
#include <cstdlib>  // Para usar funciones
#include <vector>
#include <sstream>
#include <fstream>  // para usar archivos

using namespace std;

bool arbolInicializado = false; // árbol del diccionario inicializado
bool diccionarioInversoInicializado = false; // diccionario inverso inicializado
bool grafoDePalabrasInicializado = false; // grafo de palabras inicializado


void mostrarAyuda() {
    cout << "Comandos disponibles:" << endl
         << "iniciar inverso diccionario.txt - Inicia el diccionario inverso con el archivo especificado." << endl
         << "puntaje palabra - Calcula el puntaje de una palabra según las reglas de Scrabble." << endl
         << "palabras por prefijo [prefijo] - Muestra palabras que comienzan con el prefijo dado." << endl
         << "palabras por sufijo [sufijo] - Muestra palabras que terminan con el sufijo dado." << endl
         << "posibles palabras [letras] - Muestra posibles palabras a construir con las letras dadas." << endl
         << "grafo de palabras - Construye un grafo de palabras basado en el diccionario." << endl
         << "ayuda - Muestra este menú de ayuda." << endl
         << "salir - Termina la ejecución del programa." << endl;
}

void mostrarAyudaComando(const string& comando) {
    cout << "Ayuda para el comando: " << comando << endl;
}

int main(){
    cout << "Bienvenid@ al sistema de apoyo de Scrabble" << endl;
    mostrarAyuda();

    string linea;
    char line[256];
    vector<string> comandos;
    string palabras;
    do{
        cout << "$ ";
        cin.getline(line, 256);
        istringstream isstream(line);
        comandos.clear();
        while(isstream >> palabras)
            comandos.push_back(palabras);

        if(comandos.empty()) continue; // Si no se ingresa nada continúa.

        if(comandos[0] == "ayuda") {
            if(comandos.size() == 1) {
                mostrarAyuda();
            } else {
                mostrarAyudaComando(comandos[1]);
            }
        } else if(comandos[0] == "salir") {
            break; // Finaliza el programa.
        } else if(comandos[0] == "iniciar" && comandos.size() > 2 && comandos[1] == "inverso") {
            cout << "Iniciando diccionario inverso con el archivo: " << comandos[2] << endl;
        } else if(comandos[0] == "puntaje" && comandos.size() > 1) {
            cout << "Calculando puntaje para la palabra: " << comandos[1] << endl;
        } else if(comandos[0] == "palabras" && comandos.size() > 3) {
            if(comandos[1] == "por" && comandos[2] == "prefijo") {
                cout << "Buscando palabras por prefijo: " << comandos[3] << endl;
            } else if(comandos[1] == "por" && comandos[2] == "sufijo") {
                cout << "Buscando palabras por sufijo: " << comandos[3] << endl;
            }
        } else if(comandos[0] == "posibles" && comandos.size() > 2 && comandos[1] == "palabras") {
            cout << "Buscando posibles palabras con las letras: " << comandos[2] << endl;
        } else if(comandos[0] == "grafo" && comandos.size() > 2 && comandos[1] == "de" && comandos[2] == "palabras") {
            cout << "Construyendo grafo de palabras." << endl;
        } else {
            cout << "Comando incorrecto o faltan argumentos." << endl;
            mostrarAyudaComando(comandos[0]);
        }
    } while(true);

    return 0;
}
