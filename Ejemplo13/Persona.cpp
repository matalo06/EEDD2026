#include "Persona.hpp"   // TODOS LOS #INCLUDE EN EL HPP

Persona::Persona(int edad){
	this->edad = edad;
	this->genero = (edad % 2 == 0);
	strcpy(this->DNI, "12345678A");
	
}

int Persona::getEdad(){
	return this->edad;
}

bool Persona::esMujer(){
	return this->genero;
}

void Persona::setEdad(int edad){
	this->edad = edad;
}

void Persona::mostrar(){
	std::cout << "DNI: " << this->DNI << " | Edad: " << this->edad << " | Genero: " 
	<< (this->genero ? "Mujer" : "Hombre") << std::endl;
}

Persona::~Persona(){
	
}

