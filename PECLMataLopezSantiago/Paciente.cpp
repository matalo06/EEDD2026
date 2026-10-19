#include "Paciente.hpp"

//CONSTRUCTORES
Paciente::Paciente()
{
	this->dni = "";
	this->id = -1;
	this->habitacion = -1;
	this->apendicitis = true;
}

Paciente::Paciente(std::string dni, bool apendicitis)
{
	this->dni = dni;
	this->apendicitis = apendicitis;
	this->id = -1;
	this-> habitacion = -1;
}

//DESTRUCTOR
Paciente::~Paciente()
{
}

//GETTERS
std::string Paciente::getDni() const
{
	return dni;
}

int Paciente::getId() const
{
	return id;
}

int Paciente::getHabitacion() const 
{
	return habitacion;
}

bool Paciente::esApendicitis() const
{
	return apendicitis;
}

//SETTERS
void Paciente::setId(int id)
{
	this->id = id;
}

void Paciente::setHabitacion(int habitacion)
{
	this->habitacion = habitacion;
}

//MÉTODO PRINCIPAL IMPRIMIR INFORMACIÓN
void Paciente::mostrar() const
{
	std::cout << "El paciente cuyo DNI es " << dni << (apendicitis ? " tiene apendicitis" : " tiene hernia");
	if (id != -1 && habitacion != -1)
	{
		std::cout << ", su ID es: " << id << " y su habitación asignada es: " << habitacion;
	}
	std::cout << std::endl;
}

