#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>

void imprimir_menu(short menu);
bool opcion_invalida(short opcion);
void guardar_partida(std::string cant_fichas, std::string jugadores, std::string ganador);
void mostrar_historial();

#endif // HERRAMIENTAS_H
