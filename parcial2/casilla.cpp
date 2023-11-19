#include "casilla.h"

casilla::casilla()
{
    estado = ' ';
}

void casilla::set_estado(char estado)
{
    this->estado = estado;
}

char casilla::get_estado()
{
    return estado;
}
