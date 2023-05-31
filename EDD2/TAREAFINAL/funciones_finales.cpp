//funciones finales

#include "TDA.hpp"
using namespace std;

Nodo* arbol = NULL;
//constructor y destructor

//constructor
Arbol::Arbol(){

    raiz = NULL;
    pos = 0;

}

//destructor
Arbol::~Arbol(){

}


//*********************************
//funciones auxiliares
Nodo* Arbol::crearNodo(tElem pos){

    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->numero = pos;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;

    return nuevoNodo;


}
//funcion auxiliar de insert
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
//funcion auxiliar de find
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

//funcion auxiliar de lower_bound
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
//funciones

//funcion insert
void Arbol::insert(tElem pos){

    insertarNodo(pos, arbol);

}
//funcion find
bool Arbol::find(tElem pos){

    return busqueda(pos, arbol);

}

//funcion lower_bound

int Arbol::lower_bound(tElem pos){

    return encontrarNodo(pos, arbol);

}
