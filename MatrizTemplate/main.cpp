#include <iostream>
#include <ctime>
#include "MatrizDinamica.h"

using namespace std;

int main() {
    srand(time(0)); 
    
    int dim;
    cout << "Ingrese la dimension para matrices cuadradas: ";
    cin >> dim;

    //aqui actua el template elejimos int
    MatrizDinamica<int> m1(dim, dim), m2(dim, dim), res(dim, dim);

    m1.llenarAleatorio();
    m2.llenarAleatorio();

    cout << "\nMatriz 1:" << endl; m1.mostrar();
    cout << "\nMatriz 2:" << endl; m2.mostrar();

    res.sumar(m1, m2);
    cout << "\nSuma:" << endl; 
    res.mostrar();

    

    return 0;
}