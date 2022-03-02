#ifndef PILA_H
#define PILA_H

#include "lista.h"

class Pila : public Lista
{
private:
    Nodo* cima;

public:
    Pila();
    int insertar(std::string) override;
    int eliminar(int) override;

    void set_cima(Nodo*);
    std::string cima_();

    virtual ~Pila();
};

#endif // PILA_H
