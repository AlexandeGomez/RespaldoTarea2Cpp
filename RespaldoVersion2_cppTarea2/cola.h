#ifndef COLA_H
#define COLA_H

#include "lista.h"

class Cola : public Lista
{
private:
    Nodo* cima;
public:
    Cola();

    void set_cima(Nodo*);
    std::string cima_();

    int insertar(std::string) override;
    int eliminar(int) override;

    virtual ~Cola();
};

#endif // COLA_H
