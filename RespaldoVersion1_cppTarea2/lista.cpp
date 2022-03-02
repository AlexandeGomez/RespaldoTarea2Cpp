#include "lista.h"

// Se define el constructor, el cual de atributo header se inicializara en nulo
Lista::Lista()
{
    this->header = NULL;
}
// Se define el metodo para guardar la direción de memoria de un valor de tipo nodo en su atributo header
void Lista::set_header(Nodo* _address){
    this->header = _address;
}
// Se define el metodo para obtener la dirección de memoria del primero nodo de existir
Nodo* Lista::get_header(){
    return this->header;
}

// Se define el metodo para poder encontrar le dirección de memoria de un nodo en especifico dependiendo de la posición solicitada
// Si la dirección guardada en el nodo no es nulo quiere decir que hay otro elemento, usando esto podemos recorrer el nodo hasta llegar al ultimo
// El contador nos ayuda a saber cuando hemos llegado a la posición solicitada
Nodo* Lista::search_address(int posicion){
    Nodo *direccion = this->get_header();
    int cont = 1;
    if(direccion!=NULL){
        while(direccion->get_address()!=NULL && cont<posicion){
            direccion = direccion->get_address();
            cont++;
        }
        return direccion;
    }
    return NULL;
}
// Metodo para poder obtener la dirección del ultimo elemento o nodo de la lista, utilizando un mecanismo similar al metodo anterior, al llegar
// al ultimo elemento que tiene guardada una dirección a NULL, se regresa la dirección del nodo.
Nodo* Lista::get_ultimo(){
    Nodo *direccion = this->get_header();
    if(direccion!=NULL){
        while(direccion->get_address()!=NULL){
            direccion = direccion->get_address();
        }
        return direccion;
    }
    return NULL;
}

//METODOS PROPIOS DEL EJERCICIO
// Metodo inserta que nos permite crear un nuevo nodo y agragarlo a la lista, se utliza el metodo get_ultimo para reutilizar codigo, una vez
// accediendo al ultimo nodo podemos agregarle la dirección del nuevo nodo creado y regresamos un 1 como confirmacion.
int Lista::insertar(std::string dato){
        Nodo* ultimo = this->get_ultimo();
        Nodo* nuevo = new Nodo;
        nuevo->set_data(dato);
        if(ultimo!=NULL){
            this->get_ultimo()->set_address(nuevo);
        }
        else{
            this->set_header(nuevo);
        }
        return 1;
}

// Metodo tamanio() que nos permite obtener el tamaño o numero de elementos que tiene la lista, si se trata de una lista vacia nos regresara 0
// recorremos la lista hasta llegar al ultimo nodo, utilizando un contador para guardar el numero de nodos que se recorrieron hasta el final.
// Si la direccion del header de la lista es NULL, entonces la lista es vacia y regresamos un cero.
int Lista::tamanio(){
    int cont = 0;
    Nodo *direccion = this->get_header();
    if(direccion!=NULL){
        while(direccion->get_address()!=NULL){
            direccion = direccion->get_address();
            cont++;
        }
        return cont+1;
    }
    else{
        return cont;
    }
}

