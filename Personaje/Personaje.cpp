#include "Personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje() { 
    salud = 0; 
}

void Personaje::ingresarDatos() {
    cout << "Ingrese la salud inicial del Heroe: ";
    cin >> salud;
}

void Personaje::mostrarDatos() const {
    cout << "Estado del Heroe: " << salud << " HP" << endl;
}

// VALOR: Recibe una copia mágica, la pocion original no se toca
void Personaje::curarValor(int pocion) {
    salud += pocion;
}

// REFERENCIA: Consume la pocion real
void Personaje::curarRef(int& pocion) {
    salud += pocion;
    pocion = 0; // Vaciamos la pocion original del main
}

// PUNTERO: Consume la pocion buscando su direccion de memoria
void Personaje::curarPtr(int* pocion) {
    if (pocion != nullptr) {
        salud += *pocion;
        *pocion = 0; // Vaciamos la pocion original
    }
}
