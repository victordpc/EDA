#ifndef __consultorio_H
#define __consultorio_H

#include "fecha.h"
#include "TreeMap.h"
#include "HashMap.h"
#include <string>

using namespace std;

typedef string tMedico;
typedef string tPaciente;
typedef TreeMap<fecha, tPaciente> tCitas;
typedef HashMap<tMedico, tCitas> tAgenda;

class consultorio
{
public:
	consultorio() {}

	~consultorio() {
	}

	/*
	Da de alta un nuevo m�dico en el consultorio. Si el m�dico ya estaba
	en el consultorio, este no se modifica.
	*/
	void nuevoMedico(tMedico m) {
		tAgenda::Iterator posicion = agenda.find(m);
		if (posicion == agenda.end()) {
			tCitas citas;
			agenda.insert(m, citas);
		}
	}


	/*
	El paciente p pide consulta con el m�dico m para una fecha f. Si el m�dico
	no est� dado de alta se lanzar� una excepci�n con el mensaje Medico no existente. Si el m�dico
	ya tiene reservada esta fecha, se lanzar� una excepci�n con el mensaje Fecha ocupada. Un paciente
	puede tener varias citas con el mismo m�dico, siempre que sean en distinto momento.
	*/
	void pideConsulta(tPaciente p, tMedico m, fecha f) {
		tAgenda::Iterator posicion = agenda.find(m);
		if (posicion != agenda.end()) {
			tCitas::Iterator citas = posicion.value().find(f);
			if (citas == posicion.value().end()) {
				posicion.value().insert(f, p);
			}
			else { throw ExcepcionTAD("Fecha ocupada"); }
		}
		else { throw ExcepcionTAD("Medico no existente"); }
	}

	/*
	Consulta el paciente al que le toca el turno de ser atendido por el m�dico m.
	Suponemos que el siguiente paciente es el que tiene una fecha menor. Si el m�dico no est� dado
	de alta se lanzar� una excepci�n con el mensaje Medico no existente. Si el m�dico no tiene
	pacientes asignados se lanzar� una excepci�n con mensaje No hay pacientes.
	*/
	void siguientePaciente(tPaciente m) {
		tAgenda::Iterator posicion = agenda.find(m);
		if (posicion != agenda.end()) {
			tCitas::ConstIterator citas = posicion.value().cbegin();
			if (citas != posicion.value().cend()) {
				cout << "Siguiente paciente doctor " << posicion.key() << endl;
				cout << citas.value() << endl;
			}
			else { throw ExcepcionTAD("No hay pacientes"); }
		}
		else { throw ExcepcionTAD("Medico no existente"); }
	}

	/*
	Elimina el siguiente paciente del m�dico m.Suponemos que el siguiente
	paciente es el que tiene una fecha menor.Si el m�dico no est� dado de alta se lanzar� una excepci�n
	con el mensaje Medico no existente.Si el m�dico no tiene pacientes asignados se lanzar� una
	excepci�n con mensaje No hay pacientes.
	*/
	void atiendeConsulta(tMedico m) {
		tAgenda::Iterator posicion = agenda.find(m);
		if (posicion != agenda.end()) {
			tCitas::ConstIterator citas = posicion.value().cbegin();
			if (citas != posicion.value().cend()) {
				posicion.value().erase(citas.key());
			}
			else { throw ExcepcionTAD("No hay pacientes"); }
		}
		else { throw ExcepcionTAD("Medico no existente"); }
	}

	/*
	Devuelve la lista de pacientes del m�dico m que tienen cita el d�a d. Se
	supone que el d�a es un n�mero entero correcto. Si el m�dico no est� dado de alta se lanzar� una
	excepci�n con el mensaje Medico no existente. Si el m�dico no tiene pacientes ese d�a, la lista
	devuelta ser� vac�a.
	*/
	void listaPacientes(tMedico m, int d) {
		tAgenda::Iterator posicion = agenda.find(m);
		if (posicion != agenda.end()) {
			tCitas::ConstIterator inicioCitas = posicion.value().cbegin();
			while (inicioCitas != posicion.value().cend() && inicioCitas.key().getDia() < d) {
				inicioCitas++;
			}
			tCitas::ConstIterator finCitas = inicioCitas;
			while (finCitas != posicion.value().cend() && finCitas.key().getDia() == d) {
				finCitas++;
			}

			cout << "Doctor " << posicion.key() << " dia " << d << endl;

			while (inicioCitas != finCitas)
			{
				cout << inicioCitas.value() << " "
					<< setfill('0') << setw(2) << inicioCitas.key().getHora() << ":"
					<< setfill('0') << setw(2) << inicioCitas.key().getMinuto()
					<< endl;
				inicioCitas++;
			}
		}
		else { throw ExcepcionTAD("Medico no existente"); }
	}

private:
	tAgenda agenda;
};

#endif // __consultorio_H
