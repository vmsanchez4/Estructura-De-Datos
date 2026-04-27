#include "../headers/Nodo.h"

// ============================================================
//  IMPLEMENTACION - Nodo
// ============================================================

Nodo::Nodo() : dato(nullptr), sig(nullptr), ant(nullptr) {}

Nodo::Nodo(Persona* persona) : dato(persona), sig(nullptr), ant(nullptr) {}

Nodo::~Nodo() {
    // El Nodo libera el dato que contiene
    delete dato;
    dato = nullptr;
}
