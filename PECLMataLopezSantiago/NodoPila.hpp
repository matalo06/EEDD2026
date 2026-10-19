#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Paciente.hpp"

class NodoPila
{
private:
	Paciente paciente;
	NodoPila* siguiente;

public:
	NodoPila(Paciente paciente, NodoPila* siguiente = nullptr);
	~NodoPila();

	Paciente getPaciente() const;
	NodoPila* getSiguiente() const;
	
	void setPaciente(Paciente paciente);
	void setSiguiente(NodoPila* siguiente);
};

#endif // NODOPILA_HPP
