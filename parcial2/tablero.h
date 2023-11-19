#ifndef TABLERO_H
#define TABLERO_H
#include "casilla.h"
#include <string>

class tablero
{
public:
    tablero();
    tablero(int filas, int columnas);
    ~tablero();
    std::string print_tablero();
    std::string movimiento_valido(std::string casilla, int turno);
    bool movimiento_valido(int fila, int columna, int turno);
    std::string movimientos_disponibles(int turno);
    void tomar_turno(int turno, std::string casilla);
    int contador_j1();
    int contador_j2();
    int ganador(int j1, int j2);
private:
    casilla **casillas;
    int filas;
    int columnas;
};

#endif // JUEGO_H
