#include <iostream>
#include "Matriz.h"

using namespace std;

int main() {
    int dimension, z, i, j;
    float dato;
    
    cout << "Ingrese la dimension de la matriz > ";
    cin >> dimension;
    
    /* 
    Matriz matriz_1(dimension, dimension);
    Matriz matriz_2(dimension, dimension);
    Matriz suma(dimension, dimension);
    Matriz multiplicacion(dimension, dimension);
    */

    Matriz matriz_1(dimension, dimension, dimension);
    Matriz matriz_2(dimension, dimension, dimension);
    Matriz suma(dimension, dimension, dimension);
    Matriz multiplicacion(dimension, dimension, dimension);
    
    cout << "\nIngreso de la primera matriz 3D: " << endl;
    for(z = 0; z < dimension; z++) {
        cout << "--- CAPA " << z << " ---" << endl;
        for(i = 0; i < dimension; i++) {
            for(j = 0; j < dimension; j++) {
                cout << "Elemento [" << z << "][" << i << "][" << j << "]> ";
                cin >> dato;
                matriz_1.setElemento(z, i, j, dato);
            }
        }
    }
    
    cout << "\nIngreso de la segunda matriz 3D: " << endl;
    for(z = 0; z < dimension; z++) {
        cout << "--- CAPA " << z << " ---" << endl;
        for(i = 0; i < dimension; i++) {
            for(j = 0; j < dimension; j++) {
                cout << "Elemento [" << z << "][" << i << "][" << j << "]> ";
                cin >> dato;
                matriz_2.setElemento(z, i, j, dato);
            }
        }
    }

    suma.sumar(matriz_1, matriz_2, suma);
    multiplicacion.multiplicar(matriz_1, matriz_2, multiplicacion);
    
    cout << "\n===============================" << endl;
    cout << "Resultado de A * B:" << endl;
    for(z = 0; z < dimension; z++) {
        cout << "--- CAPA " << z << " ---" << endl;
        for(i = 0; i < dimension; i++) {
            for(j = 0; j < dimension; j++) {
                cout << multiplicacion.getElemento(z, i, j) << "\t";
            }
            cout << endl;
        }
    }
    cout << "===============================" << endl;

    return 0;
}