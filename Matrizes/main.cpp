#include <iostream>
#include <limits>
#include "Matriz.h"

using namespace std;

int main() {
    cout << "\n=== OP. DE MATRICES 3D (POO - SIN MVC) ===" << endl;

    int dim = 0;
    
    cout << "Ingrese la dimension de las matrices 3D (N > 0): ";
    cin >> dim;
        
    Matriz<int> mat1(dim);
    Matriz<int> mat2(dim);

    cout << "\n=== Llenando Matriz 1 ===" << endl;
    for (int p = 0; p < mat1.getDim(); p++) {
        for (int f = 0; f < mat1.getDim(); f++) {
            for (int c = 0; c < mat1.getDim(); c++) {
                int valor;
                cout << "Elemento (Capa " << p << ") (Fila " << f << ") (Columna " << c << "): ";
                cin >> valor;
                mat1.setElemento(p, f, c, valor);
            }
        }
    }


    cout << "\n=== Llenando Matriz 2 ===" << endl;
    for (int p = 0; p < mat2.getDim(); p++) {
        for (int f = 0; f < mat2.getDim(); f++) {
            for (int c = 0; c < mat2.getDim(); c++) {
                int valor;
                cout << "Elemento (Capa " << p << ") (Fila " << f << ") (Columna " << c << "): ";
                cin >> valor;
                mat2.setElemento(p, f, c, valor);
            }
        }
    }

    cout << "\n=== Matriz 1 ===" << endl;
    mat1.imprimir(); 

    cout << "\n=== Matriz 2 ===" << endl;
    mat2.imprimir(); 

    Matriz<int> matSuma = mat1 + mat2;
    cout << "\n=== RESULTADO DE LA SUMA 3D (RECURSIVA) ===" << endl;
    matSuma.imprimir();

    Matriz<int> matResta = mat1 - mat2;
    cout << "\n=== RESULTADO DE LA RESTA 3D (RECURSIVA) ===" << endl;
    matResta.imprimir();

    Matriz<int> matMult = mat1 * mat2;
    cout << "\n=== RESULTADO DE LA MULTIPLICACION 3D (ITERATIVA) ===" << endl;
    matMult.imprimir();

    return 0;
}