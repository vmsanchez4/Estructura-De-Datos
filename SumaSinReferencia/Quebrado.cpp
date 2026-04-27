#include <iostream>
#include "Quebrado.h"

using namespace std;

Quebrado::Quebrado(int num, int den) {
    numerador = num;
    denominador = den;
}

int Quebrado::getNumerador() const { return numerador; }
int Quebrado::getDenominador() const { return denominador; }

void Quebrado::setNumerador(int num) { numerador = num; }
void Quebrado::setDenominador(int den) { denominador = den; }

void Quebrado::mostrar() const {
    cout << numerador << "/" << denominador;
}