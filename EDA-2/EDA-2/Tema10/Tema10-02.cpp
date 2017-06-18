#include <iostream>
#include <list>
#include <string>
#include "HashMap.h"

using namespace std;

typedef int Numero;

typedef struct{
	Numero numero;
	int posicion;
}NumeroLista;

typedef struct {
	NumeroLista valor;
	list<NumeroLista>::iterator iterador;
}NumeroDic;

void resuelveSerie() {
	int numCap = 0;
	int max = 0;
	int aux = 0;
	int introducido = 0;
	unsigned int orden = 0;

	list<NumeroLista> entrada;
	HashMap<Numero, NumeroDic> series;
	list<NumeroLista>::iterator cuenta= entrada.end();

	cin >> numCap;
	while (numCap-- > 0) {
		cin >> introducido;
		
		NumeroLista nuevo; nuevo.numero=introducido; nuevo.posicion=orden;
		entrada.push_front(nuevo);

		if (cuenta == entrada.end()) cuenta == entrada.begin();

		HashMap<Numero, NumeroDic>::Iterator busqueda = series.find(nuevo.numero);
		NumeroDic nuevoDic;
		if (busqueda == series.end()) {
			aux++;
			nuevoDic.valor = nuevo;
			nuevoDic.iterador = entrada.begin();
		}
		else {
			if (aux > max) max = aux;
			nuevoDic.valor = nuevo;
			nuevoDic.iterador = entrada.begin(); 

			aux = orden - busqueda.value().valor.posicion ;

			cuenta=busqueda.value().iterador;
			cuenta++;
		}


		series.insert(nuevo.numero, nuevoDic);
		orden++;
	}
	if (aux > max) max = aux;
	cout << max << endl;
}

void ejercicio1002() {
	int casos = 0;
	cin >> casos;

	while (casos-- != 0) {
		resuelveSerie();
	}
}
