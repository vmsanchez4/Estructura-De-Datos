#include "Persona.h"

Persona::Persona(string nom, string ced) {
    nombre = nom;
    cedula = ced;
}

void Persona::setNombre(string nom) {
    nombre = nom;
}

void Persona::setCedula(string ced) {
    cedula = ced;
}

string Persona::getNombre() const { 
    return nombre; 
}

string Persona::getCedula() const { 
    return cedula; 
}