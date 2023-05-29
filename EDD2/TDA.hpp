//tda

typedef int tElem;

struct Nodo{

    tElem numero;
    Nodo* izquierdo;
    Nodo* derecho;

};

class Arbol{

    private:

        //datos Constructor
        Nodo* raiz;
        int cant_postes; //contador para "PARAR_PROGRAMA", cada que se implemente insert(), se aumente en uno el contador.
        tElem pos; //posicion / "x" en el problema

        //funciones aux
        void insertarNodo(tElem, Nodo* &, Nodo*); //funcion aux para insert
        Nodo* crearNodo(); //funcion para crear un nodo
        bool busqueda(tElem, Nodo*); //funcion aux para find
        void encontrarNodo(); //funcion aux para lower_bound
        void borrarNodo(Nodo* ); //funcion eliminarNodo
        void eliminar(Nodo* ); //funcion destruir
    
    public:

        Arbol();
        ~Arbol(); //el destructor tiene que tener la funcion clear de alguna forma
        void clear();
        void insert(tElem pos);
        bool find(tElem pos);
        int lower_bound(tElem pos);
};
