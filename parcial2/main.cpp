#include "juego.h"
#include "herramientas.h"
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
        bool game_over = false;
        std::string casilla = "";
        int turno = 0;
        juego current(filas,columnas);
        while (!game_over || current.movimientos_disponibles(turno) != "") {
            if(current.movimientos_disponibles(turno) == ""){
                cout << "el jugador no tiene movimientos disponibles" << endl;
                turno++;
                game_over = true;
            }else{
                game_over = false;
                cout << "Turno: " << turno + 1;
                cout << ", jugador: ";
                if (turno%2 == 0){
                    cout << "-" << endl;
                }else{
                    cout << "*" << endl;
                }
                cout << current.print_tablero();
                cout << "movimientos disponibles: " << endl;
                cout << current.movimientos_disponibles(turno) << endl;
                cout << "";
                std::getline (std::cin,casilla);
                while (current.movimiento_valido(casilla, turno) == ""){
                    cout << "digite su movimiento (Columna en mayuscula y fila):";
                    std::getline (std::cin,casilla);
                }
                current.tomar_turno(turno, casilla);
                turno ++;
                casilla = "";
            }
        }
        cout << current.print_tablero();
        int j1 = current.contador_j1();
        int j2 = current.contador_j2();
        if (current.ganador(j1, j2) != 0){
            cout << "El ganador es el jugador: " << current.ganador(j1,j2)<< " " << j1 << " a " << j2 << endl;
        }else{
            cout << "empate a: " << j1 << endl;
        }
        //al finalizar la partida guardar la información de la partida
        std::string namej1 = "";
        std::string namej2 = "";
        cout << "inserte el nombre del jugador 1: ";
        cin >> namej1;
        cout << "inserte el nombre del jugador 2: ";
        cin >> namej2;
        if (current.ganador(j1,j2) == 1){
            guardar_partida(to_string(j1), namej1 + " vs " + namej2, namej1);
        }else if (current.ganador(j1,j2) == 2){
            guardar_partida(to_string(j2), namej1+ " vs "+namej2, namej2);
        }else{
            guardar_partida(to_string(j1), namej1+" vs "+namej2, "empate");
        }
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
