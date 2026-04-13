#include <iostream>
#include  "Quebrado.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Quebrado f1;
    Quebrado f2;
    Quebrado resultado;

    float numerador, denominador;

    cout << "Ingrese el primer Numerador: \n";
    cin >> numerador;
    f1.setNumerador(numerador);
    cout << "Ingrese el primer Denominador: \n";
    cin >> denominador;
    f1.setDenominador(denominador);
    cout << "Ingrese el segundo numerador: \n";
    cin >> numerador;
    f2.setNumerador(numerador);
    cout << "Ingrese el segundo donominador: \n";
    cin >> denominador;
    f2.setDenominador(denominador);

    resultado = f1.sumar(f2);

    cout << "El resultado es: \n"<<resultado.getNumerador() <<"/"<<resultado.getDenominador();
    
    /* code */
    return 0;
}
