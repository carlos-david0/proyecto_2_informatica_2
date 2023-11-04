#ifndef CASILLA_H
#define CASILLA_H


class casilla
{
public:
    casilla();
    void set_estado(char estado);
    char get_estado();
private:
    char estado;
};

#endif // CASILLA_H
