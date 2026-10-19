#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <iostream>

class Paciente
{
private:
	std::string dni;
	int id;
	int habitacion;
	bool apendicitis;  //true = apendicitis, false = hernia
	
public:
	Paciente();
	Paciente(std::string dni, bool es_apendicitis);
	~Paciente();
	
	//GETTERS
	std::string getDni() const;
	int getId() const;
	int getHabitacion() const;
	bool esApendicitis() const;
	
	//SETTERS
	void setId(int id);
	void setHabitacion(int habitacion);
	
	//MÉTODO PRINCIPAL IMPRIMIR INFORMACIÓN
	void mostrar() const;
	
};

#endif // PACIENTE_HPP
