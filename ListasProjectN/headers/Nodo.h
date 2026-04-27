#pragma once
#include "Persona.h"

// ============================================================
//  NODO GENERICO - Solo prototipos
// ============================================================
class Nodo {
public:
    Persona* dato;   // Puntero a tipo abstracto
    Nodo*    sig;    // Puntero al siguiente nodo
    Nodo*    ant;    // Puntero al nodo anterior (para lista doble)

    Nodo();
    explicit Nodo(Persona* persona);
    ~Nodo();
};
