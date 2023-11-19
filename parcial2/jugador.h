#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

class jugador
{
public:
    jugador();
    jugador(std::string nombre);
    void set_nombre(std::string nombre);
    std::string get_nombre();
    void set_puntos(short int puntos);
    short int get_puntos();
private:
    std::string nombre;
    short int puntos;
};
#endif // JUGADOR_H
