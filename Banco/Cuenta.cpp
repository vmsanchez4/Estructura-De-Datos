#include "Cuenta.h"
#include <iostream>
#include <cstdio>
using namespace std;

Cuenta::Cuenta() { saldo = 0.0; }

void Cuenta::ingresarDatos() {
    printf("Ingrese el saldo inicial de la cuenta: ");
    scanf("%lf", &saldo);
}

void Cuenta::mostrarDatos() const {
    printf("Saldo actual en cuenta: $%.2f\n", saldo);
}

void Cuenta::depositarValor(double cantidad) {
    saldo += cantidad; // Solo copia, no afecta al origen
}

void Cuenta::depositarRef(double& billetera) {
    saldo += billetera;
    billetera = 0; // Vaciamos la variable original
}

void Cuenta::depositarPtr(double* billetera) {
    if (billetera != nullptr) {
        saldo += *billetera;
        *billetera = 0;
    }
}