#ifndef __IPUD_H
#define __IPUD_H

#include "HashMap.h"
#include "List.h"
#include "Exceptions.h" 
#include <string>
#include <iostream>

using namespace std;

typedef string Titulo;
typedef string Artista;

typedef struct {
	Titulo _cancion;
	Artista _artista;
	int _duracion;
	bool _enRepro;
	bool _enHist;
} Cancion;

class iPud
{
public:
	iPud();
	~iPud();

	void addSong(Titulo s, Artista a, int d);
	void addToPlaylist(Titulo s);
	string current() const;
	void play();
	void totalTime()const;
	void recent(int n)const;
	void deleteSong(Titulo s);

private:
	int tiempoRep;
	List<string> listaRep;
	List<string> listaHist;

	HashMap<Titulo, Cancion> canciones;

	HashMap<Titulo, List<string>::Iterator> cancionesHist;
	HashMap<Titulo, List<string>::Iterator> cancionesRep;

};

iPud::iPud() :tiempoRep(0) { }

iPud::~iPud() { }

//• addSong(S,A,D): A˜nade la canci´on S (un string) del artista A (un string) con duraci´on D (un
//	int) al iPud.Si ya existe una canci´on con el mismo nombre la operaci´on dar´a error.
void iPud::addSong(Titulo s, Artista a, int d) {
	if (!canciones.contains(s)) {
		Cancion nueva;
		nueva._cancion = s;
		nueva._artista = a;
		nueva._duracion = d;
		nueva._enHist = false;
		nueva._enRepro = false;
		canciones.insert(s, nueva);
	}
	else { throw ExcepcionTAD("ERROR addSong"); }
} //	O(1)

//• addToPlaylist(S) : A˜nade la canci´on S al final de la lista de reproducci´on.Si la canci´on ya se
//	encontraba en la lista entonces no se a˜nade(es decir, la lista no tiene canciones repetidas).Si la
//	canci´on no est´a en el iPud se devuelve error.
void iPud::addToPlaylist(Titulo s) {
	HashMap<Titulo, Cancion>::Iterator itCanciones = canciones.find(s);

	if (itCanciones != canciones.end()) {
		if (!itCanciones.value()._enRepro) {
			itCanciones.value()._enRepro = true;
			listaRep.push_front(itCanciones.value()._cancion);
			cancionesRep.insert(itCanciones.value()._cancion, listaRep.begin());
			tiempoRep += itCanciones.value()._duracion;
		}
	}
	else { throw ExcepcionTAD("ERROR addToPlaylist"); }
} //	O(1)

//• current() : Devuelve la primera canci´on de la lista de reproducci´on.Si la lista de reproducci´on es
//	vac´ıa se devuelve error.
string iPud::current() const {
	if (!listaRep.empty()) {
	return listaRep.back();
	}
	else { throw ExcepcionTAD("ERROR current"); }
} //	O(1)

//• play() : La primera canci´on de la lista de reproducci´on abandona la lista de reproducci´on y se
//	registra como reproducida.Si la lista es vac´ıa la acci´on no tiene efecto.
inline void iPud::play() {
	if (!listaRep.empty()) {
		Titulo tit = listaRep.back();

		cout << "Sonando " << tit << endl;

		HashMap<Titulo, Cancion>::Iterator itCanciones = canciones.find(tit);
		if (itCanciones != canciones.end()) {

			if (itCanciones.value()._enRepro) {
				cancionesRep.erase(tit);
			}
			if (itCanciones.value()._enHist) {
				HashMap<Titulo, List<string>::Iterator>::Iterator  iterador = cancionesHist.find(tit);
				listaHist.erase(iterador.value());
			}
			else { itCanciones.value()._enHist = true; }

			itCanciones.value()._enRepro = false;
			tiempoRep -= itCanciones.value()._duracion;
			
			listaHist.push_front(listaRep.back());
			listaRep.pop_back();
			cancionesHist.insert(tit, listaHist.begin());
		}
	}
	else { cout << "No hay canciones en la lista" << endl; }
} //	O(1)

//• totalTime() : Devuelve la suma de las duraciones de las canciones que integran la lista de reproducci´on
//	actual.Si es vac´ıa se devuelve 0.
void iPud::totalTime() const {
	cout << "Tiempo total " << tiempoRep << endl;
} //	O(1)

//• recent(N) : Obtiene la lista con las N(mayor que 0) ´ultimas canciones que se han reproducido
//	(mediante la operaci´on play), de la m´as reciente a la m´as antigua.Si el n´umero de canciones
//	reproducidas es menor que N se devolver´an todas.La lista no tiene repeticiones, de manera que si
//	una canci´on se ha reproducido m´as de una vez solo figurar´a la reproducci´on m´as reciente.
void iPud::recent(int n) const {
	int canciones = n;
	List<string>::ConstIterator itHistorico = listaHist.cbegin();
	List<string>::ConstIterator fin = listaHist.cend();

	if (itHistorico == fin) {
		cout << "No hay canciones recientes" << endl;
	}
	else {
		cout << "Las " << canciones << " mas recientes" << endl;
		while (itHistorico != fin && canciones-- > 0) {
			cout << "    " << itHistorico.elem() << endl;
			itHistorico++;
		}
	}
} //	O(n)

//• deleteSong(S) : Elimina todo rastro de la canci´on S del iPud.Si la canci´on no existe la operaci´on
//	no tiene efecto
inline void iPud::deleteSong(Titulo s) {
	HashMap<Titulo, Cancion>::Iterator itCanciones = canciones.find(s);
	HashMap<Titulo, List<string>::Iterator>::Iterator  itHist = cancionesHist.find(s);
	HashMap<Titulo, List<string>::Iterator>::Iterator  itRep = cancionesRep.find(s);

	if (itRep != cancionesRep.end()) {
		tiempoRep -= itCanciones.value()._duracion;
		listaRep.erase(itRep.value());
		cancionesRep.erase(s);
	}
	if (itCanciones != canciones.end()) {
		canciones.erase(s);
		canciones.erase(s);
	}
	if (itHist != cancionesHist.end()) {
		listaHist.erase(itHist.value());
		cancionesHist.erase(s);
	}
} //	O(1)

#endif // !__IPUD_H 
