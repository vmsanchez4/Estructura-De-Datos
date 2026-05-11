#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string>
#include <vector>
#include "Usuario.h"

namespace Archivos {
    void asegurarEstructura();

    bool appendUsuarioRegistro(const Usuario& u);
    bool existeUsuarioRegistro(const std::string& id);
    bool cargarPerfil(const std::string& id, Usuario& u);
    bool guardarPerfil(const Usuario& u);

    bool cargarCuenta(const std::string& id, Usuario& u);
    bool guardarCuenta(const Usuario& u);

    bool appendTransaccion(const std::string& id, const Transaccion& tx);
    bool appendLogica(const std::string& id, const Transaccion& tx, const EvaluacionLogica& eval);

    std::string rutaUsuarioDir(const std::string& id);
    std::string rutaPerfil(const std::string& id);
    std::string rutaCuenta(const std::string& id);
    std::string rutaTransacciones(const std::string& id);
    std::string rutaLogica(const std::string& id);
    bool cargarTransacciones(const std::string& id, Usuario& u);
    bool cargarLogica(const std::string& id, Usuario& u);
}

#endif
