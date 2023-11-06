#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H
#include <string>
using namespace std;

void imprimir_menu(short menu);
bool opcion_invalida(string opcion);
void guardar_partida(int cant_fichas, string jugadores, string ganador);
void mostrar_historial();

#endif // HERRAMIENTAS_H
