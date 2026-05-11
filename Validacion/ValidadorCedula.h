#ifndef VALIDADOR_CEDULA_H
#define VALIDADOR_CEDULA_H

#include "Validador.h"
#include "Nodo.h"
#include <string>

class ValidadorCedula : public Validador {
private:
    Nodo* cabeza;
    void registrarCedula(const string& numero, const string& nombre);
    void liberarMemoria();
    bool existeCedula(const string& cedula) const;
    bool cargarDesdeArchivo(const string& nombreArchivo);
    bool guardarRegistroEnArchivo(const string& cedula, const string& nombre) const;
    void reescribirArchivo() const;

public:
    ValidadorCedula();
    ~ValidadorCedula();
    
    bool validar(const string& cedula) override;
    bool agregarRegistro(const string& cedula, const string& nombre);
    bool buscarCedula(const string& cedula) const;
    bool eliminarCedula(const string& cedula);
    void mostrarRegistros() const;
    void contarPorProvincia() override;
};

#endif