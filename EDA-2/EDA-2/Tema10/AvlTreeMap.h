/**
 *  @file AvlTreeMap.h
 * 
 *  Implementación dinámica del TAD Dictionary utilizando
 *  árboles de búsqueda.
 * 
 *  Estructura de Datos y Algoritmos
 *  Facultad de Informática
 *  Universidad Complutense de Madrid
 * 
 * (c) Marco Antonio Gómez Martín, 2012
 */
#ifndef __AVLTREEMAP_H
#define __AVLTREEMAP_H

#include "Exceptions.h"

#include "Stack.h" // Usado internamente por los iteradores

#define BALANCEA_AL_INSERTAR 1
#define BALANCEA_AL_BORRAR 1

using namespace std;
/**
 * Implementación dinámica del TAD Dictionary utilizando 
 * árboles de búsqueda auto-balanceados.
 * 
 * Las operaciones son:
 * 
 * - insert(clave, valor): generadora que añade una 
 * nueva pareja (clave, valor) al árbol. Si la
 * clave ya estaba se sustituye el valor.
 * 
 * - erase(clave): operación modificadora. Elimina la
 * clave del árbol de búsqueda.  Si la clave no está,
 * la operación no tiene efecto.
 * 
 * - at(clave): operación observadora que devuelve
 * el valor asociado a una clave. Es un error preguntar
 * por una clave que no existe.
 * 
 * - contains(clave): operación observadora. Sirve para
 * averiguar si se ha introducido una clave en el
 * árbol.
 * 
 * - empty(): operacion observadora que indica si
 * el árbol de búsqueda tiene alguna clave introducida.
 * 
 * @author Marco Antonio Gómez Martín
 * @author Manuel Freire Morán
 */
template <class Clave, class Valor>
class AvlTreeMap {
private:
	/**
	 * Clase nodo que almacena internamente la pareja (clave, valor)
	 * y los punteros al hijo izquierdo y al hijo derecho.
	 */
	class Nodo {
	public:
		Nodo() : _iz(NULL), _dr(NULL), _prof(0) {}
		Nodo(const Clave &clave, const Valor &valor) 
		: _clave(clave), _valor(valor), _iz(NULL), _dr(NULL), _prof(0) {}
		Nodo(Nodo *iz, const Clave &clave, const Valor &valor, Nodo *dr)
		: _clave(clave), _valor(valor), _iz(iz), _dr(dr), _prof(0) {}
		
		Clave _clave;
		Valor _valor;
		Nodo *_iz;
		Nodo *_dr;
		unsigned int _prof; // profundidad (para rebalanceados)
	};
	
public:
	
	/** Constructor */
	AvlTreeMap() : _ra(NULL) {
	}
	
	/** Destructor; elimina la estructura jerárquica de nodos. */
	~AvlTreeMap() {
		libera();
		_ra = NULL;
	}
	
	/**
	 * Operación generadora que añade una nueva clave/valor
	 * a un árbol de búsqueda.
	 * @param clave Clave nueva.
	 * @param valor Valor asociado a esa clave. Si la clave
	 * ya se había insertado previamente, sustituimos el valor
	 * viejo por el nuevo.
	 */
	void insert(const Clave &clave, const Valor &valor) {
		_ra = insertaAux(clave, valor, _ra);
	}
	
	/**
	 * Operación modificadora que elimina una clave del árbol.
	 * Si la clave no existía la operación no tiene efecto.
	 * 
	 *   erase(elem, EmptyAvlTreeMap) = AvlTreeMapVacio
	 *   erase(e, insert(c, v, arbol)) = 
	 *     inserta(c, v, erase(e, arbol)) si c != e
	 *   erase(e, insert(c, v, arbol)) = erase(e, arbol) si c == e
	 * 
	 * @param clave Clave a eliminar.
	 */
	void erase(const Clave &clave) {
		_ra = borraAux(_ra, clave);
	}
	
	/**
	 * Operación observadora que devuelve el valor asociado
	 * a una clave dada.
	 * 
	 * at(e, insert(c, v, arbol)) = v si e == c
	 * at(e, insert(c, v, arbol)) = at(e, arbol) si e != c
	 * error at(EmptyAvlTreeMap)
	 * 
	 * @param clave Clave por la que se pregunta.
	 */
	const Valor &at(const Clave &clave) const {
		Nodo *p = buscaAux(_ra, clave);
		if (p == NULL)
			throw EClaveErronea();
		
		return p->_valor;
	}
	
