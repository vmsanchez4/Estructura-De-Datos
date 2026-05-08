#include "Nodo.h"

Nodo::Nodo(const Persona& p) {
    this->dato = p;
    this->siguiente = nullptr;
}

Persona Nodo::getDato() const {
     return this->dato;
    }
Nodo* Nodo::getSiguiente() const {
     return this->siguiente;
     }
void Nodo::setSiguiente(Nodo* sig) {
     this->siguiente = sig; 
    }