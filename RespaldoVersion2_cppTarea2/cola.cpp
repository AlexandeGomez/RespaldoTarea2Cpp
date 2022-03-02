#include "cola.h"

Cola::Cola(){
    this->cima = NULL;
}

void Cola::set_cima(Nodo *nuevo){
    this->cima = nuevo;
}

std::string Cola::cima_(){
    if(cima!=NULL){
        return this->cima->get_data();
    }
    return "";
}

int Cola::insertar(std::string dato){
    int salida = Lista::insertar(dato);
    if(salida==1){
        this->set_cima(Lista::get_header());
        return 1;
    }
    return -1;
}

int Cola::eliminar(int posicion){
    posicion = 1;
    int salida = Lista::eliminar(posicion);
    if(salida==1){
        this->set_cima(Lista::get_header());
        return 1;
    }
    return -1;
}

Cola::~Cola(){

}



