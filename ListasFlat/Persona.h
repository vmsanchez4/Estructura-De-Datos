#pragma once
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    string cedula;
public:
    Persona();
    Persona(const string& nombre, const string& cedula);
    virtual ~Persona();

    virtual const string& getNombre() const;
    virtual const string& getCedula() const;
    virtual void setNombre(const string& nombre);
    virtual void setCedula(const string& cedula);

    virtual void mostrar() const = 0;   // Virtual puro => abstracta
};
