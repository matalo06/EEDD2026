#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Controlador {
private:
	Pila pila;
	Cola salaA;
	Cola salaB;
	Cola salaC;
	Cola salaD;
	Lista listaApendicitis;
	Lista listaHernia;

	// Mazos para IDs (49 elementos cada uno)
	int idsApendicitis[49];
	int idsHernia[49];
	int posIdApendicitis;
	int posIdHernia;

	// Mazos para Habitaciones (99 elementos cada uno)
	int habsApendicitis[99];
	int habsHernia[99];
	int posHabApendicitis;
	int posHabHernia;

	// Método privado para rellenar y mezclar los mazos
	void prepararMazos();
	
public:
	Controlador();
	~Controlador();

	// MÉTODOS CONTEO CABECERA MENÚ
	int pacientesEnPila() const;
	int pacientesEnSalaA() const;
	int pacientesEnSalaB() const;
	int pacientesEnSalaC() const;
	int pacientesEnSalaD() const;
	int pacientesEnListaApendicitis() const;
	int pacientesEnListaHernias() const;
	int pacientesEnArbol() const; // Devuelve 0 por ahora

	// MÉTODOS OPCIONES MENÚ
	void genera12Pacientes();
	void muestraPacientes() const;
	void borraPacientesPila();
	void encolarPacientes();
	void muestraPacientesSalasAyB() const;
	void muestraPacientesSalasCyD() const;
	void borraPacientesColas();
	void enlistarPacientes();
	void muestraPacientesApendicitis() const;
	void muestraPacientesHernias() const;
	void buscarPacientes() const;
	void reiniciar();
};

#endif // CONTROLADOR_HPP