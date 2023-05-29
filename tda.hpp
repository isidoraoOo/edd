typedef int tElem; 

class Arbol{
	private:
		struct Nodo{
			tElem numero;
			Nodo* izq;
			Nodo* der;
			Nodo* padre;
		};
		Nodo* raiz;
		
	public:
		Arbol(){
			raiz = nullptr;
		};	
		//destructor o.O no se como se hace
    ~Arbol();
	
		Nodo* crearNodo(tElem pos, Nodo* padre);
		void insert(tElem pos, Nodo* &arbol, Nodo* padre);
		bool find(tElem pos, Nodo* arbol);
		int lower_bound(tElem pos, Nodo* arbol);
};
//inicializacion funciones
Arbol::Arbol()

