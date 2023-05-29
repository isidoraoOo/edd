#include <iostream>
using namespace std;
#include "tda.hpp"
#include <string>

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