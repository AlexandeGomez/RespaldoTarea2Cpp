#include <iostream>
#include <cstring>
#include <random>
#include "pila.h"
#include "cola.h"

#define ELIMINAR 0
#define MIN 0
#define MAX 2

void prueba_pilas(Pila*);
void prueba_colas(Cola*);
void analizador_sintaxis(std::string cadena);
void atencion_al_cliente();
int insertar_personas_preba(int veces,int contador,Cola* cola);

int main()
{
    Pila* pila = new Pila;
    prueba_pilas(pila);

    Cola* cola = new Cola;
    prueba_colas(cola);

    analizador_sintaxis("(([{)}]))");
    atencion_al_cliente();
}

void prueba_pilas(Pila* pila){
    //------------------------------------------------------------------------------
    if(pila->insertar("1")==1)
        std::cout<<"Exito agregando la entrada a la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";

    if(pila->insertar("2")==1)
        std::cout<<"Exito agregando la entrada a la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";

    if(pila->insertar("3")==1)
        std::cout<<"Exito agregando la entrada a la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";
    //------------------------------------------------------------------------------
    std::cout<<"la cima es : "<<pila->cima_()<<"\n\n";
    //------------------------------------------------------------------------------
    if(pila->eliminar(ELIMINAR)==1)
        std::cout<<"Se elimino con exito la cima de la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";
    //------------------------------------------------------------------------------
    std::cout<<"la cima es : "<<pila->cima_()<<"\n\n";
    //------------------------------------------------------------------------------
    if(pila->insertar("1")==1)
        std::cout<<"Exito agregando la entrada a la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";
    //------------------------------------------------------------------------------
    if(pila->eliminar(ELIMINAR)==1)
        std::cout<<"Se elimino con exito la cima de la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";

    if(pila->eliminar(ELIMINAR)==1)
        std::cout<<"Se elimino con exito la cima de la pila\n";
    else
        std::cout<<"No se pudo agregar la entrada a la pila\n";
    //------------------------------------------------------------------------------
    std::cout<<"cima: "<<pila->cima_()<<"\n\n";
    //------------------------------------------------------------------------------
    pila->eliminar(ELIMINAR);
    //------------------------------------------------------------------------------
    std::cout<<"cima: "<<pila->cima_()<<"\n\n";
}

void prueba_colas(Cola* cola){
    //------------------------------------------------------------------------------
    if(cola->insertar("1")==1)
        std::cout<<"Exito agregando la entrada a la cola\n";
    else
        std::cout<<"No se pudo agregar la entrada a la cola\n";

    if(cola->insertar("2")==1)
        std::cout<<"Exito agregando la entrada a la cola\n";
    else
        std::cout<<"No se pudo agregar la entrada a la cola\n";

    if(cola->insertar("3")==1)
        std::cout<<"Exito agregando la entrada a la cola\n";
    else
        std::cout<<"No se pudo agregar la entrada a la cola\n";
    if(cola->insertar("4")==1)
        std::cout<<"Exito agregando la entrada a la cola\n";
    else
        std::cout<<"No se pudo agregar la entrada a la cola\n";
    //------------------------------------------------------------------------------
    std::cout<<"cima de cola: "<<cola->cima_()<<"\n\n";
    //------------------------------------------------------------------------------
    cola->eliminar(ELIMINAR);
    cola->eliminar(ELIMINAR);
    //------------------------------------------------------------------------------
    if(cola->insertar("1")==1)
        std::cout<<"Exito agregando la entrada a la cola\n";
    else
        std::cout<<"No se pudo agregar la entrada a la cola\n";
    //------------------------------------------------------------------------------
    std::cout<<"cima de cola: "<<cola->cima_()<<"\n\n";
    //------------------------------------------------------------------------------
    cola->eliminar(ELIMINAR);
    //------------------------------------------------------------------------------
    std::cout<<"cima de cola: "<<cola->cima_()<<"\n\n";
    //------------------------------------------------------------------------------
    cola->eliminar(ELIMINAR);
    //------------------------------------------------------------------------------
    std::cout<<"cima de cola: "<<cola->cima_()<<"\n\n";
}


void analizador_sintaxis(std::string cadena){
    int longitud = cadena.length();
    Pila* pilaa = new Pila;
    for(int i=0; i<longitud; i++){
        std::string s = "";
        s = s+cadena[i];
        if(s=="(" || s=="[" || s=="{"){
            pilaa->insertar(s);
        }
        else{
            std::string caracter = pilaa->cima_();
            const char *cstr = caracter.c_str();
            char chr = ' ';
            if(cstr[0]=='('){
                chr = cstr[0]+1;
            }
            else{
                chr = cstr[0]+2;
            }
            if(cadena[i]==chr){
                pilaa->eliminar(ELIMINAR);
                continue;
            }
            else{
                break;
            }
        }
    }
    if(pilaa->cima_()=="" && longitud!=0){
        std::cout<<"cadena valida\n\n";
    }
    else{
        std::cout<<"cadena NO valida\n\n";
    }
}

void atencion_al_cliente(){
    enum{
      INGRESAR = 1,
      DESPACHAR =2
    };
    int eleccion = 0;
    int contador = 1;
    Cola* colaa = new Cola;
    std::string nombre = "";
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);
    contador = insertar_personas_preba(distr(eng),contador,colaa);
    do{
        std::cout<<"#- Atencion al cliente -#\n";
        std::cout<<"#-----------------------#\n";
        std::cout<<"#      1) Ingresar      #\n";
        std::cout<<"#-----------------------#\n";
        std::cout<<"#      2) Despachar     #\n";
        std::cout<<"#-----------------------#\n";
        std::cout<<"Seleccione una opcion :  \n";
        std::cin>>eleccion;

        switch(eleccion){
            case INGRESAR:
            std::cout<<"Bienvenido a atencion a cliente, por favor, diga su nombre y lo pondremos en la cola de espera: "<<std::endl;
            std::cin>>nombre;
            colaa->insertar(nombre);
            break;
            case DESPACHAR:
            std::cout<<colaa->cima_()<<" favor de pasar a ventanilla"<<std::endl;
            colaa->eliminar(ELIMINAR);
            contador = insertar_personas_preba(distr(eng),contador,colaa);
            break;
        }
    }while(colaa->cima_()!="");
    std::cout<<"No hay personas en la cola de espera"<<std::endl;
}

int insertar_personas_preba(int veces,int contador,Cola* cola){
    for(int i=0; i<veces; i++){
        std::string cadenaContador = std::to_string(contador);
        cadenaContador = "persona :" + cadenaContador;
        cola->insertar(cadenaContador);
        contador++;
    }
    return contador;
}
