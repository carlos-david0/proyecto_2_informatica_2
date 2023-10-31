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
    bool movimientos_disponibles();
private:
    casilla** tablero;
    int filas;
    int columnas;
};

#endif // JUEGO_H
