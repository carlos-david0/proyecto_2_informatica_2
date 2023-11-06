#include "herramientas.h"

void imprimir_menu(short menu)
{
    switch(menu){
    case 1:
        std::cout<<"       BIENVENIDO A OTHELLO        "<< std::endl;
        std::cout<<"----------MENU PRINCIPAL-----------"<< std::endl;
        std::cout<<"         1. Iniciar partida        "<< std::endl;
        std::cout<<"         2. Ver historial           "<< std::endl;
        std::cout<<"         3. salir del juego        "<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        break;

    case 2:
        std::cout<<"          FIN DE LA PARTIDA         "<< std::endl;
        std::cout<<"------------------------------------"<< std::endl;
        std::cout<<"          1. Volver a jugar         "<< std::endl;
        std::cout<<"          2. Ver historial         "<< std::endl;
        std::cout<<"          3. salir del juego        "<< std::endl;
        std::cout<<"-------------------------------------"<< std::endl;

    }
}
bool opcion_invalida(short opcion)
{
    switch(opcion){
    case 1: return false; break;
    case 2: return false; break;
    case 3: return false; break;
    default: std::cout<< "ERROR: ingrese una opcion valida"; return true; break;
    }
}


void guardar_partida(std::string cant_fichas, std::string jugadores, std::string ganador)
{
    std::fstream file;

    //toma la fecha y hora actual
    time_t tiempo_actual;
    time(&tiempo_actual);

    std::string informacion = "PARTIDA "+jugadores+"\t"+ctime(&tiempo_actual)+"ganador: "+ganador+"\tcantidad de fichas: "+ cant_fichas;

    file.open("historial.txt",std::ios::out|std::ios::app);
    if(!file.is_open()){
        std::cout<<"ERROR: no fue posible abrir el archivo";
    }
    file << informacion << std::endl; //verificar formato de escritura
    file.close();
}
void mostrar_historial()
{
    std::fstream file;
    std::string linea;

    file.open("historial.txt",std::ios::in);

    if(!file.is_open()){
        std::cout<<"Aun no hay historial para mostrar";
    }

    while(!file.eof()){
        getline(file,linea);
        std::cout<<linea<<std::endl;
    }

    file.close();
}
