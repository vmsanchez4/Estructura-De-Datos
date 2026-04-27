#include "PersonaConcreta.h"
#include <iostream>
#include <iomanip>
using namespace std;

PersonaConcreta::PersonaConcreta() : Persona() {}

PersonaConcreta::PersonaConcreta(const string& nombre, const string& cedula)
    : Persona(nombre, cedula) {}

PersonaConcreta::~PersonaConcreta() {}

void PersonaConcreta::mostrar() const {
    cout << "Nombre: " << left << setw(28) << nombre
         << " | Cedula: " << cedula << endl;
}
