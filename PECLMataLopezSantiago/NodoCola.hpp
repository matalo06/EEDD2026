#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Paciente.hpp"

class NodoCola 
{
private:
    Paciente paciente;
    NodoCola* siguiente;

public:
    NodoCola(Paciente paciente, NodoCola* siguiente = nullptr);
    ~NodoCola();

    Paciente getPaciente() const;
    NodoCola* getSiguiente() const;

    void setPaciente(Paciente paciente);
    void setSiguiente(NodoCola* siguiente);
};

#endif // NODOCOLA_HPP