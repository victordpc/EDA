#ifndef __IPUD2_H
#define __IPUD2_H

#include "Exceptions.h" 
#include <string>
#include <iostream>
#include <list>
#include <unordered_map>
#include <map>

using namespace std;

typedef string Titulo;
typedef string Artista;
typedef string ListaRep;
typedef string TituloLista;

typedef struct {
	Artista artista;
	int duracion;
	Titulo cancion;
}infoArtistas;

typedef struct {
	string artista;
	int duracion;
	list<Titulo>::iterator itListaReproduccion; // iterador de las que estan en la lista de reproduccion
	list<Titulo>::iterator itReproducidas; // iterador de las que estan reproducidas;
	list<infoArtistas>::iterator itArtistas; // iterador de la lista de artistas y canciones
	map<TituloLista, list<Titulo>::iterator> itListaListasRep; // mapa con clave nombre lista y un iterador a la cancion de la lista con nombre de la clave
}infoCancion;


class iPud2
{
public:
	iPud2();
	~iPud2();

	void addSong(Titulo s, Artista a, int d) throw();
	void addToPlaylist(Titulo s) throw();
	Titulo current() const throw();
	Titulo play() throw();
	int totalTime()const;
	list<Titulo> recent(int n)const;
	void deleteSong(Titulo s) throw();

	/* Version 2.0 */
	void saveCurrentList(ListaRep nom);
	void generateArtistList(Artista a);
	void setPlaylist(ListaRep nom) throw();
	list<ListaRep>allLists();
	/* Version 2.0 */

private:
	unordered_map<string, infoCancion> ipud;
	list<string> listaReproduccion;
	list<string> reproducidas;
	int duracion_total_reproducidas = 0;
	map<string, list<string>> listaReproduccion_nom; // key artista, valor lista de canciones (ARTIST LIST)
	list<infoArtistas> artistas;
};

iPud2::iPud2() { }

iPud2::~iPud2() { }

//• addSong(S,A,D): A˜nade la canci´on S (un string) del artista A (un string) con duraci´on D (un
//	int) al iPud.Si ya existe una canci´on con el mismo nombre la operaci´on dar´a error.
void iPud2::addSong(Titulo s, Artista a, int d) throw() {
	if (ipud.find(s) == ipud.end()) {
		artistas.push_front({ a, d, s });
		ipud[s] = { a, d , listaReproduccion.end(), reproducidas.end(), artistas.begin() };
	}
	else { throw ExcepcionTAD("ERROR addSong"); }
} //	O(1)

//• addToPlaylist(S) : A˜nade la canci´on S al final de la lista de reproducci´on.Si la canci´on ya se
  //	encontraba en la lista entonces no se a˜nade(es decir, la lista no tiene canciones repetidas).Si la
  //	canci´on no est´a en el iPud se devuelve error.
void iPud2::addToPlaylist(Titulo s)  throw() {
	if (ipud.find(s) != ipud.end()) {
		if (ipud[s].itListaReproduccion == listaReproduccion.end()) {
			listaReproduccion.push_front(s);
			duracion_total_reproducidas += ipud[s].duracion;
			ipud[s].itListaReproduccion = listaReproduccion.begin();
		}
	}
	else { throw ExcepcionTAD("ERROR addToPlaylist"); }
} //	O(1)

//• current() : Devuelve la primera canci´on de la lista de reproducci´on.Si la lista de reproducci´on es
  //	vac´ıa se devuelve error.
Titulo iPud2::current() const throw() {
	if (!listaReproduccion.empty()) { return listaReproduccion.back(); }
	else { throw ExcepcionTAD("ERROR current"); }
} //	O(1)

//• play() : La primera canci´on de la lista de reproducci´on abandona la lista de reproducci´on y se
  //	registra como reproducida.Si la lista es vac´ıa la acci´on no tiene efecto.
Titulo iPud2::play() throw() {
	if (!listaReproduccion.empty()) {
		if (ipud[current()].itReproducidas != reproducidas.end()) {
			reproducidas.erase(ipud[current()].itReproducidas);
		}
		reproducidas.push_front(current());
		duracion_total_reproducidas -= ipud[current()].duracion;
		ipud[current()].itReproducidas = reproducidas.begin();
		ipud[current()].itListaReproduccion = listaReproduccion.end();
		string actual = current();
		listaReproduccion.pop_back();
		return actual;
	}
	else { throw ExcepcionTAD("No hay canciones en la lista"); }
} //	O(1)

//• totalTime() : Devuelve la suma de las duraciones de las canciones que integran la lista de reproducci´on
  //	actual.Si es vac´ıa se devuelve 0.
