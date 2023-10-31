#include "juego.h"
#include <iostream>
using namespace std;

// - jugador 2
// * jugador 1

int main()
{
    const int filas = 8;
    const int columnas = 8;
    juego current(filas,columnas);
    while(1){
    cout << current.print_tablero();
    std::string casilla;
    cin >> casilla;
    cout << current.movimiento_valido(casilla, 1) << endl;
    }
}
