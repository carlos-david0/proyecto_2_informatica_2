#include "casilla.h"

casilla::casilla()
{
    estado = ' ';
}

void casilla::set_estado(int turno)
{
    if (turno % 2 == 0){
        estado = '-';
    }else{
        estado = '*';
    }
}

char casilla::get_estado()
{
    return estado;
}
