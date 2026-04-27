#include <iostream>
#include "Quebrado.h"

using namespace std;

int main() {
    Quebrado<float> q1, q2, resultado, resultado1;
    float n, d; 

    cout << "Ingrese el primer Quebrado" << endl;
    cout << "Numerador: "; 
    cin >> n;
    q1.setNumerador(n);
    cout << "Denominador: "; cin >> d;
    q1.setDenominador(d);

    cout << "\n--- Ingrese el segundo quebrado ---" << endl;
    cout << "Numerador: "; cin >> n;
    q2.setNumerador(n);
    cout << "Denominador: "; cin >> d;
    q2.setDenominador(d);
    resultado = q1.sumar(q2);

    resultado = q1.operator/(q2);
    
    resultado1 = q1.sumar(q1, Quebrado<float>(3.4, 6));


    //cout << "\n Resultado de la Suma (q1 + q2): " << resultado.getNumerador() << " / " << resultado.getDenominador() << endl;
    
    //cout << "\n Resultado de la Suma SOBRECARGA (q1 + 3.4/6): " << resultado1.getNumerador() << " / " << resultado1.getDenominador() << endl;

    cout << "\n Resultado de la Division (q1 / q2): " << resultado.getNumerador() << " / " << resultado.getDenominador() << endl;   
    
    return 0;
}