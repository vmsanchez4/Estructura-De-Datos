#include "Persona.h"

Persona::Persona() : nombre(""), cedula("") {}

Persona::Persona(const string& nombre, const string& cedula)
    : nombre(nombre), cedula(cedula) {}

Persona::~Persona() {}

const string& Persona::getNombre() const { return nombre; }
const string& Persona::getCedula() const { return cedula; }
void Persona::setNombre(const string& n)  { nombre = n; }
void Persona::setCedula(const string& c)  { cedula = c; }
