#include "Pila.hpp"

Pila::Pila()
{
	this->cima = nullptr;
	this->numPacientes = 0;
}

Pila::~Pila()
{
	vaciar();
}

//Comprobar si la pila está vacía
bool Pila::estaVacia() const
{
	return cima == nullptr;
}

//Devolver el número de pacientes en la pila
int Pila::getNumPacientes() const
{
	return numPacientes;
}

//Insertar un nuevo paciente en la cima de la pila
void Pila::apilar(Paciente paciente)
{
	NodoPila* nuevoNodo = new NodoPila(paciente, cima);
	cima = nuevoNodo;
	numPacientes++;
}

//Extraer al paciente que está en la cima de la pila
Paciente Pila::desapilar()
{
	if (estaVacia())
	{
		std::cout << "La pila esta vacia. No se puede desapilar." << std::endl;
		return Paciente();
	}
	
	NodoPila* nodoAux = cima;
	Paciente pacienteCima = nodoAux->getPaciente();
	
	cima = cima->getSiguiente();
	delete nodoAux;
	numPacientes--;
	
	return pacienteCima;
}

//Mostrar todos los pacientes en la pila
void Pila::mostrar() const
{
	if (estaVacia())
	{
		std::cout << "La pila esta vacia." << std::endl;
		return;
	}

	NodoPila* actual = cima;
	while (actual != nullptr)
	{
		actual->getPaciente().mostrar();
		actual = actual->getSiguiente();
	}
}

//Liberar toda la memoria dinamica de la pila
void Pila::vaciar()
{
	while (!estaVacia())
	{
		desapilar();
	}
}