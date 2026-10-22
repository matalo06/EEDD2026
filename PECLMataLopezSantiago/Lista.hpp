#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
private:
	NodoLista* cabeza;
	int numPacientes;

public:
	Lista();
	~Lista();

	//MÉTODOS PRINCIPALES
	void insertarEnOrden(Paciente paciente); //Inserción ordenada por prioridad (ID)
	void vaciar();
	
	//MÉTODOS DE CONSULTA
	bool estaVacia() const;
	int getNumPacientes() const;
	void mostrar() const;


	//MÉTODOS PACIENTES ESPECÍFICOS
	Paciente getPacienteMayorID() const;
	Paciente getPacienteMenorID() const;
};

#endif // LISTA_HPP