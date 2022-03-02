#include "pila.h"

Pila::Pila()
{
    this->cima = NULL;
}

void Pila::set_cima(Nodo *nuevo){
    this->cima = nuevo;
}

std::string Pila::cima_(){
    if(cima!=NULL){
        return this->cima->get_data();
    }
    return "";
}

int Pila::insertar(std::string dato){
    int salida = Lista::insertar(dato);
    if(salida==1){
        this->set_cima(Lista::get_ultimo());
        return 1;
    }
    return -1;
}

int Pila::eliminar(int posicion){
    posicion = Lista::tamanio();
    int salida = Lista::eliminar(posicion);
    if(salida==1){
        this->set_cima(Lista::get_ultimo());
        return 1;
    }
    return -1;
}



Pila::~Pila(){

}
