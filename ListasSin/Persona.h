#pragma once
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    string cedula;

public:
    Persona(string nom, string ced);
    Persona();
    void setNombre(string nom);
    void setCedula(string ced);
    string getNombre() const;
    string getCedula() const;
};