// Metodo que nos permite recorrer todos los elementos de la lista imprimiendo en pantalla todas las entradas, utilizamos el tamaño de la lista,
// haciendo uso del metodo anterior para ahorrar lineas de codigo y saber hasta que elementos recorrer.
void Lista::mostrar_todo(){
    Nodo* direccion = this->get_header();
    int tamanio = this->tamanio();
    std::cout<<std::endl;
    for(int i=0; i<tamanio; i++){
        std::cout<<direccion->get_data()<<std::endl;
        direccion = direccion->get_address();
    }
    std::cout<<std::endl;
}
// Metodo que nos permite insertar una nueva entrada en una posición de la lista dentro del rango de 1 al tamaño maximo de la lista, haciendo
// uso del metodo tamanio() para poder insertar el elemento, tenemos 2 situaciones 1) cuando lo insertamos en la posición 1 ya que necesitamos
// guardar la nueva dirección en el header de la lista, y no puede tratarse como si fuera cualquier nodo 2) cualquier posición entre el 1<p<=tamanio
int Lista::insertar_en(int posicion, std::string newData){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        if(posicion==1){
            Nodo* direccion = this->get_header();
            Nodo* newNode = new Nodo;
            newNode->set_data(newData);
            this->set_header(newNode);
            newNode->set_address(direccion);
            return 1;
        }
        else{
            Nodo* nodoPosicion = this->search_address(posicion);
            Nodo* direccion = this->get_header();
            Nodo* anterior = NULL;
            Nodo* newNode = new Nodo;
            while(direccion!=nodoPosicion){
                anterior = direccion;
                direccion = direccion->get_address();
            }
            newNode->set_data(newData);
            anterior->set_address(newNode);
            newNode->set_address(direccion);
            return 1;
        }
    }
    return -1;
}
// Metodo que nos permite obtener una de las canciones al proporcionar un a de las posiciones de la lista, nos apoyamos de los metodos tamanio()
// para poder tratar con listas vacias, y del metodo search_address() que nos permite encontraruna direccion del nodo dependiendo la posición
// para poder acceder al dato y regresarlo.
std::string Lista::tomar(int posicion){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        Nodo* direccion = this->search_address(posicion);
        return direccion->get_data();
    }
    return "";
}
// Metodo que nos permite buscar una canción al recorrer la lista, nos apoyamos del metodo tamanio() para limitar los escenarios, nos regresara
// la posición de la canción a buscar o un -1 si no fue capaz de encontrarlo, tenemos 3 escenarios 1) la lista esta vacia. 2) la canción se encuentra
// en el nodo de la posción 1. 3) se busca en toda la lista si concuerdan los datos regresa la posición utilizando un contrados.
int Lista::buscar(std::string dato){
    int tamanio = this->tamanio();
    if(tamanio!=0){
        Nodo* direccion = this->get_header();
        int cont = 1;

        if(direccion->get_data()==dato){
            return cont;
        }
        while(direccion->get_address()!=NULL){
            direccion = direccion->get_address();
            cont++;
            if(direccion->get_data()==dato){
                return cont;
            }
        }
    }
    return -1;
}

// Metodo que nos permite modificar un dato de uno de los nodos de la lista recibiendo el dato y la posición, nos apoyamos de los metodos
// tamanio() y search_address() para reciclar codigo.
int Lista::modificar(int posicion, std::string dato){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        Nodo* direccion = this->search_address(posicion);
        direccion->set_data(dato);
        return 1;
    }
    return -1;
}
// Metodo que nos permite verificar si nuestra lista es una lsita vacia o no, nos apoyamos del metodo tamanio() para comprobar esta situación.
bool Lista::vacia(){
    int tamanio = this->tamanio();
    if(tamanio!=0)
        return false;
    else
        return true;
}
// Metodo que nos permite regresar el dato en la primera posición, nos apoyamos del metodo tomar().
std::string Lista::tomar_primero(){
    return this->tomar(1);
}
// Metodo que nos permite eliminar un nodo de una posición espeficifa, nos apoyamos del metodo tamanio() para limitar las sitaciones
// Utilizamos dos variables, una que avance por los nodos guardando la direccion de memoria actual hasta encontrar el nodo y otra que guarde
// la direccion anterior, con la intensión de no perder la referecia.
// Podemos encontrar tres escenarios 1) el elemento a eliminar esta en la posición 1. 2) El elemento a eliminar esta entre 1<elem<=tamanio. 3)
// la lista esta vacia o el elemento a eliminar se sale del rango. Regresa 1 si borro el dato, si no regresa un -1.
int Lista::eliminar(int posicion){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        Nodo* nodoBuscado = this->search_address(posicion);
        Nodo* direccion = this->get_header();
        Nodo* anterior = NULL;
        if(posicion==1){
            this->set_header(direccion->get_address());
            delete direccion;
            return 1;
        }
        while(direccion!=nodoBuscado){
            anterior = direccion;
            direccion = direccion->get_address();
        }
        anterior->set_address(direccion->get_address());
        delete direccion;
        return 1;
    }
    return -1;
}
// Metodo que nos permite vaciar la lista, utilizando el metodo tamanio() para asegurar de que sea una lista valida, y del metodo eliminar()
// iteramos desde el ultimo elemento hasta el primer eliminando cada uno de ellos utilizando el destructor de clase.
void Lista::purga(){
    int tamanio = this->tamanio();
    if(tamanio!=0){
        for(int i=tamanio;i!=0;i--){
            this->eliminar(i);
        }
    }
}
// Definimos el desctructor de la clase lista.
Lista::~Lista()
{

}
