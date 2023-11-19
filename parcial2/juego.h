#ifndef JUEGO_H
#define JUEGO_H
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include <iostream>
#include "tablero.h"
#include "jugador.h"

class juego
{
public:
    juego(int filas, int columnas);
    ~juego();
    void partida();
    void guardar_partida(std::string cant_fichas, std::string jugadores, std::string ganador);
private:
    int turno;
    tablero *tablero;
    jugador *j1, *j2;
    bool game_over;
};

void imprimir_menu(short menu);
bool opcion_invalida(short opcion);
void mostrar_historial();


#endif // HERRAMIENTAS_H

