#pragma once
#include "ListaBase.h"

class ListaSimple : public ListaBase {
public:
    void insertar(Persona* persona) override;
    void eliminar(const string& cedula) override;
    void modificar(const string& cedula, const string& nuevoNombre) override;
    void mostrar() const override;
    bool buscar(const string& cedula) const override;
    ~ListaSimple() override;
};

class ListaDoble : public ListaBase {
public:
    void insertar(Persona* persona) override;
    void eliminar(const string& cedula) override;
    void modificar(const string& cedula, const string& nuevoNombre) override;
    void mostrar() const override;
    bool buscar(const string& cedula) const override;
    ~ListaDoble() override;
};

class ListaCircular : public ListaBase {
public:
    void insertar(Persona* persona) override;
    void eliminar(const string& cedula) override;
    void modificar(const string& cedula, const string& nuevoNombre) override;
    void mostrar() const override;
    bool buscar(const string& cedula) const override;
    ~ListaCircular() override;
};