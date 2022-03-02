#ifndef NODO_H
#define NODO_H

// Se llaman las librerias necesarias
#include <iostream>

// Se crea la clase nodo
class Nodo
{
// Tendra sus atributos en privado, los cuales son un dato de tipo string y un apuntador a una instacia de clase de Nodo
private:
    std::string data;
    Nodo *address;
// Se colocan los metodos asi como el constructor y destructor en publico
public:
    Nodo();

// Se declaran los 4 metodos principales para los nodos, correspondientes a guardar o mostrar sus datos o direciones de memoria.
    void set_data(std::string);
    void set_address(Nodo*);
    std::string get_data();
    Nodo *get_address();
// Declaración del destructor
    virtual ~Nodo();
};

#endif // NODO_H
