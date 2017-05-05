#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include "Tema09-08.h"

Arbin<int>  rellenarArbol(List<int> &preO, List<int> &inO);
void pintarArbol(Arbin<int> &a);

void pintarArbol(Arbin<int> &a) {
	List<int> *pintar;
	pintar = a.niveles();
	cout << pintar->front();
	pintar->pop_front();
	while (!pintar->empty()) {
		cout << " " << pintar->front();
		pintar->pop_front();
	}
	cout << endl;
}

Arbin<int> rellenarArbol(List<int> &preO, List<int> &inO) {
	if (preO.size() == 1 && inO.size() == 1)
		return Arbin<int>(preO.front());
	else if (preO.size() == 0 && inO.size() == 0)
		return Arbin<int>();
	int raiz = preO.front();
	preO.pop_front();

	List<int> izquierdoPre = List<int>();
	List<int> derechoPre = List<int>();

	List<int> izquierdoIn = List<int>();
	List<int> derechoIn = List<int>();

	while (inO.front() != raiz) {
		izquierdoIn.push_back(inO.front());
		inO.pop_front();

		izquierdoPre.push_back(preO.front());
		preO.pop_front();
	}
	inO.pop_front();
	while (!inO.empty()) {
		derechoIn.push_back(inO.front());
		inO.pop_front();

		derechoPre.push_back(preO.front());
		preO.pop_front();
	}

	return Arbin<int>(rellenarArbol(izquierdoPre, izquierdoIn), raiz, rellenarArbol(derechoPre, derechoIn));
}

void ejercicio0908() {

	Arbin<int> a1;
	List<int> l1;
	List<int> l2;
	int valor = 0;

	do {
		a1 = Arbin<int>();
		l1 = List<int>();
		l2 = List<int>();

		cin >> valor;
		while (valor != -1) {
			l1.push_back(valor);
			cin >> valor;
		}
		cin >> valor;
		while (valor != -1) {
			l2.push_back(valor);
			cin >> valor;
		}

		a1 = rellenarArbol(l1, l2);

		if (!a1.esVacio()) {
			pintarArbol(a1);
		}
		//a1.~Arbin();
		//l1.~List();
		//l2.~List();

	} while (!a1.esVacio());
}