//arboles

#include <iostream>
using namespace std;


//funcion de menu

//estructura del nodo
struct Nodo{

    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};
Nodo* arbol = NULL;
//funcion para crear un nuevo nodo
Nodo* crearNodo(int n, Nodo* padre){

    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;
    nuevo_nodo->padre = padre;
    
    return nuevo_nodo;
}
//funcion para encontrar el nodo mas izquierdo posible
Nodo* minimo(Nodo* arbol){

    if(arbol == NULL){//si el arbol esta vacio

        return NULL;//retornas nulo

    }
    if(arbol->izq){//si tiene hijo izquierdo

        return minimo(arbol->izq);//buscamos la parte mas izquierda posible

    }
    else{ //si no tiene hijo izquierdo

        return arbol; //retornamos el mismo

    }
}
//funcion para insertar un nuevo nodo en el arbol

void insertarNodo(Nodo* &arbol, int n, Nodo* padre){

    if(arbol == NULL){ //si el arbol está vacio

        Nodo* nuevo_nodo = crearNodo(n, padre);
        arbol = nuevo_nodo;
    }
    else{ //si el arbol tiene un nodo o más

        int valorRaiz = arbol->dato;
        if(n < valorRaiz){ //si el arbol es menor a raiz, insertar lado izq

            insertarNodo(arbol->izq, n, arbol);

        }
        else{

            insertarNodo(arbol->der, n, arbol);
        }
    }
}
//funcion para reemplazar dos nodos(intercambiarlos)
void reemplazar(Nodo* arbol, Nodo*nuevoNodo){

    if(arbol->dato == arbol->padre->izq->dato){

        arbol->padre->izq = nuevoNodo;

    }
    else if(arbol->dato == arbol->padre->der->dato){

        arbol->padre->der = nuevoNodo;
    }
    if(nuevoNodo){

        nuevoNodo->padre = arbol->padre;
    }
}
//funcion para destruir un nodo
void destruir(Nodo* nodo){

    nodo->izq = NULL;
    nodo->der = NULL;
    
    delete nodo;
}


//funcion para eliminar un nodo
void eliminarNodo(Nodo* nodoEliminar){

    if(nodoEliminar->izq && nodoEliminar->der){ //si el nodo tiene hijo izquierdo y ademas hijo derecho
        Nodo* menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){ //si tiene hijo izquierdo

        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruir(nodoEliminar);

    }
    else if(nodoEliminar, nodoEliminar->der){ //si tiene hijo derecho

        reemplazar(nodoEliminar, nodoEliminar->der);
        destruir(nodoEliminar);

    }
    else{//si el nodo no tiene hijos, es decir, un nodo hoja

        reemplazar(nodoEliminar, NULL);
        destruir(nodoEliminar);

    }
}
//funcion para encontrar y eliminar un nodo en el arbol
void eliminar(Nodo* arbol, int n){

    if(arbol == NULL){//si el arbol esta vacio

        return; //no haces nada

    }
    else if(n < arbol->dato){ //si el valor es menor

        eliminar(arbol->izq, n);//busca por la izquierda

    }
    else if(n > arbol->dato){ //si el arbol es mayor

        eliminar(arbol ->der, n);//busca por la derecha

    }
    else{

        eliminarNodo(arbol);

    }

}


//funcion para mostrar el arbol completo
void mostrarArbol(Nodo* arbol, int cont){

    if(arbol == NULL){ //si el arbol esta vacio
        return;
    }
    else{
        mostrarArbol(arbol->der, cont+1); //arbol por la derecha
        for(int i = 0; i < cont; i++){

            cout << "   ";

        }
        cout << arbol->dato << endl; //arbol por la izquierda
        mostrarArbol(arbol->izq,cont+1);
    }
}
//funcion para buscar un nodo/elemento en el arbol
bool busqueda(Nodo* arbol, int n){

    if(arbol == NULL){ //si el arbol esta vacio

        return false;

    }
    else if(arbol->dato == n){ //si el nodo es igual al elemento

        return true;

    }
    else if(n < arbol->dato){

        return busqueda(arbol->izq, n);

    }
    else{

        return busqueda(arbol->der, n);
    }
}
//funcion para recorrer en profundidad por el metodo 'preorden'
void preOrden(Nodo* arbol){
    if(arbol == NULL){

        return;

    }
    else{

        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
//funcion para recorrer en profundidad por el metodo 'inorden'
void inOrden(Nodo* arbol){

    if(arbol == NULL){

        return;

    }
    else{

        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);

    }
}
//funcion para recorrer en produndidad por el metrodo 'postorden'
void postOrden(Nodo* arbol){

    if(arbol == NULL){

        return;

    } 
    else{

        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}


//funcion menú
void menu(){

    int dato, opcion, contador = 0;
    do{

        cout << "(1) Insertar un nuevo nodo." << endl;
        cout << "(2) Mostrar el arbol completo." << endl;
        cout << "(3) Buscar un elemento en el arbol" << endl;
        cout << "(4) Recorrer el arbol en preorden" << endl;
        cout << "(5) Recorrer el arbol en inorden" << endl;
        cout << "(6) Recorrer el arbol en postorden" << endl;
        cout << "(7) Eliminar un nodo del arbol" << endl;
        cout << "(8) Salir." << endl;
        cout << "Opción: "; cin >> opcion;

        switch(opcion){

            case 1: cout << "Digite un numero: "; cin >> dato;
                    insertarNodo(arbol, dato, NULL);
                    cout << "\n";
                    break;
            case 2: cout <<"\nMostrando el arbol completo\n\n";
                    mostrarArbol(arbol,contador);
                    cout << "\n";
                    break;
            case 3: cout << "\nDigite el elemento a buscar: "; cin>>dato;
                    if(busqueda(arbol, dato) == true){

                        cout << "\nElemento " << dato << " ha sido encontrado en el arbol\n";

                    }
                    else{

                        cout << "\nElemento no encontrado\n";

                    }
                    break;
            case 4: cout << "\nRecorrido en PreOrden: ";
                    preOrden(arbol);
                    cout << "\n\n";
                    break;
            case 5: cout << "\nRecorrido en InOrden: ";
                    inOrden(arbol);
                    cout << "\n\n";
                    break;
            case 6: cout << "\nRecorrido en PostOrden: ";
                    postOrden(arbol);
                    cout<< "\n\n";
                    break;
            case 7: cout << "\nDigite el numero a eliminar: "; cin >> dato;
                    eliminar(arbol, dato);
                    cout << "\n";
                    break;
        }
    }while(opcion != 8);
}

//funcion principal
int main(){

    menu();


    return 0;
}