#include <iostream>
#include <string>
using namespace std;

int main() {
    string completo, operacion, posicionSTR;
    cout << "";
    getline(cin, completo);

    // Buscar el primer espacio en blanco para separar el nombre y el apellido
    size_t posicionEspacio = completo.find(' ');
    if (posicionEspacio != string::npos) {
        // Extraer el nombre y el apellido en base a la posición del espacio
        operacion = completo.substr(0, posicionEspacio);
        posicionSTR = completo.substr(posicionEspacio + 1);
        int posicion = stoi(posicionSTR);

        // Imprimir el nombre y el apellido
        cout << "Operacion: " << operacion << endl;
        cout << "Posicion: " << posicion << endl;
    } else {
        cout << "Formato incorrecto. Ingrese el nombre y el apellido separados por un espacio." << endl;
    }

    return 0;
}
