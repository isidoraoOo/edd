//TDA PROBLEMA 2
#include <iostream>
using namespace std;

typedef int tElem; //elemento del nodo

struct Nodo{
    tElem numero; //ingresa el nodo
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo* padre;
};
Nodo* arbol = nullptr;

class Arbol{

    private:

        int cant_postes;  //no se si colocarle unsigned a estos dos
        tElem pos;
        //antes los tenia con unsigned pero decidi no usarlo

    public:

        Arbol(int, tElem); //constructor
        ~Arbol(); //destructor, libera la memoria
        Nodo* crearNodo(tElem, Nodo*); //crea un nuevo nodo
        void insert(tElem, Nodo* &, Nodo*); //inserta el elemento n en el arbol
        bool find(tElem, Nodo*); //encontrar el elemento n en el arbol
        int lower_bound(int);//busca el primer valor que sea menor o igual a x

};

//inicializacion
//constructor
Arbol::Arbol(int _cant_postes, tElem _pos){ //constructor

    this->cant_postes = _cant_postes;
    this->pos = _pos;
}
//destructor
Arbol::~Arbol(){
}
//funcion para crear un nuevo nodo
Nodo* Arbol::crearNodo(tElem pos, Nodo* padre){

    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->numero = pos;
    nodoNuevo->izquierdo = nullptr;
    nodoNuevo->derecho = nullptr;
    nodoNuevo->padre = padre;

    return nodoNuevo;
}
//funcion para insertar el elemento con la posicion "pos" en el arbol
void Arbol::insert(tElem pos, Nodo* &arbol, Nodo* padre){
    if(arbol == nullptr){

        Nodo* nodoNuevo = crearNodo(pos, padre);
        arbol = nodoNuevo;

    }
    else{

        int raiz = arbol->numero;
        if (pos < raiz){

            insert(pos, arbol->izquierdo, arbol);

        }
        else{

            insert(pos, arbol->derecho, arbol);

        }
    }
}
//funcion para encontrar el nodo en la posicion "pos"
bool Arbol::find(int pos, Nodo* arbol){

    if(arbol == nullptr){

        return false;

    }
    else{

        if(arbol->numero == pos){

            return true;
        }
        else{

            if(arbol->numero > pos){

                return find(pos, arbol->izquierdo);
            }
            else{

                return find(pos, arbol->derecho);
            }
        }
    }
}

int Arbol::lower_bound(tElem pos, Nodo* arbol){
    if(arbol == nullptr){

        return pos + 1;  
    }
    if(arbol->numero == pos){

        return 0;

    }
    if(arbol->dato > n){

        lower_bound(arbol->izq, pos);

    }
//int PreOrden(Nodo* arbol, tElem n){
//	if (arbol==nullptr){
//		return -1;
//	}
//	if (arbol->info == n){
//		return -1;
//	}
//	if (arbol->info > n){
//		PreOrden(arbol->izq, n);
//	}
//	return arbol->info;

//todavia no he realizado esta funcion


    return 0;
}

int main(){


    return 0;
}