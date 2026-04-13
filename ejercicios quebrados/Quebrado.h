/***********************************************************************
 * Module:  Quebrado.h
 * Author:  USUARIO
 * Modified: mi�rcoles, 8 de abril de 2026 22:31:12
 * Purpose: Declaration of the class Quebrado
 ***********************************************************************/

#ifndef QUEBRADO_H
#define QUEBRADO_H

#include "Proceso.h"

class Quebrado : public Proceso {
private:
    float numerador;
    float denominador;

public:
    Quebrado(float n = 0, float d = 1);

    void setNumerador(float n);
    void setDenominador(float d);
    float getNumerador() const;
    float getDenominador() const;

    void sumar(const Quebrado& q1, const Quebrado& q2) override;
    void mostrar() const override;
};

#endif