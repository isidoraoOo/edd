//programa principal

#include <iostream>
#include <string>
#include "funciones_finales.cpp"
using namespace std;

struct Cola{

    int dato;
    Cola* siguiente;

};

bool colaVacia(Cola* frente){

    if(frente == NULL){

        return true;

    }
    else{

        return false;

    }
}

//insertar elemento a la Cola
void insertarCola(Cola* &frente, Cola* &fin, int elemento){

    Cola* nuevaCola = new Cola();
    nuevaCola->dato = elemento;
    nuevaCola->siguiente = NULL;

    if(colaVacia(frente)){

        frente = nuevaCola;

    }
    else{

        fin->siguiente = nuevaCola;

    }
    fin = nuevaCola;
}
void mostrarCola(Cola* frente){

    Cola* temporal = frente;
    while(temporal != NULL){

        cout << temporal->dato << endl;
        temporal = temporal->siguiente;
    }
}

int main(){

    Cola* frente = NULL;
    Cola* fin = NULL;


    Arbol funcion;
    int operacion, cant_postes = 0, valor, resultado, posicion;
    string completo, operacionSTR, posicionSTR;


    //entrada
    do{
        cout << "";
        getline(cin, completo);
        size_t espacio = completo.find(' ');
        if(espacio != string::npos){

            operacionSTR = completo.substr(0, espacio);
            posicionSTR = completo.substr(espacio  + 1);
            posicion = stoi(posicionSTR);
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
        
        switch(operacion){

            //ENCENDER
            case 1:
            //primero tiene que tener un find para verificar que no este dentro del arbol el elemento
            if(funcion.find(posicion) == true){

                
            }
            else{

                funcion.insert(posicion);
                cant_postes++;

            }
                
                break;
            //CUANTOS_ENCENDER
            case 2:
                resultado = funcion.lower_bound(posicion);
                if(resultado == -1){

                    valor = posicion + 1;

                }
                else{

                    valor = posicion - resultado;

                }
                insertarCola(frente, fin, valor);

                break;
        }

    }while(operacion != 3); //PARAR_PROGRAMA

    //salida
    cout << endl;
    mostrarCola(frente);
    cout << cant_postes << endl;

    return 0;
}