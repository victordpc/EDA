#ifndef _ARBOL_BIN_H
#define _ARBOL_BIN_H


template <class T>
class ArbolBin
{

private:

	class Nodo {
	public:
		Nodo() : _izq(NULL), _der(NULL) {}
		Nodo(const T &elem) : _elem(elem), _izq(NULL), _der(NULL) {}
		Nodo(Nodo *izq, const T &elem, Nodo *der) :
			_elem(elem), _izq(izq), _der(der) {}

		T _elem;
		Nodo *_izq;
		Nodo *_der;
	};

	Nodo *_ra;

	// Numero de elementos
	unsigned int _numElems;


	void libera(Nodo *n) {
		if (n != nullptr) {
			libera(n->_izq);
			libera(n->_der);
			delete n;
		}
	}

	static bool comparaAux(Nodo *r1, Nodo *r2) {
		if (r1 == r2)
			return true;
		else if ((r1 == nullptr) || (r2 == nullptr))
			return false;
		else {
			return (r1->_elem == r2->elem)
				&& comparaAux(r1->_izq, r2->_izq)
				&& comparaAux(r1->_der, r2->_der);
		}
	}

	void copia(const ArbolBin &other) {
		this->_ra = copiaAux(other->_ra);
	}

	Nodo *copiaAux(Nodo *n) {
		if (n == nullptr)
			return nullptr;
		else
			return new Nodo(copiaAux(n->_izq), n->elem, copiaAux(n->_der));
	}


public:
	ArbolBin()  : _ra(nullptr), _numElems(0){}
	~ArbolBin()
	{
		libera(_ra);
	}
	/* Constructor por copia */
	ArbolBin(const ArbolBin<T> &other) {
		copia(other);
	}
	
	
	
	/* Devolver El hijo izquierdo como arbol, para evitar la comparticion de memoria
	realizamos una copia del arbol*/
	
	/* Devolver El hijo derecho como arbol, para evitar la comparticion de memoria
	realizamos una copia del arbol*/

	/* Devuelve el valor de la raiz */
	T &raiz() {
		return _ra->elem;
	}

	/** Operador de asignaci�n */
	ArbolBin<T> &operator=(const ArbolBin<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const ArbolBin<T> &other) const {
		return comparaAux(this->_ra, other->_ra);
	}

	bool operator!=(const ArbolBin<T> &other) const {
		return !(*this == other);
	}


};

#endif // !_ARBOL_BIN_H
