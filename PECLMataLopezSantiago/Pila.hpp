#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila
{
private:
	NodoPila* cima;
	int numPacientes;
	
public:
	Pila();
	~Pila();
	
	//MÉTODOS PRINCIPALES
	void apilar(Paciente paciente);
	Paciente desapilar();
	void vaciar();
	
	//MÉTODOS DE CONSULTA
	bool estaVacia() const;
	int getNumPacientes() const;
	void mostrar() const;
};

#endif // PILA_HPP
