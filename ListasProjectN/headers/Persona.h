#pragma once
#include <string>
using namespace std;

// ============================================================
//  CLASE ABSTRACTA BASE - Solo prototipos
// ============================================================
class Persona {
protected:
    string nombre;
    string cedula;

public:
    Persona();
    Persona(const string& nombre, const string& cedula);
    virtual ~Persona();

    // Getters - referencias constantes
    virtual const string& getNombre() const;
    virtual const string& getCedula() const;

    // Setters - paso por referencia
    virtual void setNombre(const string& nombre);
    virtual void setCedula(const string& cedula);

    // Metodo virtual puro => clase abstracta
    virtual void mostrar() const = 0;
};
