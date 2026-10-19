#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente paciente, NodoCola* siguiente)
{
	this->paciente = paciente;
	this->siguiente = siguiente;
}

NodoCola::~NodoCola()
{
}

Paciente NodoCola::getPaciente() const
{
	return paciente;
}

NodoCola* NodoCola::getSiguiente() const
{
	return siguiente;
}

void NodoCola::setPaciente(Paciente paciente)
{
	this->paciente = paciente;
}

void NodoCola::setSiguiente(NodoCola* siguiente)
{
	this->siguiente = siguiente;
}