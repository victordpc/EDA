#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include <exception>
#include <string>
using namespace std;

typedef struct {
	int stock;
	int num_ventas;
	list<string>::iterator it;
}cantidad;
class venta_libros {
private:
	//string libro;
	unordered_map<string, cantidad> registro;
	map<int, list<string>> top;

public:
	void nuevoLibro(int n, string x) {
		if (registro.count(x) != 0) {
			registro[x].stock += n;
		}
		else {
			registro[x].stock = n; 
			registro[x].num_ventas = 0;
		}
	}
	void comprar(string x) {
		if (registro.count(x) == 0) throw std::invalid_argument("Libro no existente");
		if (registro[x].stock == 0)throw std::out_of_range("No hay ejemplares");
		registro[x].stock--;
		if(registro[x].num_ventas != 0 )
			top[registro[x].num_ventas].erase(registro[x].it);
		registro[x].num_ventas++;
		top[registro[x].num_ventas].push_front(x);
		registro[x].it = top[registro[x].num_ventas].begin();
	}
	bool estaLibro(string x) {
		if (registro.count(x) != 0) return true;
		else return false;
	}
	void elimLibro(string x) {
		if (registro.count(x) != 0) {
			top[registro[x].num_ventas].erase(registro[x].it);
			registro.erase(x);
		}
	}
	int numEjemplares(string x) {
		if (registro.count(x) == 0) throw std::invalid_argument("Libro no existente");
		return registro[x].stock;
	}
	vector<string> top10() {
		vector<string> sol;
		int contador = 0;
		for (auto i = top.rbegin();  contador < 10 && i != top.rend(); ++i) {
			for (auto j = i->second.begin(); contador < 10 && j != i->second.end() ; ++j) {
				sol.push_back(*j);
				contador++;
			}
		}
		return sol;
	}
};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (cin.fail())
		return false;
	string op, x;
	int m;
	venta_libros v;
	for (int i = 0; i < n; ++i) {
		cin >> op;
		try {
			if (op == "nuevoLibro") {
				cin >> m;
				cin.get();
				getline(cin, x);
				v.nuevoLibro(m, x);
			}
			else if (op == "comprar") {
				cin.get();
				getline(cin, x);
				v.comprar(x);

			}
			else if (op == "estaLibro") {
				cin.get();
				getline(cin, x);
				if (v.estaLibro(x))
					cout << "El libro " << x << " esta en el sistema\n";
				else
					cout << "No existe el libro " << x << " en el sistema\n";
				cout << "---\n";
			}
			else if (op == "elimLibro") {
				cin.get();
				getline(cin, x);
				v.elimLibro(x);
			}
			else if (op == "numEjemplares") {
				cin.get();
				getline(cin, x);
				try{
					m = v.numEjemplares(x);
					cout << "Existen " << m << " ejemplares del libro " << x << "\n";
				}
				catch (exception &e) {
					cout << "No existe el libro " << x << " en el sistema\n";
				}
				cout << "---\n";

			}
			else if (op == "top10") {
				vector<string> top10 = v.top10();
				for (int i = 0;  i < 10 && i < top10.size(); ++i) {
					cout << top10[i] << "\n";
				}
				cout << "---\n";
			}
		}
		catch (exception &e) {
			cout << e.what() << "\n";
			cout << "---\n";
		}
		
	}
	cout << "------\n";

	// escribir sol


	return true;

}
//#define DOMJUDGE

//int main() {
//	// Para la entrada por fichero.
//	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//
//
//	while (resuelveCaso())
//		;
//
//	
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif
//
//	return 0;
//}