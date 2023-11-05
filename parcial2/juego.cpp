#include "juego.h"
#include <cmath>
#include <iostream>
juego::juego(int filas, int columnas)
{
    tablero = new casilla*[filas];
    for (int i = 0; i < filas; i++) {
        tablero[i] = new casilla[columnas];
    }
    tablero[(filas/2)-1][(columnas/2)-1].set_estado('*');
    tablero[(filas/2)][(columnas/2)].set_estado('*');
    tablero[(filas/2)][(columnas/2)-1].set_estado('-');
    tablero[(filas/2)-1][(columnas/2)].set_estado('-');
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

std::string juego::movimiento_valido(std::string casilla, int turno)
{
    char enemigo = '-';
    if (turno % 2 == 0){
        enemigo = '*';
    }
    int fila = int(casilla[1]) - 49;
    int columna = int(casilla[0]) - 65;
    std::string validez = "";
    bool encontrado = false;
    int i = 1;
    if (casilla.size()!= 2 || fila < 0 || columna < 0 || fila >= filas || columna >= columnas){
        validez = "";
    }else{
    while(columna - i >= 0){
        if (tablero[fila][columna-i].get_estado() == ' '){
            break;
        }else if (tablero[fila][columna-i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez += std::to_string(1);
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
            validez += std::to_string(2);
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
            validez += std::to_string(3);
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
            validez += std::to_string(4);
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
            validez += std::to_string(5);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila - i >= 0 && columna - i >= 0){
        if (tablero[fila-i][columna-i].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna-i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez += std::to_string(6);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila + i < filas && columna - i >= 0){
        if (tablero[fila+i][columna - i].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna-i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez += std::to_string(7);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    encontrado = false;
    while(fila - i >= 0 && columna + i < columnas){
        if (tablero[fila-i][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna+i].get_estado() == enemigo){
            encontrado = true;
        } else if (encontrado == true){
            validez += std::to_string(8);
        }else{
            break;
        }
        i++;
    }
    if (tablero[fila][columna].get_estado() != ' '){
        validez = "";
    }
    if (fila < 0 || columna < 0 || fila >= filas || columna >= columnas){
        validez = "";
    }
    }
    return validez;
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
        if (tablero[fila-i][columna-i].get_estado() == ' '){
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
    i = 1;
    encontrado = false;
    while(fila + i < filas && columna - i >= 0){
        if (tablero[fila+i][columna - i].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna-i].get_estado() == enemigo){
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
    while(fila - i >= 0 && columna + i < columnas){
        if (tablero[fila-i][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna+i].get_estado() == enemigo){
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

std::string juego::movimientos_disponibles(int turno)
{
    std::string value = "";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(movimiento_valido(i, j, turno)){
                value += char(j + 65);
                value += std::to_string(i+1);
                value += "\n";
            }
        }
    }
    return value;
}

void juego::tomar_turno(int turno, std::string casilla)
{
    char enemigo = '-';
    char propio = '*';
    if (turno % 2 == 0){
        propio = '-';
        enemigo = '*';
    }
    std::string encierros = movimiento_valido(casilla, turno);
    int fila = int(casilla[1]) - 49;
    int columna = int(casilla[0]) - 65;
    tablero[fila][columna].set_estado(propio);
    int i = 1;
    if (encierros.find("1") != std::string::npos){
    while(columna - i >= 0){
        if (tablero[fila][columna-i].get_estado() == ' '){
            break;
        }else if (tablero[fila][columna-i].get_estado() == enemigo){
            tablero[fila][columna-i].set_estado(propio);
        } else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if (encierros.find("2") != std::string::npos){
    while(columna + i < columnas){
        if (tablero[fila][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila][columna+i].get_estado() == enemigo){
            tablero[fila][columna+i].set_estado(propio);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if (encierros.find("3") != std::string::npos){
    while(fila - i >= 0){
        if (tablero[fila-i][columna].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna].get_estado() == enemigo){
            tablero[fila-i][columna].set_estado(propio);
        } else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if (encierros.find("4") != std::string::npos){
    while(fila + i < filas){
        if (tablero[fila+i][columna].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna].get_estado() == enemigo){
            tablero[fila+i][columna].set_estado(propio);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if(encierros.find("5") != std::string::npos){
    while(fila + i < filas && columna + i < columnas){
        if (tablero[fila+i][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna+i].get_estado() == enemigo){
            tablero[fila+i][columna+i].set_estado(propio);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if(encierros.find("6") != std::string::npos){
    while(fila - i >= 0 && columna - i >= 0){
        if (tablero[fila-i][columna-i].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna-i].get_estado() == enemigo){
            tablero[fila-i][columna-i].set_estado(propio);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if(encierros.find("7") != std::string::npos){
    while(fila + i < filas && columna - i >= 0){
        if (tablero[fila+i][columna - i].get_estado() == ' '){
            break;
        }else if (tablero[fila+i][columna-i].get_estado() == enemigo){
            tablero[fila+i][columna-i].set_estado(propio);
        }else{
            break;
        }
        i++;
    }
    i = 1;
    }
    if(encierros.find("8") != std::string::npos){
    while(fila - i >= 0 && columna + i < columnas){
        if (tablero[fila-i][columna+i].get_estado() == ' '){
            break;
        }else if (tablero[fila-i][columna+i].get_estado() == enemigo){
            tablero[fila-i][columna+i].set_estado(propio);
        }else{
            break;
        }
        i++;
    }
    }
}

int juego::contador_j1()
{
    int j1 = 0; //-
    for(int i = 0; i < filas; i++){
    for(int j = 0; j < columnas; j++){
        if(tablero[i][j].get_estado() == '-'){
            j1++;
            }
        }
    }
    return j1;
}
int juego::contador_j2()
{
    int j2 = 0; //*
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(tablero[i][j].get_estado() == '*'){
            j2++;
            }
        }
    }
    return j2;
}

int juego::ganador(int j1, int j2)
{
    int winner;
    if (j1 > j2){
        winner = 1;
    }else if(j2 < j1){
        winner = 2;
    }else{
        winner = 0;
    }
    return winner;
}
