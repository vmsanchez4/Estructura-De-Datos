#include <iostream>
#include <ctime>
#include "MatrizDinamica.h"

using namespace std;

int main() {
    srand(time(0)); // Semilla para que los números cambien siempre
    
    int dim;
    cout << "Ingrese la dimension para matrices cuadradas: ";
    cin >> dim;

    // Instancia de objetos (TDA)
    MatrizDinamica m1(dim, dim), m2(dim, dim), res(dim, dim);

    m1.llenarAleatorio();
    m2.llenarAleatorio();

    cout << "\nMatriz 1:" << endl; m1.mostrar();
    cout << "\nMatriz 2:" << endl; m2.mostrar();

    // Aplicamos las operaciones
    res.sumar(m1, m2);
    cout << "\nSuma:" << endl; 
    res.mostrar();

    res.restar(m1, m2);
    cout << "\nResta:" << endl; 
    res.mostrar();

    res.multiplicar(m1, m2);
    cout << "\nMultiplicacion:" << endl; 
    res.mostrar();

    return 0;
}