int iPud2::totalTime() const {
	if (listaReproduccion.empty()) return 0;
	return duracion_total_reproducidas;
} //	O(1)

//• recent(N) : Obtiene la lista con las N(mayor que 0) ´ultimas canciones que se han reproducido
  //	(mediante la operaci´on play), de la m´as reciente a la m´as antigua.Si el n´umero de canciones
  //	reproducidas es menor que N se devolver´an todas.La lista no tiene repeticiones, de manera que si
  //	una canci´on se ha reproducido m´as de una vez solo figurar´a la reproducci´on m´as reciente.
list<Titulo> iPud2::recent(int n) const {
	list<Titulo> reciente;
	if (reproducidas.size() < n) return reproducidas;
	int i = 0;

	list<Titulo>::const_iterator itRep = reproducidas.cbegin();
	while (itRep != reproducidas.cend() && i++ < n) {
		reciente.push_back(*itRep);
		itRep	++;
	}
	return reciente;
} //	O(n)

//• deleteSong(S) : Elimina todo rastro de la canci´on S del iPud.Si la canci´on no existe la operaci´on
  //	no tiene efecto
void iPud2::deleteSong(Titulo s)  throw() {
	if (ipud.count(s) == 0) throw ExcepcionTAD("ERROR deleteSong");
	if (ipud[s].itListaReproduccion != listaReproduccion.end())
		listaReproduccion.erase(ipud[s].itListaReproduccion);
	if (ipud[s].itReproducidas != reproducidas.end())
		reproducidas.erase(ipud[s].itReproducidas);
	if (ipud[s].itArtistas != artistas.end())
		artistas.erase(ipud[s].itArtistas);
	if (!ipud[s].itListaListasRep.empty() && !listaReproduccion_nom.empty()) {
		for (auto i : ipud[s].itListaListasRep) {
			listaReproduccion_nom[i.first].erase(i.second);
		}
	}
	ipud.erase(s);
} //	O(1)

//• saveCurrentList(Nom) : Guarda la lista de reproducci´on actual con el nombre Nom proporcionado
//(un string).
void iPud2::saveCurrentList(ListaRep nom)
{
	for (auto &i : listaReproduccion_nom[nom]) {
		ipud[i].itListaListasRep[nom] = listaReproduccion_nom[nom].end();
		i.erase();
	}
	listaReproduccion_nom[nom].clear();
	for (auto i = listaReproduccion.rbegin(); i != listaReproduccion.rend(); ++i) {
		listaReproduccion_nom[nom].push_front(*i);
		ipud[*i].itListaListasRep[nom] = listaReproduccion_nom[nom].begin();
	}
}

//• generateArtistList(A) : Genera una nueva lista de reproducci´on con las canciones del artista A
//(si es que hay alguna), en el orden en que fueron a˜nadidas al iPud, y la almacena con el propio
//nombre del artista.
void iPud2::generateArtistList(Artista a)
{
	for (auto &i : listaReproduccion_nom[a]) {
		ipud[i].itListaListasRep[a] = listaReproduccion_nom[a].end();
		i.erase();
	}
	listaReproduccion_nom[a].clear();
	for (auto it = artistas.rbegin(); it != artistas.rend(); ++it) {
		if (it->artista == a) {
			listaReproduccion_nom[a].push_front(it->cancion);
			ipud[it->cancion].itListaListasRep[a] = listaReproduccion_nom[a].begin();
		}
	}
}

//• setPlaylist(Nom) : Pone como lista actual la lista Nom proporcionada.Si la lista no existe se
//devuelve error
void iPud2::setPlaylist(ListaRep nom) throw() {
	if (listaReproduccion_nom.count(nom) == 0) throw std::domain_error("ERROR setPlaylist");
	duracion_total_reproducidas = 0;
	for (auto i : listaReproduccion) {
		ipud[i].itListaReproduccion = listaReproduccion.end();
		i.erase();
	}
	listaReproduccion.clear();
	for (auto it = listaReproduccion_nom[nom].rbegin(); it != listaReproduccion_nom[nom].rend(); ++it) {
		duracion_total_reproducidas += ipud[*it].duracion;
		listaReproduccion.push_front(*it);
		ipud[*it].itListaReproduccion = listaReproduccion.begin();
	}
}

//• allLists() : que devuelve una lista ordenada con los nombres de las listas 
//de reproducci´on almacenadas.
list<ListaRep> iPud2::allLists()
{
	list<ListaRep> resultado;
	for (auto it : listaReproduccion_nom) {
		resultado.push_back(it.first);
	}
	return resultado;
}

#endif // !__IPUD2_H 
