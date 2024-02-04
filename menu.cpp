#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    system("color 02");
  cout<<"c:/Ingrese_linea_de_comando:>\n";
  string linea;
  char line[15];
  vector<string> sentence;
  string word;
  do{
  cin.getline(line,15);
  cout<<"PS C:/Users/>";
  //configuracion del juego
  istringstream isstream(line);
  sentence.clear();
  while(isstream>>word)
  sentence.push_back(word);

  if(sentence[0]=="inicializar"){cout<<sentence[1];}
  else if(sentence[0]=="iniciar_inverso"){}
  else if(sentence[0]=="puntaje palabra"){}
  else if(sentence[0]=="Salir"){}

  //Busqueda de palabra
  else if(sentence[0]=="iniciar_arbol"){}
  else if(sentence[0]=="iniciar_arbol_inverso"){}
  else if(sentence[0]=="palabras_por_prefijo"){}
  else if(sentence[0]=="palabras_por_sufijo"){}
  //combinaciones de letra
  else if(sentence[0]=="grafo_de_palabras"){}  
  else if(sentence[0]=="posibles_palabras"){} 
  else{
    cout<<"Lo que dijito no es valido\n";
  }
  sentence.clear();
  }while(sentence[0]!="Salir");
    return 0;
}