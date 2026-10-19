#include "Cola.hpp"

Cola::Cola()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->numPacientes = 0;
}

Cola::~Cola()
{
	vaciar();
}

bool Cola::estaVacia() const
{
	return primero == nullptr;
}

int Cola::getNumPacientes() const
{
	return numPacientes;
}

//Inserta un nuevo paciente por el final de la cola
void Cola::encolar(Paciente paciente) {
	NodoCola* nuevoNodo = new NodoCola(paciente);

	if (estaVacia())
	{
		primero = nuevoNodo;
	} else {
		ultimo->setSiguiente(nuevoNodo);
	}

	ultimo = nuevoNodo;
	numPacientes++;
}

Paciente Cola::desencolar()
{
	if (estaVacia())
	{
		std::cout << "La cola esta vacia. No se puede desencolar." << std::endl;
		return Paciente();
	}
	NodoCola* nodoAux = primero;
	Paciente pacientePrimero = nodoAux->getPaciente();
	
	primero = primero->getSiguiente();
	
	if (primero == nullptr)
	{
		ultimo = nullptr;
	}
	
	delete nodoAux;
	numPacientes--;
	
	return pacientePrimero;
}

void Cola::mostrar() const
{
	if (estaVacia())
	{
		std::cout << "La cola esta vacia." << std::endl;
		return;
	}
	
	NodoCola* actual = primero;
	while (actual != nullptr)
	{
		actual->getPaciente().mostrar();
		actual = actual->getSiguiente();
	}
}

void Cola::vaciar()
{
	while (!estaVacia())
	{
		desencolar();
	}
}
