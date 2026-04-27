
#include "Quebrado.h"
#include <iostream>
#include <cmath>

using namespace std;

Quebrado::Quebrado(float n, float d) {
    numerador = n;
    denominador =  d; 
}

void Quebrado::setNumerador(float n) { 
    numerador = n; 
}
void Quebrado::setDenominador(float d) {
     denominador = d; 
}
float Quebrado::getNumerador() const {
     return numerador;
}
float Quebrado::getDenominador() const { 
    return denominador; 
}

void Quebrado::sumar(const Quebrado& q1, const Quebrado& q2) {
    this->numerador = (q1.numerador * q2.denominador) + (q2.numerador * q1.denominador);
    this->denominador = q1.denominador * q2.denominador;
}

void Quebrado::mostrar() const {
    cout << numerador << "/" << denominador;
}

Quebrado Quebrado::operator/(const Quebrado& q1) const {
     return Quebrado(numerador * q1.getDenominador(), denominador * q1.getNumerador());
}