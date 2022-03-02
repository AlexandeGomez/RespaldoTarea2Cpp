#include <iostream>
#include <cstring>
#include <random>
//#include <string.h>
#include "pila.h"
#include "cola.h"

using std::string;

#define ELIMINAR 0
#define MIN 0
#define MAX 2

void analizador_sintaxis(std::string cadena);
void atencion_al_cliente();
int insertar_personas_preba(int veces,int contador,Cola* cola);

int main()
{
//    Pila* pila = new Pila;
//    pila->insertar("1");
//    pila->insertar("2");
//    pila->insertar("3");
//    std::cout<<"cima: "<<pila->cima_()<<"\n\n";
//    //pila->mostrar_todo();

//    pila->eliminar(ELIMINAR);
//    pila->eliminar(ELIMINAR);
//    std::cout<<"cima: "<<pila->cima_()<<"\n\n";
//    pila->eliminar(ELIMINAR);
//    std::cout<<"cima: "<<pila->cima_()<<"\n\n";
//    //pila->mostrar_todo();

//    std::cout<<"\n\n";
//    Cola* cola = new Cola;
//    cola->insertar("1");
//    cola->insertar("2");
//    cola->insertar("3");
//    cola->insertar("4");
//    cola->mostrar_todo();
//    std::cout<<"cima de cola: "<<cola->cima_()<<"\n"; //1

//    cola->eliminar(ELIMINAR); //2, 3, 4
//    cola->eliminar(ELIMINAR); //3 , 4
//    std::cout<<"cima de cola: "<<cola->cima_()<<"\n"; //3
//    cola->eliminar(ELIMINAR); //4
//    std::cout<<"cima de cola: "<<cola->cima_()<<"\n"; //4
//    cola->eliminar(ELIMINAR);
//    std::cout<<"cima de cola: "<<cola->cima_()<<"\n"; //""

    analizador_sintaxis("(([{}]))");
    atencion_al_cliente();
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
                std::cout<<"valida\n";
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
    pilaa->mostrar_todo();
}

void atencion_al_cliente(){
    int contador = 1;
    Cola* colaa = new Cola;
    std::string nombre = "";
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);
    std::cout << distr(eng) << "; ";
    contador = insertar_personas_preba(distr(eng),contador,colaa);
    std::cout<<"Bienvenido a atencion a cliente, por favor, diga su nombre y lo pondremos en la cola de espera: "<<std::endl;
    std::cin>>nombre;
    colaa->insertar(nombre);
    colaa->mostrar_todo();
    do{
        std::cout<<colaa->cima_()<<" favor de pasar a ventanilla"<<std::endl;
        colaa->eliminar(ELIMINAR);
        contador = insertar_personas_preba(distr(eng),contador,colaa);
    }while(colaa->cima_()!="");
    std::cout<<"No hay personas en la cola de espera"<<std::endl;
    colaa->mostrar_todo();
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
