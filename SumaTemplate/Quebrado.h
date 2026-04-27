/***********************************************************************
 * Module:  Quebrado.cpp
 * Author:  Vicente
 * Modified: sabado, 11 de abril de 2026 21:24:16
 * Purpose: Implementation of the class Quebrado
 ***********************************************************************/

#ifndef QUEBRADO_H
#define QUEBRADO_H

#include <iostream>
#include "Proceso.h"

template <class T>
class Quebrado : public Proceso<T> {
private:
    T numerador;
    T denominador;

public:
    Quebrado(T n = 0, T d = 1) : numerador(n), denominador(d) {}

    void setNumerador(T n) {
         numerador = n;
    }
    void setDenominador(T d) { 
        denominador = d; 
    }

    T getNumerador() const { 
    return numerador; }
    T getDenominador() const {
     return denominador; }

    
    Quebrado<T> sumar(Quebrado<T> q1) override {
        T n = (this->numerador * q1.getDenominador()) + (this->denominador * q1.getNumerador());
        T d = this->denominador * q1.getDenominador();
        return Quebrado<T>(n, d);
    }

    Quebrado<T> sumar(Quebrado<T> q1, Quebrado<T> q2) override {
        T n = (q1.getNumerador() * q2.getDenominador()) + (q1.getDenominador() * q2.getNumerador());
        T d = q1.getDenominador() * q2.getDenominador();
        return Quebrado<T>(n, d);
    }
    
    Quebrado operator/(const Quebrado& q1) const{

        return Quebrado(numerador * q1.getDenominador(), denominador*q1.getDenominador());
    }
};

#endif