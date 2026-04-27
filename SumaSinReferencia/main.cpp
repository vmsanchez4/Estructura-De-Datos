#include <iostream>
#include "Quebrado.h"
#include "CalculadoraQuebrados.h"

using namespace std;

int main() {
    Quebrado q1, q2;
    int temporal;

    cout << "--- Suma de Quebrados (100% Modular) ---\n\n";

    // --- PRIMER QUEBRADO ---
    cout << "Ingrese numerador del 1er quebrado: ";
    cin >> temporal;
    q1.setNumerador(temporal);

    cout << "Ingrese denominador del 1er quebrado: ";
    cin >> temporal;
    q1.setDenominador(temporal);

    // --- SEGUNDO QUEBRADO ---
    cout << "\nIngrese numerador del 2do quebrado: ";
    cin >> temporal;
    q2.setNumerador(temporal);

    cout << "Ingrese denominador del 2do quebrado: ";
    cin >> temporal;
    q2.setDenominador(temporal);

    // Instanciamos la calculadora
    CalculadoraQuebrados calc;

    // Ejecutamos la suma (que viene del método virtual implementado)
    Quebrado resultado = calc.suma(q1, q2);

    // Mostrar el resultado
    cout << "\nEl resultado de la suma es: ";
    resultado.mostrar();
    cout << "\n";

    return 0;
}