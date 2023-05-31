//programa principal

#include <iostream>
#include <string>
#include "funciones_finales.cpp"
using namespace std;

int main(){
    Arbol funcion;
    int operacion, cant_postes = 0, valor, resultado, posicion;
    string completo, operacionSTR, posicionSTR;

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
        
//aqui irá un switch eventualmente
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
                cout << valor << endl;

                break;
            //PARAR_PROGRAMA
            case 3:

                cout << cant_postes << endl;

                break;

        }

    }while(operacion != 3);

    return 0;
}