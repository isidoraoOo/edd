#include <iostream>
using namespace std;

struct Nodo{
    int numero; //el numero asignado (la posicion)
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo* padre;
};
Nodo* arbol = nullptr;

//funciones
//funcion para crear un nuevo nodo
Nodo* crearNodo(int pos, Nodo* padre){

    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->numero = pos;
    nodoNuevo->izquierdo = nullptr;
    nodoNuevo->derecho = nullptr;
    nodoNuevo->padre = padre;

    return nodoNuevo;
}
//funcion para insertar un nodo en el arbol
void insert(int pos, Nodo* &arbol, Nodo* padre){
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
//Funcion para encontrar el nodo en la posicion "pos"
bool find(int pos, Nodo* arbol){

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
//funcion que busca la posicion mas cercana al poste encendido,
int lower_bound(int pos, Nodo* arbol){
    int cant_postes = 0;

//no se como hacer esta funcion pipipi, tengo la idea pero no la ejecucion jaskdjad

    return cant_postes;
}


int main(){
    //declaración de variables
    int operacion;
    string completo, operacionSTR, posicionSTR;

    do{
        cout << "";
        getline(cin, completo);
        size_t espacio = completo.find(' ');
        if(espacio != string::npos){

            operacionSTR = completo.substr(0, espacio);
            posicionSTR = completo.substr(espacio  + 1);
            int posicion = stoi(posicionSTR);
            if(operacionSTR == "ENCENDER"){

                operacion = 1;

            }
            else if(operacionSTR == "CUANTOS_ENCENDER"){

                operacion = 2;

            }
        }
        else if(completo == "PARAR_PROGRAMA"){

            operacion = 3;

        }
        else{

            cout << "operacion invalida, intentelo nuevamente\n";

        }
        
//aqui irá un switch eventualmente
        switch(operacion){

            //ENCENDER
            case 1:
                    break;
            //CUANTOS_ENCENDER
            case 2:
                    break;
            //PARAR_PROGRAMA
            case 3:
                    break;




        }
    }while(operacion != 3);
    return 0;
}