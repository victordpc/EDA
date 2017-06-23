#include "iPud.h"
#include <string>

using namespace std;

void ejecutarComando(string instr, iPud &reproductor) {
	int primerEspacio = instr.find_first_of(" ");
	string comando = instr.substr(0, primerEspacio);
	instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

	if (comando == "deleteSong") {
		Titulo	cancion = Titulo(instr);
		try { reproductor.deleteSong(cancion); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
	else if (comando == "recent") {
		int	numero = stoi(instr);
		try { reproductor.recent(numero); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
	else if (comando == "play") {
		try { reproductor.play(); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
	else if (comando == "current") {
		try { reproductor.current(); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
	else if (comando == "totalTime") {
		try { reproductor.totalTime(); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
	else if (comando == "addSong") {
		int duracion = 0;

		primerEspacio = instr.find_first_of(" ");
		Titulo titulo = Titulo(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		primerEspacio = instr.find_first_of(" ");
		Artista artista = Artista(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		primerEspacio = instr.find_first_of(" ");
		duracion = stoi(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		try { reproductor.addSong(titulo, artista, duracion); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
	else if (comando == "addToPlaylist") {
		Titulo cancion = Titulo(instr);
		try { reproductor.addToPlaylist(cancion); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
	}
}

void ejercicio3() {
	string comando = "";
	getline(cin, comando);
	iPud reproductor;
	while (!cin.fail()) {
		iPud reproductor;
		while (comando != "FIN")
		{
			ejecutarComando(comando, reproductor);
			getline(cin, comando);
		}
		cout << "----" << endl;
		getline(cin, comando);
	}
}
