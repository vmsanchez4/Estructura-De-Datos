#include <iostream>

using namespace std;

int main() {
    int a, b;

    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;

    cout << "\nAntes del intercambio:\n";
    cout << "  a = " << a << "\n";
    cout << "  b = " << b << "\n";

    // Intercambio XOR bit a bit (sin variable auxiliar)
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "\nDespues del intercambio:\n";
    cout << "  a = " << a << "\n";
    cout << "  b = " << b << "\n";

    return 0;
}