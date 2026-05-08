#include "Persona.h"

using namespace std;

Persona::Persona(const string &ced, const string &nom) : cedula(ced), nombre(nom) {}
Persona::Persona() : cedula(""), nombre("") {}

string Persona::getCedula() const {
     return cedula;
     }
string Persona::getNombre() const {
     return nombre;
     }