	/**
	 * Operación observadora que permite averiguar si una clave
	 * determinada está o no en el árbol de búsqueda.
	 * 
	 * contains(e, EmptyAvlTreeMap) = false
	 * contains(e, insert(c, v, arbol)) = true si e == c
	 * contains(e, insert(c, v, arbol)) = contains(e, arbol) si e != c
	 * 
	 * @param clave Clave por la que se pregunta.
	 * @return true si el diccionario contiene un valor asociado
	 * a esa clave.
	 */
	bool contains(const Clave &clave) const {
		return (buscaAux(_ra, clave) != NULL) ? true : false;
	}
	
	/**
	 * Operación observadora que devuelve si el árbol
	 * es vacío (no contiene elementos) o no.
	 * 
	 * empty(EmptyAvlTreeMap) = true
	 * empty(insert(c, v, arbol)) = false
	 */
	bool empty() const {
		return _ra == NULL;
	}
	
	/**
	 * Sobrecarga del operador [] que permite acceder
	 * al valor asociado a una clave y modificarlo.
	 * Si el elemento buscado no estaba, se inserta uno
	 * con el valor por defecto del tipo Valor.
	 */
	Valor &operator[](const Clave &clave) {
		// Buscamos. Sería mejor hacerlo in-line; así en
		// caso de no encontrarlo no hace falta buscar otra
		// vez dónde insertar la clave.
		Nodo * ret = buscaAux(_ra, clave);
		if (ret == NULL) {
			// No está, lo añadimos y vemos dónde
			// quedó. Hay formas más eficientes para evitar
			// recorridos por el árbol.
			insert(clave, Valor());
			ret = buscaAux(_ra, clave);
		}
		
		return ret->_valor;
	}
	
	// //
	// ITERADOR CONSTANTE Y FUNCIONES RELACIONADAS
	// //
	
	/**
	 * Clase interna que implementa un iterador sobre
	 * la lista que permite recorrer el árbol pero no
	 * permite modificarlo.
	 */
	class ConstIterator {
	public:
		void next() {
			if (_act == NULL) throw InvalidAccessException();
			
			// Si hay hijo derecho, saltamos al primero
			// en inorden del hijo derecho
			if (_act->_dr!=NULL)
				_act = primeroInOrden(_act->_dr);
			else {
				// Si no, vamos al primer ascendiente
				// no visitado. Para eso consultamos
				// la pila; si ya está vacía, no quedan
				// ascendientes por visitar
				if (_ascendientes.empty())
					_act = NULL;
				else {
					_act = _ascendientes.top();
					_ascendientes.pop();
				}
			}
		}
		
		const Clave &key() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_clave;
		}
		
