#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "Quebrado.h"

class Operaciones {
public:
    // El método virtual puro tal como lo solicitaste
    virtual Quebrado suma(Quebrado q1, Quebrado q2) = 0; 
    
    virtual ~Operaciones() {}
};

#endif