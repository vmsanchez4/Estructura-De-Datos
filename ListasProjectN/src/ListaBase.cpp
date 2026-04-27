#include "../headers/ListaBase.h"

// ============================================================
//  IMPLEMENTACION - ListaBase
// ============================================================

ListaBase::ListaBase() : cabeza(nullptr), tamanio(0) {}

ListaBase::~ListaBase() {}

bool ListaBase::estaVacia() const {
    return cabeza == nullptr;
}

int ListaBase::getTamanio() const {
    return tamanio;
}
