#include "jugador.h"

jugador::jugador()
{

}

jugador::jugador(std::string nombre)
{
    this->nombre = nombre;
}

void jugador::set_nombre(std::string nombre)
{
    this->nombre = nombre;
}

std::string jugador::get_nombre()
{
    return nombre;
}

void jugador::set_puntos(short puntos)
{
    this->puntos = puntos;
}

short jugador::get_puntos()
{
    return puntos;
}
