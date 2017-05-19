#include <iostream>
#include <list>
#include "TreeMap.h"
#include <string>

using namespace std;

void printLista(const list<int>& l, ostream& sout) {
	list<int>::const_iterator it = l.cbegin();
	if (it != l.cend()) {
		sout << *it;
		++it;
	}
	while (it != l.end()) {
		sout << " " << *it;
		++it;
	}
	sout << endl;
}

void aMinusculas(std::string& palabra) {
	for (char& c : palabra) {
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
	}
}

void resuelveCaso(int numLineas) {
	char c;
	string palabra;
	TreeMap<string, list<int>> datos;




	for (int linea = 1; linea <= numLineas; linea++) {
		cin.get(c);
		while (c != '\n') {
			cin.unget();
			cin >> palabra;

			if (palabra.size() > 2) {
				aMinusculas(palabra);

				TreeMap<string, list<int>>::Iterator itera = datos.find(palabra);

				if (itera != datos.end()) {
					if (itera.value().back() != linea)
						itera.value().push_back(linea);
				}
				else {
					list<int> valores;
					valores.push_front(linea);
					datos.insert(palabra, valores);
				}
			}
			cin.get(c);
		}
	}

	TreeMap<string, list<int>> ::ConstIterator inicio = datos.cbegin();
	TreeMap<string, list<int>> ::ConstIterator fin = datos.cend();

	while (inicio != fin) {
		cout << inicio.key() << " ";
		printLista(inicio.value(), cout);
		inicio.next();
	}
	cout << "----" << endl;
}

void ejercicio1003() {
	int numLineas;
	char c;
	cin >> numLineas; cin.get(c);
	while (numLineas != 0) {
		resuelveCaso(numLineas);
		cin >> numLineas; cin.get(c);
	}
}