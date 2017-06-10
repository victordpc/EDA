#ifndef _LIBRERIA_H
#define _LIBRERIA_H

#include "List.h"
#include "TreeMap.h"
#include "HashMap.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

typedef string Libro;

typedef struct {
	int unidades;
	int nVendidos;
	List<Libro>::Iterator it;
}LibroAlm;

class Libreria {

public:
	Libreria();
	~Libreria();

	void nuevoLibro(int n, Libro x);
	void comprar(Libro x);
	bool estaLibro(Libro x);
	void elimLibro(Libro x);
	int numEjemplares(Libro x);
	List<Libro> top10();

private:
	HashMap<Libro, LibroAlm> libreria;
	map<int, List<Libro>> vendidos;
};

Libreria::Libreria() { }

Libreria::~Libreria() { }

//• nuevoLibro(n, x) : A˜nade n ejemplares de un libro x al sistema.Si n toma el valor cero significa
//que el libro est´a en el sistema, aunque no se tienen ejemplares disponibles.Si el libro ya est´a en el
//sistema se a˜naden los ejemplares.
void Libreria::nuevoLibro(int n, Libro x) {
	LibroAlm nuevo;
	nuevo.unidades = n;
	nuevo.nVendidos = 0;
	nuevo.it = NULL;
	libreria.insert(x, nuevo);
}

//• comprar(x) : Un usuario compra un libro x.Si no existen ejemplares disponibles del libro x se
//produce un error de tipo out of range con el mensaje No hay ejemplares.Si el libro no est´a
//dado de alta en el sistema se produce un error de tipo invalid argument con el mensaje Libro
//no existente.
void Libreria::comprar(Libro x) throw() {
	HashMap<Libro, LibroAlm>::Iterator it = libreria.find(x);

	if (it != libreria.end()) {
		if (it.value().unidades != 0) {
			it.value().unidades = it.value().unidades - 1;


			if (it.value().nVendidos++ != 0) {
				vendidos[it.value().nVendidos].erase(it.value().it);
			}
			vendidos[it.value().nVendidos].push_front(x);
			it.value().it = vendidos[it.value().nVendidos].begin();
		}
		else { throw ExcepcionTAD("No hay ejemplares"); }
	}
	else { throw ExcepcionTAD("Libro no existente"); }
}

//• estaLibro(x) : Indica si un libro x se ha a˜nadido al sistema.El resultado ser´a cierto si el libro
//est´a en el sistema, aunque no haya ejemplares disponibles, y ser´a falso si no est´a en el sistema.
bool Libreria::estaLibro(Libro x) {
	return libreria.find(x) != libreria.end();
}

//• elimLibro(x) : Elimina el libro x del sistema.
//Si el libro no existe la operaci´on no tiene efecto.
void Libreria::elimLibro(Libro x) {
	HashMap<Libro, LibroAlm>::Iterator it = libreria.find(x);

	if (it != libreria.end()) {
		if (it.value().nVendidos > 0) {
			vendidos[it.value().nVendidos].erase(it.value().it);
		}
		libreria.erase(x);
	}
}

//• numEjemplares(x) : Devuelve el n´umero de ejemplares de un libro x que hay disponibles en el
//sistema.Si el libro no est´a dado de alta se produce un error de tipo invalid argument con el
//mensaje Libro no existente.
int Libreria::numEjemplares(Libro x) throw() {
	HashMap<Libro, LibroAlm>::Iterator it = libreria.find(x);

	if (it != libreria.end()) { return it.value().unidades; }
	else { throw ExcepcionTAD("Libro no existente"); }
}

//• top10() : Obtiene una lista con los 10 libros que m´as se han vendido.La lista estar´a ordenada por
//n´umero de ventas primero los m´as vendidos y los libros que se hayan vendido el mismo n´umero de
//veces se ordenan del que tenga la venta m´as moderna a la m´as antigua, as´ı hasta completar la lista
//de 10 libros.Si no se han vendido 10 libros distintos se listar´an todos ellos.
List<string> Libreria::top10() {
	List<Libro>resultado;
	//int contador = 0;
	////map<int, List<Libro>>::const_reverse_iterator vendidos=0;
	//for (auto itV = vendidos.rbegin(); itV != vendidos.rend() && contador < 10; itV++) {
	//	for (auto itL = itV->second().cbegin(); itL != itV->second().cend() && contador < 10; itL++) {
	//		resultado.push_back(itL.elem());
	//		contador++;

	//	}
	//}

	////vector<string> top10() {
	////	vector<string> sol;
	////	int contador = 0;
	////	for (auto i = top.rbegin(); contador < 10 && i != top.rend(); ++i) {
	////		for (auto j = i->second.begin(); contador < 10 && j != i->second.end(); ++j) {
	////			sol.push_back(*j);
	////			contador++;
	////		}
	////	}
	////	return sol;
	////}

	return resultado;
}


#endif // !_LIBRERIA_H
