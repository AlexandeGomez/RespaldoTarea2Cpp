#include "nodo.h"

// Definiendo al constructor de la clase nodo, para inicializar sus atributos
Nodo::Nodo()
{
    this->data = "";
    this->address = NULL;
}
// Metodo para poder guardar un dato dentro del nodo
void Nodo::set_data(std::string _data){
    this->data = _data;
}
// Metodo para poder guardar una dirección de memoria dentro del nodo
void Nodo::set_address(Nodo *_address){
    this->address = _address;
}
// Metodo para poder solicitar el dato del nodo
std::string Nodo::get_data(){
    return this->data;
}
// Metodo para poder solicitar la dirección de memoria guardada en el nodo (del siguiente nodo al que apunta)
Nodo* Nodo::get_address(){
    return this->address;
}
// Definiendo al destructor
Nodo::~Nodo(){
}
