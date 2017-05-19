#include "consultorio.h"
#include <string>

using namespace std;

void ejecutarComando(string instr, consultorio &consulta) {
	int primerEspacio = instr.find_first_of(" ");
	string comando = instr.substr(0, primerEspacio);
	instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

	if (comando == "atiendeConsulta") {
		tMedico	medico = tMedico(instr);
		try { consulta.atiendeConsulta(medico); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl << "---" << endl; }
	}
	else if (comando == "listaPacientes") {
		primerEspacio = instr.find_first_of(" ");
		tMedico	medico = tMedico(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));
		int dia = stoi(instr);

		try { consulta.listaPacientes(medico, dia); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		cout << "---" << endl;
	}
	else if (comando == "nuevoMedico") {
		tMedico medico = tMedico(instr);
		consulta.nuevoMedico(medico);
	}
	else if (comando == "pideConsulta") {
		int dia = 0, hora = 0, minuto = 0;

		primerEspacio = instr.find_first_of(" ");
		tPaciente paciente = tPaciente(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		primerEspacio = instr.find_first_of(" ");
		tMedico medico = tMedico(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		primerEspacio = instr.find_first_of(" ");
		dia = stoi(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		primerEspacio = instr.find_first_of(" ");
		hora = stoi(instr.substr(0, primerEspacio));
		instr = instr.substr(primerEspacio + 1, (instr.length() - primerEspacio + 1));

		minuto = stoi(instr);

		fecha cita = fecha(dia, hora, minuto);
		try { consulta.pideConsulta(paciente, medico, cita); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl << "---" << endl; }
	}
	else if (comando == "siguientePaciente") {
		tPaciente paciente = tPaciente(instr);
		try { consulta.siguientePaciente(paciente); }
		catch (const ExcepcionTAD &e) { cout << e.msg() << endl; }
		cout << "---" << endl;
	}
}

void ejercicio() {
	int instrucciones = 0;
	string comando = "";
	cin >> instrucciones;
	while (!cin.fail())
	{
		getline(cin, comando);
		consultorio consulta;
		while (instrucciones-- > 0)
		{
			getline(cin, comando);
			ejecutarComando(comando, consulta);
		}
		cout << "------" << endl;
		cin >> instrucciones;
	}
}


int main() {
	ejercicio();
	return 0;
}
