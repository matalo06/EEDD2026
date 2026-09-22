#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <iostream>
#include <cstring>

class Persona
{
public:
	Persona(int edad);
	int getEdad();
	bool esMujer();
	void setEdad(int edad);
	void mostrar();
	
	~Persona();
private:
	bool genero; // True = Mujer y False = Hombre
	int edad;
	char DNI[10];
	
};

#endif // PERSONA_HPP
