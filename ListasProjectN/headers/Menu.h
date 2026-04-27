#pragma once
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaCircular.h"

// ============================================================
//  MENU PRINCIPAL - Solo prototipos
// ============================================================
class Menu {
private:
    ListaSimple*   listaSimple;
    ListaDoble*    listaDoble;
    ListaCircular* listaCircular;

    // Helpers privados
    Persona* pedirPersona()   const;
    string   pedirCedula()    const;
    void     submenuLista(ListaBase* lista, const string& nombre) const;
    void     opcionesExtras(int tipoLista) const;

public:
    Menu();
    ~Menu();

    void ejecutar();
};
