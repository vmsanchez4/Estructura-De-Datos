#pragma once
#include "ListaBase.h"

// ============================================================
//  LISTA CIRCULAR - Solo prototipos
// ============================================================
class ListaCircular : public ListaBase {
private:
    Nodo* cola;   // El ultimo apunta de vuelta a cabeza

public:
    ListaCircular();
    ~ListaCircular() override;

    void insertar(Persona* persona)           override;
    void eliminar(const string& cedula)       override;
    void mostrar()                      const override;
    bool buscar(const string& cedula)   const override;

    // Metodo extra: dar N vueltas para visualizar circularidad
    void recorrerVueltas(int vueltas) const;

private:
    void liberarMemoria();
};
