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
    std::string movimiento_valido(std::string casilla, int turno);
    bool movimiento_valido(int fila, int columna, int turno);
    std::string movimientos_disponibles(int turno);
    void tomar_turno(int turno, std::string casilla);
    int contador_j1();
    int contador_j2();
    int ganador(int j1, int j2);
private:
    casilla** tablero;
    int filas;
    int columnas;
};

#endif // JUEGO_H
