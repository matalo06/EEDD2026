#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Paciente.hpp"

class NodoLista
{
private:
	Paciente paciente;
	NodoLista* siguiente;

public:
	NodoLista(Paciente paciente, NodoLista* siguiente = nullptr);
	~NodoLista();

	Paciente getPaciente() const;
	NodoLista* getSiguiente() const;

	void setPaciente(Paciente paciente);
	void setSiguiente(NodoLista* siguiente);
};

#endif // NODOLISTA_HPP