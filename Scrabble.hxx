#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

void inicializarFuncion(const string &argumento, vector<string> &diccionario)
{

    ifstream archivoEntrada(argumento, ios::in);

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open())
    {

        string palabra;

        while (getline(archivoEntrada, palabra))
        {
            for (char c : palabra)
            {
                if (!isalpha(c) && !isspace(c))
                {
                    cout << "Hay una palabra que contiene símbolos inválidos en el diccionario" << endl;
                    return;
                }
            }
            diccionario.push_back(palabra);
        }

        archivoEntrada.close();
        cout << " El diccionario se ha inicializado correctamente" << endl;
    }
    else
    {
        cout << " El archivo diccionario.txt no existe o no puede ser leído." << endl;
    }
}

void iniciarInversoFuncion(const string &argumento, vector<string> &palabrasInv)
{
    ifstream archivoEntrada(argumento);
    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open())
    {
        string palabra;
        while (getline(archivoEntrada, palabra))
        {
            for (char c : palabra)
            {
                if (!isalpha(c) && !isspace(c))
                {
                    cout << "Hay una palabra que contiene símbolos inválidos en el diccionario" << endl;
                    return;
                }
            }
            int length = palabra.length();
            for (int i = 0; i < length / 2; i++)
            {
                swap(palabra[i], palabra[length - i - 1]);
            }
            palabrasInv.push_back(palabra);
        }
        archivoEntrada.close();
        int con = 0;

        cout << " El diccionario se ha inicializado correctamente" << endl;
    }
    else
    {
        cerr << " El archivo diccionario.txt no existe o no puede ser leído." << endl;
    }
}

void puntajeFuncion(const string &argumento, vector<string> &diccionario, vector<string> &palabrasInv)
{
    bool palabraEnDiccionario = false;
    for (char c : argumento)
    {   c= tolower(c);
        // Verifica si el carácter no es una letra o un espacio en blanco
        if (!isalpha(c) && !isspace(c))
        {
            cout << "La palabra contiene símbolos inválidos" << endl;
            return; // Sale de la función si se encuentra un carácter inválido
        }
    }
    for (const auto &palabraDic : diccionario)
    {
        string arg=argumento;
       transform(arg.begin(), arg.end(), arg.begin(), ::tolower);
        if (palabraDic == arg)
        {
            palabraEnDiccionario = true;
            break; // No es necesario continuar verificando el diccionario si ya encontramos la palabra
        }
    }
    if (!palabraEnDiccionario)
    {
        for (const auto &palabraDic : palabrasInv)
        {   string arg1=argumento;
            transform(arg1.begin(), arg1.end(), arg1.begin(), ::tolower);
            if (palabraDic == arg1)
            {
                palabraEnDiccionario = true;
                break; // No es necesario continuar verificando el diccionario si ya encontramos la palabra
            }
        }
    }

    if (!palabraEnDiccionario)
    {
        cout << "La palabra no existe en el diccionario" << endl;
    }
    else
    {
        int puntaje = 0;
        for (char c : argumento)
        {
            // Verifica si el carácter no es una letra o un espacio en blanco
            if (!isalpha(c) && !isspace(c))
            {
                cout << "La palabra contiene símbolos inválidos" << endl;
                return; // Sale de la función si se encuentra un carácter inválido
            }
            else
            {
                c = toupper(c);
            }
            if (c == 'E' || c == 'A' || c == 'I' || c == 'O' || c == 'N' || c == 'R' || c == 'T' || c == 'L' || c == 'S' || c == 'U')
                puntaje++;
            if (c == 'D' || c == 'G')
                puntaje = puntaje + 2;
            if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
                puntaje = puntaje + 3;
            if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
                puntaje = puntaje + 4;
            if (c == 'K')
                puntaje = puntaje + 5;
            if (c == 'J' || c == 'X')
                puntaje = puntaje + 8;
            if (c == 'Q' || c == 'Z')
                puntaje = puntaje + 10;
        }

        // Si no se encontraron caracteres inválidos, imprime el mensaje de puntaje
        cout << "La palabra tiene un puntaje de:     " << puntaje << endl;
    }
}

