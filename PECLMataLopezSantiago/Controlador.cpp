#include "Controlador.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Controlador::Controlador() 
{
	srand(time(nullptr));
	prepararMazos();
}

Controlador::~Controlador() 
{
}

// Rellena los arrays con todos los números posibles y los baraja
void Controlador::prepararMazos() {
	posIdApendicitis = 0;
	posIdHernia = 0;
	posHabApendicitis = 0;
	posHabHernia = 0;

	// 1. Rellenar los mazos de IDs (49 valores cada uno)
	for (int i = 0; i < 49; i++) {
		idsApendicitis[i] = i + 1;     // Rango [1..49]
		idsHernia[i] = i + 51;         // Rango [51..99]
	}

	// 2. Rellenar los mazos de Habitaciones (99 valores cada uno)
	for (int i = 0; i < 99; i++) {
		habsApendicitis[i] = i + 101;  // Rango [101..199]
		habsHernia[i] = i + 201;       // Rango [201..299]
	}

	// 3. Barajar IDs de Apendicitis y Hernia
	for (int i = 0; i < 49; i++) {
		int r1 = rand() % 49;
		std::swap(idsApendicitis[i], idsApendicitis[r1]);

		int r2 = rand() % 49;
		std::swap(idsHernia[i], idsHernia[r2]);
	}

	// 4. Barajar Habitaciones de Apendicitis y Hernia
	for (int i = 0; i < 99; i++) {
		int r1 = rand() % 99;
		std::swap(habsApendicitis[i], habsApendicitis[r1]);

		int r2 = rand() % 99;
		std::swap(habsHernia[i], habsHernia[r2]);
	}
}

// MÉTODOS DE CONTEO PARA LA CABECERA

int Controlador::pacientesEnPila() const 
{
	return pila.getNumPacientes();
}

int Controlador::pacientesEnSalaA() const 
{
	return salaA.getNumPacientes();
}

int Controlador::pacientesEnSalaB() const 
{
	return salaB.getNumPacientes();
}

int Controlador::pacientesEnSalaC() const 
{
	return salaC.getNumPacientes();
}

int Controlador::pacientesEnSalaD() const 
{
	return salaD.getNumPacientes();
}

int Controlador::pacientesEnListaApendicitis() const 
{
	return listaApendicitis.getNumPacientes();
}

int Controlador::pacientesEnListaHernias() const 
{
	return listaHernia.getNumPacientes();
}

int Controlador::pacientesEnArbol() const 
{
	return 0;
}

// MÉTODOS DE LAS OPCIONES DEL MENÚ

// Opción A: Genera 12 pacientes aleatorios y los apila (máximo 48 en total)
void Controlador::genera12Pacientes() 
{
	if (pacientesEnPila() + pacientesEnSalaA() + pacientesEnSalaB() + 
    pacientesEnSalaC() + pacientesEnSalaD() + 
    pacientesEnListaApendicitis() + pacientesEnListaHernias() + 12 > 48) 
	{
		std::cout << "  No se pueden agregar mas pacientes. El sistema no puede superar los 48 elementos." << std::endl;
		return;
	}

	char letrasDNI[] = "TRWAGMYFPDXBNJZSQVHLCKE";

	for (int i = 0; i < 12; i++) 
	{
		// Generar DNI aleatorio (8 dígitos + letra)
		int numDNI = (rand() % 9000 + 1000) * 10000 + (rand() % 10000);
		std::string dni = std::to_string(numDNI) + letrasDNI[numDNI % 23];

		// Enfermedad aleatoria (true = apendicitis, false = hernia)
		bool apendicitis = (rand() % 2 == 0);

		Paciente p(dni, apendicitis);
		pila.apilar(p);
	}

	std::cout << "  Se han generado 12 pacientes aleatorios correctamente en la Pila." << std::endl;
}

// Opción B: Muestra los pacientes de la pila
void Controlador::muestraPacientes() const 
{
	std::cout << " || PACIENTES EN LA PILA ||\n" << std::endl;
	pila.mostrar();
}

// Opción C: Vacía la pila
void Controlador::borraPacientesPila() 
{
	pila.vaciar();
	std::cout << "  Se han borrado todos los pacientes de la pila." << std::endl;
}

