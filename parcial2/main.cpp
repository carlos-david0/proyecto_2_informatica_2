#include "juego.h"
#include <iostream>

using namespace std;

// * jugador 2
// - jugador 1


using namespace std;
int main()
{
    const int filas = 8;
    const int columnas = 8;
    short opcion;
    bool en_juego=true;

    //menu de inicio
    imprimir_menu(1);
    do
    {
        cout<< "Ingrese una opcion: " <<endl;
        cin>> opcion;
    }
    while(opcion_invalida(opcion));

    while(en_juego){
    if (opcion==1){
        juego *activo;
        activo = new juego(filas, columnas);
        activo->partida();
    }
    else if(opcion==2){
        mostrar_historial();
    }

    else if(opcion==3){
        break;
    }
    //menu de salida
    imprimir_menu(2);
    do
    {
        cout<< "Ingrese una opcion: " <<endl;
        cin>> opcion;
    }
    while(opcion_invalida(opcion));
    }
    cout<< "Haz salido del juego!" <<endl;
    return 0;
}
