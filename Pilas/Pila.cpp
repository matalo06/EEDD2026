#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(int v)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
    longitud++;
}

int Pila::extraer()
{
    pnodoPila nodo = ultimo;
    int v;
    if(!ultimo)
        return 0;
    ultimo = nodo->siguiente;
    v = nodo->valor;
    longitud--;
    delete nodo;
    return v;
}

int Pila::cima()
{
    pnodoPila nodo = ultimo;
    if(!ultimo)
        return 0;
    return ultimo->valor;
}

void Pila::mostrar()
{
    pnodoPila nodo = ultimo;
    cout << "El contenido de la pila es --> ";
    while(nodo)
    {
        cout << nodo->valor << " --> ";
        nodo = nodo->siguiente;
    }
    cout << endl;
}

int Pila::getLongitud()
{
    return this->longitud;
}

Pila::~Pila()
{
    pnodoPila nodo = ultimo;
    while(ultimo)
        extraer();
}