// Opción D: Desapila de la Pila y los reparte en las Colas (Salas)
void Controlador::encolarPacientes() 
{
	if (pila.estaVacia()) 
	{
		std::cout << "  No hay pacientes en la pila para distribuir." << std::endl;
		return;
	}

	while (!pila.estaVacia()) 
	{
		Paciente p = pila.desapilar();

		if (p.esApendicitis()) 
		{
			// Coge el siguiente ID y Habitación del mazo mezclado
			p.setId(idsApendicitis[posIdApendicitis++]);
			p.setHabitacion(habsApendicitis[posHabApendicitis++]);

			if (salaA.getNumPacientes() <= salaB.getNumPacientes()) 
			{
				salaA.encolar(p);
			} else 
			  {
				salaB.encolar(p);
			  }
		} else 
		  {
			// Coge el siguiente ID y Habitación del mazo mezclado
			p.setId(idsHernia[posIdHernia++]);
			p.setHabitacion(habsHernia[posHabHernia++]);

			if (salaC.getNumPacientes() <= salaD.getNumPacientes()) 
			{
				salaC.encolar(p);
			} else 
			  {
				salaD.encolar(p);
			  }
		  }
	}
	std::cout << "  Se han distribuido los pacientes de la pila a sus correspondientes salas." << std::endl;
}

// Opción E: Muestra las salas A y B
void Controlador::muestraPacientesSalasAyB() const 
{
	std::cout << " || SALA A (Apendicitis) ||\n" << std::endl;
	salaA.mostrar();
	std::cout << "\n || SALA B (Apendicitis) ||\n" << std::endl;
	salaB.mostrar();
}

// Opción F: Muestra las salas C y D
void Controlador::muestraPacientesSalasCyD() const 
{
	std::cout << " || SALA C (Hernia) ||\n" << std::endl;
	salaC.mostrar();
	std::cout << "\n || SALA D (Hernia) ||\n" << std::endl;
	salaD.mostrar();
}

// Opción G: Vacía todas las colas
void Controlador::borraPacientesColas() 
{
	salaA.vaciar();
	salaB.vaciar();
	salaC.vaciar();
	salaD.vaciar();
	std::cout << "  Se han vaciado todas las salas de espera." << std::endl;
}

// Opción H: Pasa pacientes de las Colas a las Listas ordenadas de los Quirófanos
void Controlador::enlistarPacientes() 
{
	// Pasar pacientes de Sala A y B a la Lista de Apendicitis
	while (!salaA.estaVacia()) 
	{
		listaApendicitis.insertarEnOrden(salaA.desencolar());
	}
	while (!salaB.estaVacia()) 
	{
		listaApendicitis.insertarEnOrden(salaB.desencolar());
	}

	// Pasar pacientes de Sala C y D a la Lista de Hernia
	while (!salaC.estaVacia()) 
	{
		listaHernia.insertarEnOrden(salaC.desencolar());
	}
	while (!salaD.estaVacia()) 
	{
		listaHernia.insertarEnOrden(salaD.desencolar());
	}

	std::cout << "  Se han trasladado los pacientes de las salas a los quirofanos." << std::endl;
}

// Opción I: Muestra la lista del quirófano de Apendicitis
void Controlador::muestraPacientesApendicitis() const 
{
	std::cout << " || QUIROFANO APENDICITIS ||\n" << std::endl;
	listaApendicitis.mostrar();
}

// Opción J: Muestra la lista del quirófano de Hernia
void Controlador::muestraPacientesHernias() const 
{
	std::cout << " || QUIROFANO HERNIAS ||\n" << std::endl;
	listaHernia.mostrar();
}

// Opción K: Muestra el menor ID de apendicitis y el mayor ID de hernia
void Controlador::buscarPacientes() const 
{
	std::cout << " -- BUSQUEDA DE PACIENTES --\n" << std::endl;

	if (listaApendicitis.estaVacia()) 
	{
		std::cout << "  Lista de Apendicitis vacia." << std::endl;
	} else 
	 {
		Paciente menorApendicitis = listaApendicitis.getPacienteMenorID();
		std::cout << "  Paciente con APENDICITIS de menor prioridad:" << std::endl;
		menorApendicitis.mostrar();
	 }

	std::cout << std::endl;

	if (listaHernia.estaVacia()) 
	{
		std::cout << "  Lista de Hernias vacia." << std::endl;
	} else 
	 {
		Paciente mayorHernia = listaHernia.getPacienteMayorID();
		std::cout << "  Paciente con HERNIA de mayor prioridad:" << std::endl;
		mayorHernia.mostrar();
	 }
}

// Opción L: Reinicia todas las estructuras de datos
void Controlador::reiniciar() 
{
	pila.vaciar();
	salaA.vaciar();
	salaB.vaciar();
	salaC.vaciar();
	salaD.vaciar();
	listaApendicitis.vaciar();
	listaHernia.vaciar();
	prepararMazos(); // Vuelve a barajar los mazos desde el principio
	std::cout << "  Se han reiniciado todas las estructuras del sistema." << std::endl;
}
