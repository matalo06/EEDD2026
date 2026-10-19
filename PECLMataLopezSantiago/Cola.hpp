#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola {
private:
	NodoCola* primero;
	NodoCola* ultimo;
	int numPacientes;

public:
	Cola();
	~Cola();

	//MÉTODOS PRINCIPALES
	void encolar(Paciente paciente);
	Paciente desencolar();
	void vaciar();

	//MÉTODOS DE CONSULTA
	bool estaVacia() const;
	int getNumPacientes() const;
	void mostrar() const;
};

#endif // COLA_HPP