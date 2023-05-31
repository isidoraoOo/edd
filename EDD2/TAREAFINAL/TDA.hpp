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
        Nodo* raiz; //raiz del arbol
        tElem pos; //posicion / "x" en el problema

        //funciones aux
        void insertarNodo(tElem, Nodo* &); //funcion aux para insert
        Nodo* crearNodo(tElem); //funcion para crear un nodo
        bool busqueda(tElem, Nodo*); //funcion aux para find
        int encontrarNodo(tElem, Nodo*); //funcion aux para lower_bound
        void clearHelp(Nodo*);
    
    public:

        Arbol();
        ~Arbol(); //el destructor tiene que tener la funcion clear de alguna forma
        void clear();
        void insert(tElem pos);
        bool find(tElem pos);
        int lower_bound(tElem pos);
};
