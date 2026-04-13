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
    Quebrado(T n = 0, T d = 1){
        numerador = n;
        denominador = d;
    }

    void setNumerador(T n) { 
        numerador = n; 
    }

    void setDenominador(T d) { 
        denominador = d; 
    }

  
    T getNumerador() const { 
        return numerador; 
    }

    T getDenominador() const {
        return denominador; 
    }

    // Lógica de la suma
    Quebrado<T> sumar(const Quebrado<T>& q1) const override {
        T nuevoNum = (this->numerador * q1.getDenominador()) + (this->denominador * q1.getNumerador());
        T nuevoDen = this->denominador * q1.getDenominador();
        
        return Quebrado<T>(nuevoNum, nuevoDen);
    }
};

#endif


