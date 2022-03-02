#ifndef LISTA_H
#define LISTA_H
// Se llama al archivo .h del nodo para poder utilizar sus objetos de clase
#include "nodo.h"

// Se crea la clase lista
class Lista
{
// Se configura su atributo el cual es su la dirección al primero nodo de la lisata
private:
    Nodo *header;
// Se colocan los métodos asi como el constructor y destructo en publico.
public:
// Declarando al constructor de clase
    Lista();

//// Metodos necesarios para interactuar con la cabezara o direccion al primer nodo
//    void set_header(Nodo*);
//    Nodo* get_header();

//// Metodos extra utilizados de apoyo para recliclar codigo y ser reutilizado
//    Nodo* search_address(int);
//    Nodo* get_ultimo();

// Metodos propios del ejercicio solicitado
    // Metodos que no regresan un tipo de dato
//    void mostrar_todo();
//    void purga();
//    // Metodo que regresa un valor booleano
//    bool vacia();
//    // Metodos que regresan un numero entero
//    int modificar(int, std::string);
//    int insertar_en(int, std::string);
    virtual int insertar(std::string);
//    int buscar(std::string);
    virtual int eliminar(int);
//    int tamanio();
//    // Metodos que regresan un objeto de la clase std (string)
//    std::string tomar_primero();
//    std::string tomar(int);
    // Declaración del destructor
    virtual ~Lista();
//protected:
    int tamanio();
    // Metodos que regresan un objeto de la clase std (string)
    std::string tomar_primero();
    std::string tomar(int);
    int buscar(std::string);
    void mostrar_todo();
    void purga();
    // Metodo que regresa un valor booleano
    bool vacia();
    // Metodos que regresan un numero entero
    int modificar(int, std::string);
    int insertar_en(int, std::string);
// Metodos necesarios para interactuar con la cabezara o direccion al primer nodo
    void set_header(Nodo*);
    Nodo* get_header();

// Metodos extra utilizados de apoyo para recliclar codigo y ser reutilizado
    Nodo* search_address(int);
    Nodo* get_ultimo();
};

#endif // LISTA_H
