
#include <iostream>
#include "Quebrado.h"

using namespace std;

int main() {
    float n, d;
    Quebrado q1, q2, resultado; 

    cout << "--- Ingrese el primer quebrado ---" << endl;
    cout << "Numerador: ";
    cin >> n;
    q1.setNumerador(n);
    cout << "Denominador: "; 
    cin >> d;
    q1.setDenominador(d);

    cout << "\n--- Ingrese el segundo quebrado ---" << endl;
    cout << "Numerador: "; cin >> n;
    q2.setNumerador(n);
    cout << "Denominador: "; cin >> d;
    q2.setDenominador(d);

    resultado.sumar(q1, q2);

    cout << "\n--- Resultado de la Suma ---" << endl;
    q1.mostrar();
    cout << " + ";
    q2.mostrar();
    cout << " = ";
    resultado.mostrar();
    cout << endl;

    return 0;
}