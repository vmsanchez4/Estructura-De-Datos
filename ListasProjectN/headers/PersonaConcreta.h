#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;

// ============================================================
//  CLASE CONCRETA que implementa mostrar() virtual puro
//  Va en .h porque es una clase pequeña de datos
// ============================================================
class PersonaConcreta : public Persona {
public:
    PersonaConcreta();
    PersonaConcreta(const string& nombre, const string& cedula);
    ~PersonaConcreta() override;

    void mostrar() const override;
};
