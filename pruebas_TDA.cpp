//Ejercicio 2:
/*

Construya una clase Tiempo que contenga los siguientes atributos enteros: horas, minutos y segundos. Haga que la clase contenga dos constructores,
el primero debe tener 3 parametros Tiempo(int, int, int) y el segundo solo tendra un campo que seran los segundos y desamble el numero entero largo 
en horas, minutos y segundos.

*/
#include <iostream>
using namespace std;

class Tiempo{

    private:

        int horas;
        int minutos;
        int segundos;

    public:

        Tiempo(int, int, int);
        Tiempo(long);
        void mostrarHora();
#include <iostream>
using namespace std;
class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int, int, int); //constructor1
        Fecha(long); //constructor 2
        void mostrarFecha();
};
//constructor 1
Fecha::Fecha(int _dia, int _mes, int _anio){
    anio = _anio;
    mes = _mes;
    dia = _dia;
}
//constructor 2
Fecha::Fecha(long fecha){
    anio = int(fecha/10000);//extraer el anio
    mes = int((fecha - anio*10000)/100); //Extraer el mes
    dia = int(fecha - anio*10000 - mes*100); //extraer el dia
}
void Fecha::mostrarFecha(){
    cout << "La fecha es: " << dia << "/" << mes << "/" <<anio <<endl;
}
int main(){
    Fecha hoy(24, 05, 2023);
    hoy.mostrarFecha();
    Fecha ayer(20230523);
    ayer.mostrarFecha();
    return 0;
}
