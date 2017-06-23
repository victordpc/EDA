#include <iostream>
#include <algorithm>
#include <climits>
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

void solucionaMazmorraRaizHojasRecursiva(Arbin<int> mazmorra, int &minimoDragones, int dragonesAcumulados, int &mejorPuerta) {
	if (mazmorra.esVacio()|| dragonesAcumulados>minimoDragones) {
		return;
	} else if (1 == mazmorra.raiz()) {
		solucionaMazmorraRaizHojasRecursiva(mazmorra.hijoIz(), minimoDragones, dragonesAcumulados + 1, mejorPuerta);
		solucionaMazmorraRaizHojasRecursiva(mazmorra.hijoDr(), minimoDragones, dragonesAcumulados + 1, mejorPuerta);
	} else if (2 == mazmorra.raiz() || 0 == mazmorra.raiz()) {
		solucionaMazmorraRaizHojasRecursiva(mazmorra.hijoIz(), minimoDragones, dragonesAcumulados, mejorPuerta);
		solucionaMazmorraRaizHojasRecursiva(mazmorra.hijoDr(), minimoDragones, dragonesAcumulados, mejorPuerta);
	} else {
		if (dragonesAcumulados < minimoDragones) {
			mejorPuerta = mazmorra.raiz();
			minimoDragones = dragonesAcumulados;
		}
	}
}

void solucionaMazmorraRaizHojas(Arbin<int> mazmorra) {
	int minimoDragrones = mazmorra.ContarNodos();
	int mejorPuerta = 0;

	solucionaMazmorraRaizHojasRecursiva(mazmorra, minimoDragrones, 0, mejorPuerta);
	cout << mejorPuerta << endl;
}

void solucionaMazmorraHojasRaizRecursiva(Arbin<int> mazmorra, int &minimoDragones, int &mejorPuerta) {
	if (mazmorra.esVacio()) {
		minimoDragones = INT_MAX;
	}
	else if (0 <= mazmorra.raiz() && mazmorra.raiz() <= 2) {
		int dragonesIz = 0;
		int dragonesDr = 0;
		int puertaIz = 0;
		int puertaDr = 0;

		solucionaMazmorraHojasRaizRecursiva(mazmorra.hijoIz(), dragonesIz, puertaIz);
		solucionaMazmorraHojasRaizRecursiva(mazmorra.hijoDr(), dragonesDr, puertaDr);

		minimoDragones = (dragonesIz > dragonesDr) ? dragonesDr : dragonesIz;
		minimoDragones = (mazmorra.raiz() == 1) ? minimoDragones + 1 : minimoDragones;

		mejorPuerta = (dragonesIz > dragonesDr) ? puertaDr : puertaIz;
	}
	else {
		mejorPuerta = mazmorra.raiz();
		minimoDragones = 0;
	}
}



void solucionaMazmorraHojasRaiz(Arbin<int> mazmorra) {
	int minimoDragrones = 0;
	int mejorPuerta = 0;

	solucionaMazmorraHojasRaizRecursiva(mazmorra, minimoDragrones,mejorPuerta);
	cout << mejorPuerta << endl;
}


void entraMazmorra(bool raiz_a_hojas) {
	Arbin<int> mazmorra = leerMazmorra(-1);
	if (raiz_a_hojas)
		solucionaMazmorraRaizHojas(mazmorra);
	else
		solucionaMazmorraHojasRaiz(mazmorra);
}

void ejercicio0910() {
	int numMazmorras;
	cin >> numMazmorras;
	for (int i = 0; i < numMazmorras; i++)
		entraMazmorra(false);
}