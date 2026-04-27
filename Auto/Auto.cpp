#include "Auto.h"
#include <iostream>
//suma de os fracciones que de una suma
using namespace std;

Auto::Auto() { 
    combustible = 0.0f; 
}

void Auto::ingresarDatos() {
    cout << "Ingrese los litros actuales en el tanque del Auto: ";
    cin >> combustible;
}

void Auto::mostrarDatos() const {
    cout << "Medidor del tanque: " << combustible << " Litros." << endl;
}

void Auto::cargarValor(float litros) {
    combustible += litros;
}

void Auto::cargarRef(float& surtidor) {
    combustible += surtidor;
    surtidor = 0.0f; // Vaciamos el surtidor externo
}

void Auto::cargarPtr(float* surtidor) {
    if (surtidor != nullptr) {
        combustible += *surtidor;
        *surtidor = 0.0f;
    }
}