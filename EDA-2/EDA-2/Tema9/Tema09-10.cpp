#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include "Tema09-10.h"

using namespace std;

template <class T>
Arbin<T> leerMazmorra(const T& repVacio) {
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else {
		Arbin<T> hi = leerMazmorra(repVacio);
		Arbin<T> hd = leerMazmorra(repVacio);
		return Arbin<T>(hi, elem, hd);
	}
}

void solucionaMazmorraRecursiva(Arbin<int> mazmorra, int &minimoDragones, int dragonesAcumulados, int &mejorPuerta) {
	if (mazmorra.esVacio()) {
		return;
	} else if (1 == mazmorra.raiz()) {
		solucionaMazmorraRecursiva(mazmorra.hijoIz(), minimoDragones, dragonesAcumulados + 1, mejorPuerta);
		solucionaMazmorraRecursiva(mazmorra.hijoDr(), minimoDragones, dragonesAcumulados + 1, mejorPuerta);
	} else if (2 == mazmorra.raiz() || 0 == mazmorra.raiz()) {
		solucionaMazmorraRecursiva(mazmorra.hijoIz(), minimoDragones, dragonesAcumulados, mejorPuerta);
		solucionaMazmorraRecursiva(mazmorra.hijoDr(), minimoDragones, dragonesAcumulados, mejorPuerta);
	} else {
		if (dragonesAcumulados < minimoDragones) {
			mejorPuerta = mazmorra.raiz();
			minimoDragones = dragonesAcumulados;
		}
	}
}

void solucionaMazmorra(Arbin<int> mazmorra) {
	int minimoDragrones = mazmorra.ContarNodos();
	int mejorPuerta = 0;

	solucionaMazmorraRecursiva(mazmorra, minimoDragrones, 0, mejorPuerta);
	cout << mejorPuerta << endl;
}

void entraMazmorra() {
	Arbin<int> mazmorra = leerMazmorra(-1);
	solucionaMazmorra(mazmorra);
}

void ejercicio0910() {
	int numMazmorras;
	cin >> numMazmorras;
	for (int i = 0; i < numMazmorras; i++)
		entraMazmorra();
}