		const Valor &value() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_valor;
		}
		
		bool operator==(const ConstIterator &other) const {
			return _act == other._act;
		}
		
		bool operator!=(const ConstIterator &other) const {
			return !(this->operator==(other));
		}
		
		ConstIterator &operator++() {
			next();
			return *this;
		}
		
		ConstIterator operator++(int) {
			ConstIterator ret(*this);
			operator++();
			return ret;
		}
		
	protected:
		// Para que pueda construir objetos del
		// tipo iterador
		friend class AvlTreeMap;
		
		ConstIterator() : _act(NULL) {}
		ConstIterator(Nodo *act) {
			_act = primeroInOrden(act);
		}
		
		/**
		 *     Busca el primer elemento en inorden de
		 *     la estructura jerárquica de nodos pasada
		 *     como parámetro; va apilando sus ascendientes
		 *     para poder "ir hacia atrás" cuando sea necesario.
		 *     @param p Puntero a la raíz de la subestructura.
		 */
		Nodo *primeroInOrden(Nodo *p) {
			if (p == NULL)
				return NULL;
			
			while (p->_iz != NULL) {
				_ascendientes.push(p);
				p = p->_iz;
			}
			return p;
		}
		
		// Puntero al nodo actual del recorrido
		// NULL si hemos llegado al final.
		Nodo *_act;
		
		// Ascendientes del nodo actual
		// aún por visitar
		Stack<Nodo*> _ascendientes;
	};
	
	/**
	 * Devuelve el iterador constante al principio del
	 * diccionario (clave más pequeña).
	 * @return iterador al principio del recorrido;
	 * coincidirá con cend() si el diccionario está vacío.
	 */
	ConstIterator cbegin() const {
		return ConstIterator(_ra);
	}
	
	/**
	 * @return Devuelve un iterador al final del recorrido
	 * (fuera de éste).
	 */
	ConstIterator cend() const {
		return ConstIterator(NULL);
	}
	
	ConstIterator find(const Clave &c) const {
		Stack<Nodo*> ascendientes;
		Nodo *p = _ra;
		while ((p != NULL) && (p->_clave != c)) {
			if (p->_clave > c) {
				ascendientes.push(p);
				p = p->_iz;
			} else
				p = p->_dr;
		}
		ConstIterator ret;
		ret._act = p;
		if (p != NULL)
			ret._ascendientes = ascendientes;
		return ret;
	}
	
	// //
	// ITERADOR NO CONSTANTE Y FUNCIONES RELACIONADAS
	// //
	
	/**
	 * Clase interna que implementa un iterador sobre
	 * la árbol de búsqueda que permite recorrer la lista e incluso
	 * alterar el valor de sus elementos.
	 */
	class Iterator {
	public:
		void next() {
			if (_act == NULL) throw InvalidAccessException();
			
			// Si hay hijo derecho, saltamos al primero
			// en inorden del hijo derecho
			if (_act->_dr!=NULL)
				_act = primeroInOrden(_act->_dr);
			else {
				// Si no, vamos al primer ascendiente
				// no visitado. Para eso consultamos
				// la pila; si ya está vacía, no quedan
				// ascendientes por visitar
				if (_ascendientes.empty())
					_act = NULL;
				else {
					_act = _ascendientes.top();
					_ascendientes.pop();
				}
			}
		}
		
		const Clave &key() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_clave;
		}
		
		Valor &value() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_valor;
		}
		
		bool operator==(const Iterator &other) const {
			return _act == other._act;
		}
		
		bool operator!=(const Iterator &other) const {
			return !(this->operator==(other));
		}
		
		Iterator &operator++() {
			next();
			return *this;
		}
		
		Iterator operator++(int) {
			Iterator ret(*this);
			operator++();
			return ret;
		}
		
	protected:
		// Para que pueda construir objetos del
		// tipo iterador
		friend class AvlTreeMap;
		
		Iterator() : _act(NULL) {}
		Iterator(Nodo *act) {
			_act = primeroInOrden(act);
		}
		
		/**
		 * 	 Busca el primer elemento en inorden de
		 * 	 la estructura jerárquica de nodos pasada
		 * 	 como parámetro; va apilando sus ascendientes
		 * 	 para poder "ir hacia atrás" cuando sea necesario.
		 * 	 @param p Puntero a la raíz de la subestructura.
		 */
		Nodo *primeroInOrden(Nodo *p) {
			if (p == NULL)
				return NULL;
			
			while (p->_iz != NULL) {
				_ascendientes.push(p);
				p = p->_iz;
			}
			return p;
		}
		
		// Puntero al nodo actual del recorrido
		// NULL si hemos llegado al final.
		Nodo *_act;
		
		// Ascendientes del nodo actual
		// aún por visitar
		Stack<Nodo*> _ascendientes;
	};
	
	/**
	 * Devuelve el iterador al principio de la lista.
	 * @return iterador al principio de la lista;
	 * coincidirá con final() si la lista está vacía.
	 */
	Iterator begin() {
		return Iterator(_ra);
	}
	
	/**
	 * @return Devuelve un iterador al final del recorrido
	 * (fuera de éste).
	 */
	Iterator end() const {
		return Iterator(NULL);
	}
	
	Iterator find(const Clave &c) {
		Stack<Nodo*> ascendientes;
		Nodo *p = _ra;
		while ((p != NULL) && (p->_clave != c)) {
			if (p->_clave > c) {
				ascendientes.push(p);
				p = p->_iz;
			} else
				p = p->_dr;
		}
		Iterator ret;
		ret._act = p;
		if (p != NULL)
			ret._ascendientes = ascendientes;
		return ret;
	}
	
	
	// //
	// MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
	// A LA CLASE
	// //
	
	/** Constructor copia */
	AvlTreeMap(const AvlTreeMap<Clave, Valor> &other) : _ra(NULL) {
		copia(other);
	}
	
	/** Operador de asignación */
	AvlTreeMap<Clave, Valor> &operator=(const AvlTreeMap<Clave, Valor> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}
	
	/**
	 * pretty-print the tree contents. Format is similar to
	 * <pre> 
	 * *- 1 (root: preceeded by '*')
	 *    +- 1.1 (first child of 2: preceeded by '+')
	 *    |  ~- 1.1.1 (single left child: '~')
	 *    `- 1.2 (second child of 2: '`')
	 *   `- 1.2.2 (single right child: '`')
	 * </pre>
	 * empty nodes are not represented.
	 */	
	void print(std::ostream &out=std::cout) const {
		std::string bars;
		if (_ra) {
			out << "*- " << _ra->_clave << ": " 
			<< _ra->_valor << " " << _ra->_prof << std::endl;
			bars.push_back(' ');
			bool full = _ra->_iz && _ra->_dr;
			_print(_ra->_iz, bars, full ? '+' : '~', out);
			_print(_ra->_dr, bars, '`', out);   
			bars.erase(bars.size()-1); // c11: pop_back
		}
	}   
	
	/**
	 * pretty-print for output with DOT (part of GraphViz)
	 * 
	 * 
	 */
	void printToDot(std::ostream &out=std::cout) const {
		out << "digraph g{\n";
		out << "\tnode [shape = record,height=.1];\n";
		// asigna un ID a cada nodo
		AvlTreeMap<Clave,int> ki;
		AvlTreeMap<Clave,Valor>::ConstIterator it = cbegin();
		int counter = 0;
		for (/**/; it!=cend(); it++) {
			ki[it.key()] = counter ++;
		}
		// genera descripciones para cada nodo
		_printNodeToDot(out, _ra, ki);
		out << "}\n";
	}
	
