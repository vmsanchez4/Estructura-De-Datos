#include <iostream>
#include "Quebrado.h"

using namespace std;

int main() {
    // AQUÍ ESTÁ LA MAGIA: Le decimos que construya Quebrados de tipo 'int'
    Quebrado<int> q1, q2,resultado;
    
    int n, d; // Variables temporales tipo int

    cout << "Ingrese el primer Quebrado" << endl;
    cout << "Numerador: ";
    cin >> n;
    q1.setNumerador(n);
    
    cout << "Denominador: ";
    cin >> d;
    q1.setDenominador(d);

    cout << "\n--- Ingrese el segundo quebrado ---" << endl;
    cout << "Numerador: ";
    cin >> n;
    q2.setNumerador(n);
    
    cout << "Denominador: ";
    cin >> d;
    q2.setDenominador(d);

    // Hacemos la suma
    resultado = q1.sumar(q2);

    // Mostramos
    cout << "\n Resultado de la Suma:" << resultado.getNumerador() << " / " << resultado.getDenominador() << endl;
    

    return 0;
}