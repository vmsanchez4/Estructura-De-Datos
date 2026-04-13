/***********************************************************************
 * Module:  Proceso.h
 * Author:  USUARIO
 * Modified: mi�rcoles, 8 de abril de 2026 22:25:43
 * Purpose: Declaration of the class Proceso
 ***********************************************************************/

#ifndef PROCESO_H
#define PROCESO_H

class Quebrado;

class Proceso {
public:
    virtual void sumar(const Quebrado& q1, const Quebrado& q2) = 0;
    virtual void mostrar() const = 0;
    virtual ~Proceso() = default;
};
#endif 