//funciones finales

#include "TDA.hpp"
#include <iostream>
using namespace std;

Nodo* arbol = NULL;

//constructor
Arbol::Arbol(){

    raiz = NULL;
    pos = 0;

}

//*********************************

//Funciones auxiliares
//A continuación se encuentran las funciones auxiliares, las que 
//posteriormente se utilizarán para las funciones solicitadas

Nodo* Arbol::crearNodo(tElem pos){

    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->numero = pos;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;

    return nuevoNodo;
}

//Funcion auxiliar de insert
//Su proposito es insetar un nodo en el arbol. Si el arbol esta vacio, crea un 
//nuevo nodo y lo asigna raiz. Si no esta vacio, compara el elemento que se desea 
//insertar con la raiz actual con el proposito de determinar en que subarbol debe 
//ser insertado el nuevo elemento.

void Arbol::insertarNodo(tElem pos, Nodo* &arbol){

    if(arbol == NULL){

        arbol = crearNodo(pos);

    }
    else{

        if(pos < arbol->numero){

            insertarNodo(pos, arbol->izquierdo);

        }
        else{

            if(pos > arbol->numero){

                insertarNodo(pos, arbol->derecho);
            }
        }
    }
}

//Funcion auxiliar de find
//Su proposito es buscar un determinado elemento en el arbol. Si el arbol no existe
//retornara 'false', pues no hay elementos en el arbol. Si el arbol existe
//ira comparando el elemento que se esta buscando con la raiz del arbol. La busqueda 
//contunuara con llamadas recursivas en el subarbol derecho o izquierdo, dependiendo 
//de la relacion entre el elemento buscado y la raiz. Si se encuentra el elemento se 
//retornara 'true', de otra manera retornara 'false'.

bool Arbol::busqueda(tElem pos, Nodo* arbol){

    if(arbol == NULL){

        return false;

    }
    else{

        if(arbol->numero == pos){

            return true;
        }
        else{

            if(arbol->numero > pos){

                return busqueda(pos, arbol->izquierdo);
            }
            else{

                return busqueda(pos, arbol->derecho);
            }
        }
    }
}

//Funcion auxiliar de lower_bound
//Su proposito es buscar el primer elemento que sea menor o igual a otro elemento 'pos'.
//Compara la informacion del nodo actual con el elemento 'pos' para determinar por que 
//subarbol se debe continuar la busqueda. La exploracion en los subarboles correspondientes
//se realiza con llamadas recursivas. Finalmente, retornara el numero mas cercano
//que es menor o igual a 'pos' si es que es encontrado, de otra forma retornara -1.

int Arbol::encontrarNodo(tElem pos,Nodo *arbol) {
    if (arbol == NULL) {
        return -1;
    }
    if (arbol->numero > pos) {
        return encontrarNodo(pos, arbol->izquierdo);
    }

    else{
        int num = encontrarNodo(pos, arbol->derecho);
        if (num == -1 || arbol->numero > num) {
        num = arbol->numero;
        }
    return num;
    }
}
//Funcion auxiliar de clear
//Su proposito es eliminar todos los nodos del arbol de manera recursiva

void Arbol::clearHelp(Nodo* arbol) {
    if (arbol == NULL) return;
     
    clearHelp(arbol->izquierdo); 
    clearHelp(arbol->derecho); 
    delete arbol;
}

//Funciones
//Estas funciones son las que se solicitaron en el enunciado. El proposito de crear 
//funciones auxiliares fue facilitar su desarrollo y luego crear estas funciones 
//principales, que llamarian a las auxiliares. De esta manera, las funciones principales 
//solo tendrian el parametro requerido.

//Funcion insert
void Arbol::insert(tElem pos){

    insertarNodo(pos, arbol);

}
//Funcion find
bool Arbol::find(tElem pos){

    return busqueda(pos, arbol);

}

//Funcion lower_bound

int Arbol::lower_bound(tElem pos){

    return encontrarNodo(pos, arbol);

}

//Funcion clear

void Arbol::clear(){

    clearHelp(arbol);

}

//destructor
Arbol::~Arbol(){

    clear();

}

int main(){


    return 0;
}
