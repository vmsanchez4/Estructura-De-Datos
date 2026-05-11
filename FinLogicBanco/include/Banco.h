#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Usuario.h"

class Banco {
public:
    static constexpr double LIMITE_DIARIO = 200.0;

    Banco();

    bool registrarUsuario(const std::string& nombre, bool esExtranjero,
                      const std::string& pais, const std::string& cedula,
                      const std::string& numDocumento,
                      std::string& idGenerado, std::string& error);

    bool existeUsuario(const std::string& id) const;
    bool cargarUsuario(const std::string& id, Usuario& usuario);
    bool guardarUsuario(const Usuario& usuario);

    Usuario* obtenerUsuarioCache(const std::string& id);
    void cachearUsuario(const Usuario& usuario);
    void limpiarCache();

    EvaluacionLogica evaluarTransaccion(const Usuario& usuario,
                                        const Transaccion& tx,
                                        const std::vector<Transaccion>& ultimasTransacciones,
                                        const std::string& paisRegistro);

private:
    std::unordered_map<std::string, Usuario> cache;
};

#endif
