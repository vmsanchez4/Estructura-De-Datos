#include "../headers/PersonaConcreta.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ============================================================
//  IMPLEMENTACION - PersonaConcreta
// ============================================================

PersonaConcreta::PersonaConcreta() : Persona() {}

PersonaConcreta::PersonaConcreta(const string& nombre, const string& cedula)
    : Persona(nombre, cedula) {}

PersonaConcreta::~PersonaConcreta() {}

// Implementacion del metodo virtual puro heredado de Persona
void PersonaConcreta::mostrar() const {
    cout << "Nombre: " << left << setw(28) << nombre
         << " | Cedula: " << cedula << endl;
}
