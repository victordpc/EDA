#include "Tema08-11.h"

using namespace std;

void mostrarLista(List<int>* l);

void ejercicio0811() {
	char c = 0; int n;
	int casos = 0, resultado =0;
	int acumulado = 0;
	cin >> casos;
	while (casos > 0) {
		List<int> lista = List<int>();
		//	c = cin.peek(); // Nos dice el siguiente caracter pero sin consumirlo
		
		while (c != '\n') {
			cin >> n; // como sabemos que no viene el salto de línea leemos el siguiente entero
			if (n == acumulado)
			{
				lista.push_back(n);
				++resultado;
			}
			lista.push_back(n);

			acumulado += n;
			c = cin.peek();
		}
		cout << resultado << ": ";

		mostrarLista(&lista);
		resultado = 0;
		c = 0;
		acumulado = 0;
		--casos;
	}
}

void mostrarLista(List<int>* l) {
	List<int>::ConstIterator it = l->cbegin();
	if (it != l->cend()) {
		cout << it.elem();
		it.next();
	}
	while (it != l->cend()) {
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}