#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include "Tema09-04.h"

using namespace std;

template <class T>
Arbin<T> leerArbol(const T& repVacio) {
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else {
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi, elem, hd);
	}
}

//void planificarRescate(Arbin<int> rutas, int &grupos, int &max) {
//	if (rutas.esVacio() )
//		max = 0;
//	else if (!rutas.esVacio()) {
//		int numIz = 0, numDer = 0;
//		int gruposAux = grupos;
//		planificarRescate(rutas.hijoDr(), grupos, numIz);
//		planificarRescate(rutas.hijoIz(), grupos, numDer);
//		if (grupos == gruposAux && rutas.raiz()!=0)
//			grupos++;
//		if (numDer > numIz)
//			max = numDer + rutas.raiz();
//		else
//			max = numIz + rutas.raiz();
//	}
//}

void planificarRescate(Arbin<int> rutas, int &grupos, int &max) {
	if (rutas.esVacio()) {
		max = 0;
		grupos = 0;
	}
	else {// if (!rutas.esVacio()) {
		int numIz = 0, numDer = 0;
		int gruposIz = 0, gruposDr = 0;

		planificarRescate(rutas.hijoDr(), gruposIz, numIz);
		planificarRescate(rutas.hijoIz(), gruposDr, numDer);

		grupos = gruposDr + gruposIz;
		if (rutas.raiz() != 0 && grupos == 0)
			grupos = 1;

		if (numDer > numIz)
			max = numDer + rutas.raiz();
		else
			max = numIz + rutas.raiz();
	}
}


void resuelveCaso() {
	Arbin<int> rutas;
	int grupos = 0, max = 0;
	rutas = leerArbol(-1); // -1 es la repr. de arbol vacio
	planificarRescate(rutas, grupos, max);
	cout << grupos << " " << max << endl;
}

void ejercicio0904() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}