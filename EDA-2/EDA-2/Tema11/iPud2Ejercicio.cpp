#include "iPud2.h"
#include <string>

using namespace std;

bool ejecutarComando() {
	// leer los datos de la entrada
	string op;
	cin >> op;
	if (cin.fail())
		return false;
	string s, a;
	int d;
	iPud2 ipod2;
	while (op != "FIN") {
		if (op == "addSong") {
			cin >> s;
			cin >> a;
			cin >> d;
			try {
				ipod2.addSong(s, a, d);
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "addToPlaylist") {
			cin >> s;
			try {
				ipod2.addToPlaylist(s);
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "current") {
			try {
				string aux = ipod2.current();
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "play") {
			try {
				string aux = ipod2.play();
				cout << "Sonando " << aux << endl;
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "recent") {
			cin >> d;
			try {
				list<Titulo> aux = ipod2.recent(d);
				list<Titulo>::const_iterator itLista = aux.cbegin();

				if (itLista != aux.cend()) {
					cout << "Las " << d << " mas recientes" << endl;
					while (itLista != aux.cend()) {
						cout << "    " << *itLista << endl;
						itLista++;
					}
				}
				else { cout << "No hay canciones recientes" << endl; }
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "totalTime") {
			try {
				int time = ipod2.totalTime();
				cout << "Tiempo total " << time << endl;
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "deleteSong") {
			cin >> s;
			try {
				ipod2.deleteSong(s);
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "generateArtistList") {
			cin >> a;
			try {
				ipod2.generateArtistList(a);
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "setPlaylist") {
			cin >> a;
			try {
				ipod2.setPlaylist(a);
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "saveCurrentList") {
			cin >> a;
			try {
				ipod2.saveCurrentList(a);
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		else if (op == "allLists") {
			try {
				list<ListaRep> listas = ipod2.allLists();
				if (listas.empty())
					cout << "No hay listas de reproduccion" << endl;
				else {
					cout << "Listas de reproduccion" << endl;
					list<ListaRep>::const_iterator itListaRep = listas.cbegin();
					while (itListaRep != listas.cend()) {
						cout << "    " << *itListaRep << endl;
						itListaRep++;
					}
				}
			}
			catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		}
		cin >> op;
	}
	cout << "----" << endl;
	// escribir sol
	return true;
}

void ejercicio5() {
	while (ejecutarComando()) {}
}
