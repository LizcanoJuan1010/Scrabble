#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]){
    system("color 02");
    cout << "La versión de C++ es: " << __cplusplus << std::endl;
  cout<<"Ingrese linea de comando:\n";
  string linea;
  char line[15];
  do{
  cin.getline(line,15);
  cout<<line;
  //configuracion del juego
  if(line=="inicializar diccionario.txt"){}
  if(line=="iniciar_inverso diccionario.txt"){}
  if(line=="puntaje palabra"){}
  if(line=="salir"){}
  if(line=="XD"){cout<<"No negro";  }
  //Busqueda de palabra
  if(line=="iniciar_arbol diccionario.txt"){}
  if(line=="iniciar_arbol_inverso diccionario.txt"){}
  if(line=="palabras_por_prefijo prefijo"){}
  if(line=="palabras_por_sufijo sufijo"){}
  //combinaciones de letra
  if(line=="grafo_de_palabras"){}  
  if(line=="posibles_palabras letras"){} 
  }while(line=="Salir");
    return 0;
}