#include "Tema09-01.h"

using namespace std;

void ejercicio0901();

Arbin<char> leerArbol() {
	char raiz;
	cin >> raiz;
	if (raiz == '.') {
		return Arbin<char>();
	}
	else {
		Arbin<char> iz = leerArbol();
		Arbin<char> dr = leerArbol();
		return Arbin<char>(iz, raiz, dr);
	}
}

void ejercicio0901() {
	int n = 0;
	cin >> n;
	while (n > 0) {
		Arbin<char> arbol = leerArbol();

		int numeroNodos = arbol.ContarNodos();
		int numeroHojas = arbol.ContarHojas();
		int numeroAltura = arbol.CalcularAltura();

		cout << numeroNodos << " " << numeroHojas << " " << numeroAltura << endl;
		--n;
	}
}
