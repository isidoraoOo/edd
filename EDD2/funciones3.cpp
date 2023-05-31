#include <iostream>
#include "TDA.hpp"
#include <string>
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

//**********************************************************
void mostrarArbol(Nodo* arbol, int n)
{
     if(arbol==NULL)
          return;
     mostrarArbol(arbol->derecho, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->numero <<endl;

     mostrarArbol(arbol->izquierdo, n+1);
}

int main(){
    Arbol prueba;
    int opcion, cant_postes = 0, numerito, n = 0, resultado;
    do{
        cout << "(1) Insertar un nodo. " << endl; //insert
        cout << "(2) Encontrar nodo. " << endl; //find
        cout << "(3) funcion lower_bound." << endl; //lower_bound
        cout << "(4) Mostrar arbol. " << endl; 
        cout << "(5) Mostrar cuantos nodos tiene el arbol." << endl; 
        cout << "(6) salir" << endl;

        cin >> opcion;
        switch(opcion){
            case 1:
            
                cout << "numero a insertar: "; cin >> numerito;
                prueba.insert(numerito);
                cant_postes++; //parar_programa

                break;
            case 2:

                cout << "\n numero a buscar: "; cin >>numerito;
                if(prueba.find(numerito) == true){

                    cout << "verdadero" << endl;

                }
                else{

                    cout << "falso" << endl;

                }
                break;

            case 3:
                cout << "encontrar numero mas cercano a la posicion: "; cin >> numerito;
                resultado = prueba.lower_bound(numerito);
                cout << resultado << endl;
                break;

            case 4:

                cout << "ARBOL" << endl;
                cout << endl;
                mostrarArbol(arbol, n);

                break;
            case 5:

                cout << "\n en el arbol hay " << cant_postes << " nodos. " <<endl;
                break;

        }
    }while(opcion != 6);
    return 0;
}