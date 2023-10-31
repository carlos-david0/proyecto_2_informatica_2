#include "juego.h"
juego::juego(int filas, int columnas)
{
    tablero = new casilla*[filas];
    for (int i = 0; i < filas; i++) {
        tablero[i] = new casilla[columnas];
    }
    tablero[(filas/2)-1][(columnas/2)-1].set_estado(1);
    tablero[(filas/2)][(columnas/2)].set_estado(1);
    tablero[(filas/2)][(columnas/2)-1].set_estado(2);
    tablero[(filas/2)-1][(columnas/2)].set_estado(2);
    this->columnas = columnas;
    this->filas = filas;
}

juego::~juego()
{
    for (int i = 0; i < filas; i++) {
        delete tablero[i];
    }
    delete tablero;
}

std::string juego::print_tablero()
{
    std::string tabla = "| |";
    for (int i = 0; i < columnas; i++){
        tabla += "|";
        tabla += char(65+i);
        tabla += "|";
    }
    tabla += "\n";
    for (int i = 0; i < filas; i++) {
        tabla += "|";
        tabla += std::to_string(1+i);
        tabla += "|";
        for (int j = 0; j < columnas; j++) {
            tabla += "|";
            tabla += tablero[i][j].get_estado();
            tabla += "|";
        }
        tabla += "\n";
    }
    return tabla;
}

bool juego::movimiento_valido(int fila, int columna, int turno)
{
    char enemigo = '-';
    if (turno % 2 == 0){
        enemigo = '*';
    }
    bool validez = false;
    bool encontrado = false;
    int i = 1;
    while(columna - i >= 0){
        if (tablero[fila][columna-i].get_estado() == ' '){
            break;
        }else if (tablero[fila][columna-i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez = true;
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(columna + i < columnas){
        if (tablero[fila][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila][columna+i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez = true;
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila - i >= 0){
        if (tablero[fila-i][columna].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez = true;
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila + i < filas){
        if (tablero[fila+i][columna].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez = true;
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila + i < filas && columna + i < columnas){
        if (tablero[fila+i][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna+i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez = true;
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila - i >= 0 && columna - i >= 0){
        if (tablero[fila+i][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna-i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez = true;
        }else{
            break;
        }
        i++;
    }
    if (tablero[fila][columna].get_estado() != ' '){
        validez = false;
    }
    return validez;
}

int juego::movimientos_disponibles(int turno)
{
    int value = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(movimiento_valido(i, j, turno)){
                value ++;
            }
        }
    }
    return value;
}
