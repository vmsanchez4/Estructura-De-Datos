#pragma once
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaCircular.h"
#include "PersonaConcreta.h"

class Menu {
private:
    ListaSimple<Persona>* listaSimple;
    ListaDoble<Persona>* listaDoble;
    ListaCircular<Persona>* listaCircular;

    Persona* pedirPersona() const;
    string pedirCedula() const;
    void submenuSimple() const;
    void submenuDoble() const;
    void submenuCircular() const;

public:
    Menu();
    ~Menu();
    void ejecutar();
};
