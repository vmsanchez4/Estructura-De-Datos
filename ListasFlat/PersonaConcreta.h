#pragma once
#include "Persona.h"

class PersonaConcreta : public Persona {
public:
    PersonaConcreta();
    PersonaConcreta(const string& nombre, const string& cedula);
    ~PersonaConcreta() override;

    void mostrar() const override;
};