protected:
	
	/**
	 * Constructor protegido que crea un árbol
	 * a partir de una estructura jerárquica de nodos
	 * previamente creada.
	 * Se utiliza en hijoIz e hijoDr.
	 */
	AvlTreeMap(Nodo *raiz) : _ra(raiz) {
	}
	
	void libera() {
		libera(_ra);
	}
	
	void copia(const AvlTreeMap &other) {
		_ra = copiaAux(other._ra);
	}
	
private:
	
	/**
	 * Elimina todos los nodos de una estructura arbórea
	 * que comienza con el puntero ra.
	 * Se admite que el nodo sea NULL (no habrá nada que
	 * liberar).
	 */
	static void libera(Nodo *ra) {
		if (ra != NULL) {
			libera(ra->_iz);
			libera(ra->_dr);
			delete ra;
		}
	}
	
	/**
	 * Copia la estructura jerárquica de nodos pasada
	 * como parámetro (puntero a su raiz) y devuelve un
	 * puntero a una nueva estructura jerárquica, copia
	 * de anterior (y que, por tanto, habrá que liberar).
	 */
	static Nodo *copiaAux(Nodo *ra) {
		if (ra == NULL)
			return NULL;
		
		return new Nodo(copiaAux(ra->_iz),
						ra->_clave, ra->_valor,
				  copiaAux(ra->_dr));
	}
	
	/**
	 * Inserta una pareja (clave, valor) en la estructura
	 * jerárquica que comienza en el puntero pasado como parámetro.
	 * Ese puntero se admite que sea NULL, por lo que se creará
	 * un nuevo nodo que pasará a ser la nueva raíz de esa
	 * estructura jerárquica. El método devuelve un puntero a la
	 * raíz de la estructura modificada. En condiciones normales
	 * coincidirá con el parámetro recibido; sólo cambiará si
	 * la estructura era vacía.
	 * @param clave Clave a insertar. Si ya aparecía en la
	 * estructura de nodos, se sobreescribe el valor.
	 * @param valor Valor a insertar.
	 * @param p Puntero al nodo raíz donde insertar la pareja.
	 * @return Nueva raíz (o p si no cambia).
	 */
	static Nodo *insertaAux(const Clave &clave, const Valor &valor, Nodo *p) {
		
		if (p == NULL) {
			p = new Nodo(clave, valor);
			p->_prof = 1;
		} else if (p->_clave == clave) {
			p->_valor = valor;
		} else if (clave < p->_clave) {
			p->_iz = insertaAux(clave, valor, p->_iz);
			if (BALANCEA_AL_INSERTAR) p = rebalancea(p);
		} else { // (clave > p->_clave)
			p->_dr = insertaAux(clave, valor, p->_dr);
			if (BALANCEA_AL_INSERTAR) p = rebalancea(p);
		}
		return p;
	}
	
	/**
	 * Rebalancea el subarbol que comienza en p (si fuere necesario). 
	 * Asume que los hijos de p (si existen) saben su profundidad, pero *no* asume que p
	 * la tenga ya calculada. 
	 * Existen 4 casos posibles; ver http://en.wikipedia.org/wiki/File:AVL_Tree_Rebalancing.svg
	 * para descripcion. 
	 * @param p Puntero al nodo raíz del subarbol a balancear
	 * @return Puntero al subarbol balanceado; posiblemente distinto de p. Tanto p como 
	 * sus subarboles estarán balanceados y tendran profundidades correctas a la salida.
	 */
	static Nodo *rebalancea(Nodo *p) {
		switch (calculaBalance(p)) {
			case 2: {
				// izq pesa mas que derecho; hay que rotar a la derecha
				if (calculaBalance(p->_iz) < 0) {
					// reduce a izq-izq
					p->_iz = rotateLeft(p->_iz);
				}
				p = rotateRight(p);
				break;
			}
			case -2: {
				// der pesa mas que izquierdo; hay que rotar a la izquierda
				if (calculaBalance(p->_dr) > 0) {
					// reduce a der-der
					p->_dr = rotateRight(p->_dr);
				}
				p = rotateLeft(p);
				break;
			}
		}
		// actualiza profundidad de p
		p->_prof = calculaProf(p);
		return p;
	}
	
	static int calculaProf(Nodo *p) {
		int pizq = (p->_iz) ? p->_iz->_prof : 0;
		int pder = (p->_dr) ? p->_dr->_prof : 0;
		return (pizq > pder ? pizq : pder) + 1;
	}
	
	static int calculaBalance(Nodo *p) {
		int pizq = (p->_iz) ? p->_iz->_prof : 0;
		int pder = (p->_dr) ? p->_dr->_prof : 0;
		return pizq - pder;
	}
	
	/**
	 * http://en.wikipedia.org/wiki/Tree_rotation
	 *     P\    /Q
	 *    a  Q -->  P  c
	 *  b c    a b
	 */
	static Nodo *rotateLeft(Nodo *p) {
		Nodo *q = p->_dr;
		p->_dr = q->_iz; // recoloca 'b'
		q->_iz = p;
		p->_prof --;
		q->_prof ++;
		return q;
	}
	
	/**
	 * http://en.wikipedia.org/wiki/Tree_rotation
	 *     P\    /Q
	 *    a  Q <--  P  c
	 *  b c    a b
	 */
	static Nodo *rotateRight(Nodo *q) {
		Nodo *p = q->_iz;
		q->_iz = p->_dr; // recoloca 'b'
		p->_dr = q;
		q->_prof --;    
		p->_prof ++;
		return p;
	}
	
	/**
	 * Busca una clave en la estructura jerárquica de
	 * nodos cuya raíz se pasa como parámetro, y devuelve
	 * el nodo en la que se encuentra (o NULL si no está).
	 * @param p Puntero a la raíz de la estructura de nodos
	 * @param clave Clave a buscar
	 */
	static Nodo *buscaAux(Nodo *p, const Clave &clave) {
		if (p == NULL)
			return NULL;
		
		if (p->_clave == clave)
			return p;
		
		if (clave < p->_clave)
			return buscaAux(p->_iz, clave);
		else
			return buscaAux(p->_dr, clave);
	}
	
	/**
	 * Elimina (si existe) la clave/valor de la estructura jerárquica
	 * de nodos apuntada por p. Si la clave aparecía en la propia raíz,
	 * ésta cambiará, por lo que se devuelve la nueva raíz. Si no cambia
	 * se devuelve p.
	 * 
	 * @param p Raíz de la estructura jerárquica donde borrar la clave.
	 * @param clave Clave a borrar.
	 * @return Nueva raíz de la estructura, tras el borrado. Si la raíz
	 * no cambia, se devuelve el propio p.
	 */
	static Nodo *borraAux(Nodo *p, const Clave &clave) {
		
		if (p == NULL) {
			// nada
		} else if (clave == p->_clave) {
			p = borraRaiz(p);
		} else if (clave < p->_clave) {
			p->_iz = borraAux(p->_iz, clave);
		} else { // clave > p->_clave
			p->_dr = borraAux(p->_dr, clave);
		}
		
		if (p != NULL && BALANCEA_AL_BORRAR) p = rebalancea(p);
		return p;
	}
	
	/**
	 * Borra la raíz de la estructura jerárquica de nodos
	 * y devuelve el puntero a la nueva raíz que garantiza
	 * que la estructura sigue siendo válida para un árbol de
	 * búsqueda (claves ordenadas).
	 */
	static Nodo *borraRaiz(Nodo *p) {
		
		Nodo *aux;
		
		if (p->_iz == NULL) {
			// Si no hay hijo izquierdo, la raíz pasa a ser
			// el hijo derecho
			aux = p->_dr;
			delete p;
		} else if (p->_dr == NULL) {
			// Si no hay hijo derecho, la raíz pasa a ser
			// el hijo izquierdo		
			aux = p->_iz;
			delete p;
		} else {
			// Convertimos el elemento más pequeño del hijo derecho
			// en la raíz.
			aux = mueveMinYBorra(p);
			if (BALANCEA_AL_BORRAR) aux = rebalancea(aux);
		}		
		return aux;
	}
	
	/**
	 * Método auxiliar para el borrado; recibe un puntero a la
	 * raíz a borrar. Busca el elemento más pequeño del hijo derecho
	 * que se convertirá en la raíz (que devolverá), borra la antigua
	 * raíz (p) y "cose" todos los punteros, de forma que ahora:
	 * 
	 *   - El mínimo pasa a ser la raíz, cuyo hijo izquierdo y
	 *     derecho eran los hijos izquierdo y derecho de la raíz
	 *     antigua.
	 *   - El hijo izquierdo del padre del elemento más pequeño
	 *     pasa a ser el antiguo hijo derecho de ese mínimo.
	 */
	static Nodo *mueveMinYBorra(Nodo *p) {
		
		// Vamos bajando hasta que encontramos el elemento
		// más pequeño (aquel que no tiene hijo izquierdo).
		// Vamos guardando también el padre (que será null
		// si el hijo derecho es directamente el elemento
		// más pequeño).
		Nodo *aux = p->_dr;
		Stack<Nodo*> padres;
		while (aux->_iz != NULL) {
			padres.push(aux);
			aux = aux->_iz;
		}
		
		// aux apunta al elemento más pequeño.
		// padre apunta a su(s) padre(s) (si el nodo es hijo izquierdo)
		
		// Dos casos dependiendo de si el padre del nodo con 
		// el mínimo es o no la raíz a eliminar
		// (=> padre != NULL)
		if (!padres.empty()) {
			padres.top()->_iz = aux->_dr;
			// re-balancea ruta hasta 'aux'
			while (!padres.empty()) {
				Nodo *n = padres.top();
				padres.pop();
				if (!padres.empty() && BALANCEA_AL_BORRAR) {
					if (padres.top()->_iz == n) {
						padres.top()->_iz = rebalancea(n);
					} else {
						padres.top()->_dr = rebalancea(n);
					}
				}
			}
			aux->_iz = p->_iz;
			aux->_dr = p->_dr;
			aux->_prof = calculaProf(aux);
		} else {
			aux->_iz = p->_iz;
		}
		
		delete p;
		return aux;
	}
	
	void _print(Nodo *n, std::string &bars, char nodeChar, std::ostream &out) const {
		if (n) {
			for (unsigned int i=0; i<bars.size(); i++) {
				out << bars[i] << std::string(3, ' ');
			}
			out << nodeChar << "- " 
			<< n->_clave << ": " << n->_valor << " " << n->_prof << std::endl;
			bars.push_back(nodeChar == '`' || nodeChar == '~' ? ' ' : '|');
			bool full = n->_iz && n->_dr;
			_print(n->_iz, bars, full ? '+' : '~', out);
			_print(n->_dr, bars, '`', out);    
			bars.erase(bars.size()-1); // c11: pop_back
		}
	}
	
	static void _printNodeToDot(std::ostream &out, Nodo *n, AvlTreeMap<Clave,int> &ki){
		out << "\tn" << ki[n->_clave] << "[label = \"<f0> |" 
		<< n->_clave << ": " << n->_valor << "|<f1>\"];\n";
		if (n->_iz) {
			_printNodeToDot(out, n->_iz, ki);
			out << "\t\"n" << ki[n->_clave] << "\":f0 -> \"n" << ki[n->_iz->_clave] << "\"\n";
		}
		if (n->_dr) {
			_printNodeToDot(out, n->_dr, ki);
			out << "\t\"n" << ki[n->_clave] << "\":f1 -> \"n" << ki[n->_dr->_clave] << "\"\n";
		}
	}
	
	/** 
	 * Puntero a la raíz de la estructura jerárquica
	 * de nodos.
	 */
	Nodo *_ra;
};

#endif // __AVLTREEMAP_H
