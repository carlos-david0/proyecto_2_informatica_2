#ifndef JUEGO_H
#define JUEGO_H
#include "casilla.h"
#include <string>

class juego
{
public:
    juego(int filas, int columnas);
    ~juego();
    std::string print_tablero();
    bool movimiento_valido(std::string casilla, int turno);
    bool movimiento_valido(int fila, int columna, int turno);
    int movimientos_disponibles(int turno);
private:
    casilla** tablero;
    int filas;
    int columnas;
};

#endif // JUEGO_H
