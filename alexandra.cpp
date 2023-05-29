#include <iostream>
#include <string>
using namespace std;

int main(){

    string completo, nombre, apellido, espacio = " ";
    cout << "Ingrese su nombre y su apellido: "; cin >>completo;
    for(int n = 0; n < completo.length(); n++){

        for(int i = 0; completo[i] != espacio; i++){

            nombre.append(completo[i]);

        }
        
    } 

        

    }

    return 0;
}