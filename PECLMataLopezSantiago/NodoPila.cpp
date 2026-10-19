#include "NodoPila.hpp"

NodoPila::NodoPila(Paciente paciente, NodoPila* siguiente)
{
	this->paciente = paciente;
	this->siguiente = siguiente;
}

NodoPila::~NodoPila()
{
}

Paciente NodoPila::getPaciente() const
{
	return paciente;
}

NodoPila* NodoPila::getSiguiente() const
{
	return siguiente;
}

void NodoPila::setPaciente(Paciente paciente)
{
	this->paciente = paciente;
}
void NodoPila::setSiguiente(NodoPila* siguiente)
 {
	 this->siguiente = siguiente;
 }