#include "Tema08-10.h"

using namespace std;

void ordenar(List<int> &lista);

void ejercicio0810() {
	int casos = 0;
	cin >> casos;

	int dato;
	while (casos > 0) {
		cin >> dato;

		List<int> lista = List<int>();

		while (dato != -1)
		{
			lista.push_back(dato);
			cin >> dato;
		}

		ordenar(lista);
			cout<< endl;

		--casos;
	}
}

void ordenar(List<int> &lista) {
	List<int>::Iterator iterador = lista.begin();
	List<int>::Iterator iteradorEnd = lista.end();

	if (iterador == iteradorEnd) {
		return;
	}

	int dato1 = iterador.elem();
	iterador.next();
	int dato2 = 0;
	cout << dato1;
	while (iterador != iteradorEnd) {
		dato2 = iterador.elem();
		if (dato2 < dato1)
		{
			iterador = lista.erase(iterador);
		}
		else
		{
			cout << " " << dato2;
			dato1 = iterador.elem();
			iterador.next();
		}
	}

}