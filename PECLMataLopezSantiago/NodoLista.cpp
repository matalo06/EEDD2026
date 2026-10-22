#include "NodoLista.hpp"

NodoLista::NodoLista(Paciente paciente, NodoLista* siguiente)
{
	this->paciente = paciente;
	this->siguiente = siguiente;
}

NodoLista::~NodoLista()
{
}

Paciente NodoLista::getPaciente() const
{
	return paciente;
}

NodoLista* NodoLista::getSiguiente() const
{
	return siguiente;
}

void NodoLista::setPaciente(Paciente paciente)
{
	this->paciente = paciente;
}

void NodoLista::setSiguiente(NodoLista* siguiente)
{
	this->siguiente = siguiente;
}