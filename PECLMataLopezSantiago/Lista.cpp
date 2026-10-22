#include "Lista.hpp"

Lista::Lista() 
{
	this->cabeza = nullptr;
	this->numPacientes = 0;
}

Lista::~Lista() 
{
	vaciar();
}

bool Lista::estaVacia() const 
{
	return cabeza == nullptr;
}

int Lista::getNumPacientes() const 
{
	return numPacientes;
}

void Lista::insertarEnOrden(Paciente paciente) {
	NodoLista* nuevoNodo = new NodoLista(paciente);

	//Caso 1: La lista está vacía o el nuevo paciente tiene mayor ID que el primero
    if (estaVacia() || paciente.getId() > cabeza->getPaciente().getId()) 
	{
		nuevoNodo->setSiguiente(cabeza);
		cabeza = nuevoNodo;
	} else 
	  {
		//Caso 2: Buscar la posición adecuada recorriendo la lista
		NodoLista* actual = cabeza;
		while (actual->getSiguiente() != nullptr && 
				actual->getSiguiente()->getPaciente().getId() > paciente.getId())
			{
				actual = actual->getSiguiente();
			}

		//Insertar el nuevo nodo entre 'actual' y 'actual->getSiguiente()'
		nuevoNodo->setSiguiente(actual->getSiguiente());
		actual->setSiguiente(nuevoNodo);
	  }

    numPacientes++;
}

// Muestra todos los pacientes de la lista
void Lista::mostrar() const 
{
	if (estaVacia()) 
	{
		std::cout << "La lista esta vacia." << std::endl;
		return;
	}

	NodoLista* actual = cabeza;
	while (actual != nullptr)
	{
		actual->getPaciente().mostrar();
		actual = actual->getSiguiente();
	}
}

// Devuelve el paciente con mayor ID (al estar ordenada descendentemente, es la cabeza)
Paciente Lista::getPacienteMayorID() const
{
	if (estaVacia()) 
	{
		return Paciente();
	}
	return cabeza->getPaciente();
}

// Devuelve el paciente con menor ID (al estar ordenada descendentemente, es el último nodo)
Paciente Lista::getPacienteMenorID() const 
{
	if (estaVacia())
	{
		return Paciente();
	}

	NodoLista* actual = cabeza;
	while (actual->getSiguiente() != nullptr) 
	{
		actual = actual->getSiguiente();
	}
	return actual->getPaciente();
}

// Libera toda la memoria dinámicamente reservada de la lista
void Lista::vaciar() 
{
	NodoLista* actual = cabeza;
	while (actual != nullptr) 
	{
		NodoLista* aux = actual;
		actual = actual->getSiguiente();
		delete aux;
	}
	cabeza = nullptr;
	numPacientes = 0;
}