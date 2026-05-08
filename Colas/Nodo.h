#ifndef NODO_H
#define NODO_H
#include "Persona.h"

class Nodo {
private:
    Persona dato;
    Nodo* siguiente;

public:
    Nodo(const Persona& p);

    Persona getDato() const;
    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* sig);
};
#endif