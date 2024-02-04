#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;


void menu();
void menudeljuego();
void opciones(int opcion);

void ListadeAyudas();

int main(int argc, char *argv[]) {

  int opcion = 0;
  do{
    menu();
    cout<<"PS C:/Users/> $";
    cin>> opcion;

  opciones(opcion);

  }while(opcion !=3);
    return 0;
}


void menu(){
  
  cout<<"---------Scrabble---------"<< endl;
  cout<<"1)Jugar"<< endl;
  cout<<"2) Ayuda"<< endl;
  cout<<"3) Salir" << endl;
  cout<<"---------------------------"<< endl;
}

void opciones(int opcion){
    switch (opcion)
    {
    case 1:
      menudeljuego();
      break;
    
    case 2:
      ListadeAyudas();
      break;
      
    case 3:

      cout<<"Vuela Pronto!!"<<endl;
      break;
    
    default:
    cout<< "Opcion no Valida. Intentelo nuevamente" << endl;
      break;
    }
}

 void menudeljuego() {
    string comandos[10] = {"inicializar", "iniciar_inverso", "puntaje", "salir", "iniciar_arbol", "iniciar_arbol_inverso", "palabras_por_prefijo", "palabras_por_sufijo", "grafo_de_palabras", "posibles_palabras"};
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

            // Aquí puedes agregar el código correspondiente al comando encontrado

            // Ahora verifica si hay argumentos adicionales y procesa según sea necesario
            string argumento;
            while (isstream >> argumento) {
                // Procesa los argumentos adicionales aquí
                cout << "Argumento adicional: " << argumento << endl;
            }

            break; // Termina el bucle si encuentra el comando
        }
    }

    if (!existe) {
        cout << "Comando no reconocido. Inténtalo de nuevo." << endl;
    }
}
      

 

 void ListadeAyudas(){

   cout<< "Ayuda" << endl;
 }