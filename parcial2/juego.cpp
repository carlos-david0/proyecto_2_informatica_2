#include "juego.h"

juego::juego(int filas, int columnas){
    tablero = new class tablero(filas, columnas);
    j1 = new jugador;
    j2 = new jugador;
    turno = 0;
    game_over = false;
}

juego::~juego()
{
    delete tablero;
    delete j1;
    delete j2;
}

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


void juego::guardar_partida(std::string cant_fichas, std::string jugadores, std::string ganador)
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


void juego::partida()
{
    while (!game_over || tablero->movimientos_disponibles(turno) != ""){
        if (tablero->movimientos_disponibles(turno) == ""){
            std::cout << "el jugador no tiene movimientos disponibles" << std::endl;
            turno++;
            game_over = true;
        }else{
            game_over = false;
            std::cout << "Turno: " << turno + 1 << ", jugador: ";
            if (turno%2 == 0){
                std::cout << "-" << std::endl;
            }else{
                std::cout << "*" << std::endl;
            }
            std::cout << tablero->print_tablero();
            std::cout << "movimientos disponibles: " << std::endl;
            std::cout << tablero->movimientos_disponibles(turno) << std::endl;
            std::cout << "";
            std::string paso;
            std::getline(std::cin, paso);
            while (tablero->movimiento_valido(paso, turno) == ""){
                std::cout << "digite su movimiento (Columna en mayuscula y fila):";
                std::getline (std::cin,paso);
            }
            tablero->tomar_turno(turno, paso);
            turno++;
            paso = "";
        }
    }
    std::cout << tablero->print_tablero();
    j1->set_puntos( tablero->contador_j1());
    j2->set_puntos( tablero->contador_j2());
    if (tablero->ganador(j1->get_puntos(), j2->get_puntos()) != 0){
        std::cout << "El ganador es el jugador: " << tablero->ganador(j1->get_puntos(),j2->get_puntos())<< " " << j1->get_puntos() << " a " << j2->get_puntos() << std::endl;
    }else{
        std::cout << "empate a: " << j1->get_puntos() << std::endl;
    }
    //al finalizar la partida guardar la información de la partida
    std::string namej1 = "";
    std::string namej2 = "";
    std::cout << "inserte el nombre del jugador 1: ";
    std::cin >> namej1;
    j1->set_nombre(namej1);
    std::cout << "inserte el nombre del jugador 2: ";
    std::cin >> namej2;
    j2->set_nombre(namej2);
    if (tablero->ganador(j1->get_puntos(),j2->get_puntos()) == 1){
        guardar_partida(std::to_string(j1->get_puntos())+ ", " + std::to_string(j2->get_puntos()), j1->get_nombre() + " vs " + j2->get_nombre(), j1->get_nombre());
    }else if (tablero->ganador(j1->get_puntos(),j2->get_puntos()) == 2){
        guardar_partida(std::to_string(j1->get_puntos())+ ", " + std::to_string(j2->get_puntos()), j1->get_nombre()+ " vs "+ j2->get_nombre(), j2->get_nombre());
    }else{
        guardar_partida(std::to_string(j1->get_puntos())+ ", " + std::to_string(j2->get_puntos()), j1->get_nombre()+" vs "+j2->get_nombre(), "empate");
    }
}