void ayuda(std::string& comando){

    if(comando == "inicializar" ){
        cout<<'\t' <<"- $inicializar (Fomato: $inicializar) Descripcion: Este comando inicia el juego preguntando la cantidad de jugadores y ubicar a los jugadores " <<endl;
        cout<<"  o si desea inicializar con el nombre de archivo utilice el siguiente formato..."<<endl;
        cout<<'\t' <<"- $inicializar (Formato: $inicializar <nombre_archivo>) Descripcion: Inicializa el juego desde archivo <nombre_archivo> con datos guardados o comprimidos. "<<endl;
    }else if(comando == "turno"){
        cout<<'\t' <<"- $turno (Fomato: $turno <id_jugador>) Descripcion: Permite que un jugador realice todas las acciones necesarias en su turno, incluyendo la asignación de nuevas unidades, realizar ataques y fortificar sus territorios. "<<endl;
    }else if(comando == "guardar"){
        cout<<'\t' <<"- $guardar (Fomato: $guardar <nombre_archivo>) Descripcion: Permite guardar el estado actual del juego en un archivo de texto. El archivo incluirá información sobre la cantidad de jugadores, sus nombres, colores, países ocupados, unidades de ejército en cada país, tarjetas poseídas y sus identificadores."<<endl;
    }else if(comando == "guardar_comprimido"){
        cout<<'\t' <<"- $guardar_comprimido  (Fomato: $guardar_comprimido <nombre_archivo>) Descripcion: Almacena el estado del juego en un archivo binario comprimido usando codificación de Huffman "<<endl;
    }else if(comando == "costo_conquista"){
        cout<<'\t' <<"- $costo_conquista (Fomato: $costo_conquista  <territorio>) Descripcion: Programa calcula conquista de territorios cercanos al objetivo, análisis del jugador actual. "<<endl;
    }else if(comando == "conquista_mas_barata"){
        cout<<'\t' <<"- $conquista_mas_barata (Formato: $conquista_mas_barata) Descripcion: Buscar territorio con menor pérdida de ejércitos para jugador actual. "<<endl;
    }else if(comando == "salir"){
        cout<<'\t' <<"- $salir (Fomato: $salir) Descripcion: Fin del juego "<<endl;
    }else if(comando == "ayuda"){
        cout<<'\t' << "- $ayuda (Fomato: $ayuda nombre_comando)"<<endl;
    }else if(comando == "todos"){
        cout<<'\t' << "Para mayor facilidad escribe ($ayuda nombre_comando)"<<endl;
        cout<<'\t' << "Por ejemplo: $ayuda cargar_elementos" << endl <<endl;
        cout<<'\t' << "Lista de comandos: "<<endl;

        cout<<'\t' << "- $inicializar (Fomato: $inicializar)" <<endl;
        cout<<'\t' << "- $turno (Fomato: $turno <id_jugador>)"<<endl;
        cout<<'\t' << "- $guardar (Fomato: $guardar <nombre_archivo>)"<<endl;
        cout<<'\t' << "- $guardar_comprimido  (Fomato: $guardar_comprimido <nombre_archivo>)"<<endl;
        cout<<'\t' << "- $inicializar (Formato: $inicializar <nombre_archivo>)"<<endl;
        cout<<'\t' << "- $costo_conquista (Fomato: $costo_conquista  <territorio>)"<<endl;
        cout<<'\t' << "- $conquista_mas_barata (Formato: $conquista_mas_barata)"<<endl;
        cout<<'\t' << "- $salir (Fomato: $salir)"<<endl;
        cout<<'\t' << "- $ayuda    (Fomato: $ayuda nombre_comando)"<<endl;
    }else{
        cout<<'\t' << " Comando " << comando << " no conocido :(" << endl;
    }}
    void mostrarMenuAyuda()
{
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
void exitfuncion(const string &argumento)
{

    exit(0);
}

void iniciararbolFuncion(const string &argumento)
{
    ifstream archivoEntrada(argumento);

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open())
    {

        string palabra;

        while (getline(archivoEntrada, palabra))
        {
        }

        archivoEntrada.close();
        cout << " El árbol del diccionario ya ha sido inicializado.\n"
             << endl;
    }
    else
    {
        cout << " El archivo diccionario.txt no existe o no puede ser leído.\n"
             << endl;
    }
}

void iniciararbolinversoFuncion(const string &argumento)
{
    ifstream archivoEntrada(argumento);
    vector<string> palabras;
    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open())
    {
        string palabra;
        while (getline(archivoEntrada, palabra))
        {
            palabras.push_back(palabra);
        }
        archivoEntrada.close();

        cout << " El árbol del diccionario inverso se ha inicializado correctamente.\n"
             << endl;
    }
    else
    {
        cerr << " El archivo diccionario.txt no existe o no puede ser leído.\n"
             << endl;
    }
}

void palabrasporprefijoFuncion(const string &argumento, vector<string> &diccionario)
{

    bool existepref;
    int contador = 0;
    // Utiliza la función find para buscar la parte en la palabra
    for (const auto &palabraDic : diccionario)
    {
        existepref = false;
        existepref = palabraDic.find(argumento) == 0;
        if (existepref)
            contador++;
    }
    if (contador == 0)
    {
        cout << "Prefijo prefijo no pudo encontrarse en el diccionario.\n";
    }
    else
    {
        cout << "Las palabras que inician con este prefijo son:\n";
    }
}

void palabrasporsufijoFuncion(const string &argumento, vector<string> &diccionario)
{
    bool existesuf;
    int contador = 0;
    // Utiliza la función find para buscar la parte en la palabra
    for (const auto &palabraDic : diccionario)
    {
        existesuf = false;
        size_t posicion = palabraDic.rfind(argumento);
        existesuf = posicion != string::npos && posicion == palabraDic.length() - argumento.length(); // string::npos para cosas no enconradas o invalidas
        if (existesuf)
            contador++;
    }
    if (contador == 0)
    {
        cout << " Sufijo sufijo no pudo encontrarse en el diccionario.\n";
    }
    else
    {
        cout << "Las palabras que terminan con este sufijo son:\n";
    }
}

void grafodepalabrasFuncion(const string &argumento)
{
    cout << "Grafo construído correctamente.\n";
}

void posiblespalabrasFuncion(const string &argumento)
{
    for (char c : argumento)
    {
        // Verifica si el carácter no es una letra o un espacio en blanco
        if (!isalpha(c) && !isspace(c))
        {
            cout << "La cadena letras contiene símbolos inválidos" << endl;
            return; // Sale de la función si se encuentra un carácter inválido
        }
    }
    cout << "Las posibles palabras a construir con las letras letras son:\n";
}
