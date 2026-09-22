#include <stdio.h>
#include "Persona.hpp"

using namespace std;

int main(int argc, char **argv){
	
	Persona* personas[10];
	
	for (int i = 0; i < 10; i++){
		int edadAsignada = 18 + i;
		personas[i] = new Persona(edadAsignada);
	}
	
	cout << " || PERSONAS CREADAS || " << endl;
	for (int i = 0; i < 10; i++){
		cout << "Persona " << i + 1 << ": "; 
		personas[i]->mostrar();
	}
	
	for (int i = 0; i < 10; i++) {
        delete personas[i];
    }
	
	return 0;
}
