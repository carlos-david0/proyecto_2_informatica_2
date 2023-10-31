#ifndef CASILLA_H
#define CASILLA_H


class casilla
{
public:
    casilla();
    void initialice_casilla();
    void set_estado(int turno);
    char get_estado();
private:
    char estado;
};

#endif // CASILLA_H
