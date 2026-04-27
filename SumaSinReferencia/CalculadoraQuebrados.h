#ifndef CALCULADORA_QUEBRADOS_H
#define CALCULADORA_QUEBRADOS_H

#include "Operaciones.h"

class CalculadoraQuebrados : public Operaciones {
public:
    // Declaramos que aquí vamos a sobrescribir (override) el método virtual
    Quebrado suma(Quebrado q1, Quebrado q2) override; 
};

#endif