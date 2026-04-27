#include "../headers/Persona.h"
#include <iostream>
using namespace std;

// ============================================================
//  IMPLEMENTACION - Persona
// ============================================================

Persona::Persona() : nombre(""), cedula("") {}

Persona::Persona(const string& nombre, const string& cedula)
    : nombre(nombre), cedula(cedula) {}

Persona::~Persona() {}

const string& Persona::getNombre() const {
    return nombre;
}

const string& Persona::getCedula() const {
    return cedula;
}

void Persona::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Persona::setCedula(const string& cedula) {
    this->cedula = cedula;
}
