#ifndef _FECHA_H
#define _FECHA_H

using namespace std;
class fecha
{
public:
	fecha() {}
	fecha(int dia, int hora, int minuto) :_hora(hora), _minuto(minuto), _dia(dia) {}

	~fecha()
	{
	}

	const int getHora() const { return _hora; }
	const int getMinuto() const { return _minuto; }
	const int getDia() const { return _dia; }

	bool operator<(fecha const &obj) const {
		if (_dia < obj._dia) return true;
		if (_dia > obj._dia) return false;

		if (_hora < obj._hora) return true;
		if (_hora > obj._hora) return false;

		if (_minuto < obj._minuto) return true;
		if (_minuto > obj._minuto) return false;

		return false;
	}

	bool operator<=(fecha const &obj) const {
		if (_dia < obj._dia) return true;
		if (_dia > obj._dia) return false;

		if (_hora < obj._hora) return true;
		if (_hora > obj._hora) return false;

		if (_minuto < obj._minuto) return true;
		if (_minuto > obj._minuto) return false;

		return true;
	}

	bool operator>(fecha const &obj) const {
		if (_dia > obj._dia) return true;
		if (_dia < obj._dia) return false;

		if (_hora > obj._hora) return true;
		if (_hora < obj._hora) return false;

		if (_minuto > obj._minuto) return true;
		if (_minuto < obj._minuto) return false;

		return false;
	}

	bool operator>=(fecha const &obj) const {
		if (_dia > obj._dia) return true;
		if (_dia < obj._dia) return false;

		if (_hora > obj._hora) return true;
		if (_hora < obj._hora) return false;

		if (_minuto > obj._minuto) return true;
		if (_minuto < obj._minuto) return false;

		return true;
	}

	bool operator==(fecha const &obj) const{
		return _dia == obj._dia && _hora == obj._hora&& _minuto == obj._minuto;
	}

	bool operator!=(fecha const &obj) const{
		return !operator==(obj);
	}

private:
	int _hora;
	int _minuto;
	int _dia;
};


#endif // !_FECHA_H

