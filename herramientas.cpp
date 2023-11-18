#include "herramientas.h"
#include <fstream>
#include <string>
#include <time.h>
#include <iostream>

using namespace std;

void imprimir_menu(short menu)
{
    switch(menu){
    case 1:
        cout<<"       BIENVENIDO A OTHELLO        "<< endl;
        cout<<"----------MENU PRINCIPAL-----------"<< endl;
        cout<<"         1. Iniciar partida        "<< endl;
        cout<<"        2. Ver historial           "<< endl;
        cout<<"         3. salir del juego        "<< endl;
        cout<<"-----------------------------------"<< endl;
        break;

    case 2:
        cout<<"          FIN DE LA PARTIDA         "<< endl;
        cout<<"------------------------------------"<< endl;
        cout<<"          1. Volver a jugar         "<< endl;
        cout<<"           2. Ver historial         "<< endl;
        cout<<"          3. salir del juego        "<< endl;
        cout<<"-------------------------------------"<< endl;

    }
}
bool opcion_invalida(string opcion)
{
    if(opcion=="1")
        return false;
    else if(opcion=="2")
        return false;
    else if(opcion=="3")
        return false;
    else{
        cout<< "ERROR: ingrese una opción valida";
            return true;
    }
}


void guardar_partida(int cant_fichas, string jugadores, string ganador)
{
    string fichas;
    fichas = to_string(cant_fichas);
    fstream file;

    //toma la fecha y hora actual
    time_t tiempo_actual;
    time(&tiempo_actual);

    string informacion = "PARTIDA "+jugadores+"\t"+ctime(&tiempo_actual)+"ganador: "+ganador+"\tcantidad de fichas: "+fichas;

    file.open("historial.txt",ios::out|ios::app);
    if(!file.is_open()){
        cout<<"ERROR: no fue posible abrir el archivo";
    }
    file << informacion << endl;
    file.close();
}

void mostrar_historial()
{
    fstream file;
    string linea;

    file.open("historial.txt",ios::in);

    if(!file.is_open()){
        cout<<"Aún no hay historial para mostrar";
    }

    while(!file.eof()){
        getline(file,linea);
        cout<<linea<<endl;
    }

    file.close();
}
