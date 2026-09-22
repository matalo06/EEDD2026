#include <stdio.h>
#include <iostream>
#include "Cola.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Cola cola;

    cola.insertar(1);
    cola.insertar(2);
    cola.insertar(3);
    cola.insertar(4);
    cola.mostrar();

    int primero = cola.verPrimero();
    cola.eliminar();
    cout << "Despues de extraer el primero (" << primero << ")" << endl;
    cola.mostrar();

    cola.eliminar();
    cola.mostrar();
    cola.insertar(5);
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();

    return 0;
}