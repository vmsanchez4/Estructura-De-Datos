#pragma once
#include "Persona.h"

// ============================================================
//  CLASE CONCRETA - Solo prototipos
//  Implementa el metodo virtual puro mostrar()
// ============================================================
class PersonaConcreta : public Persona {
public:
    PersonaConcreta();
    PersonaConcreta(const string& nombre, const string& cedula);
    ~PersonaConcreta() override;

    void mostrar() const override;
};
