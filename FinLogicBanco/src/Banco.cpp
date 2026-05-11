#include "Banco.h"
#include "Archivos.h"
#include "Validaciones.h"
#include <random>
#include <algorithm>
#include <fstream>


Banco::Banco() {
    Archivos::asegurarEstructura();
}

bool Banco::registrarUsuario(const std::string& nombre, bool esExtranjero,
                             const std::string& pais, const std::string& cedula,
                             const std::string& numDocumento,
                             std::string& idGenerado, std::string& error) {
    Usuario u;
    u.nombre = nombre;
    u.esExtranjero = esExtranjero;
    u.paisRegistro = esExtranjero ? pais : "Ecuador";
    u.saldo = 0.0;
    u.totalDepositadoHoy = 0.0;
    u.totalRetiradoHoy = 0.0;
    u.fechaUltResumen = Validaciones::soloFecha(Validaciones::fechaHoraActualISO());

    if (esExtranjero) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<long long> dist(1000000000LL, 9999999999LL); // 10 dígitos
    do {
        idGenerado = std::to_string(dist(rng));
    } while (Archivos::existeUsuarioRegistro(idGenerado));
    u.id = idGenerado;
    u.cedula = "";
    u.numDocumento = numDocumento;
} else {
        if (!Validaciones::esCedulaEcuatorianaValida(cedula)) {
            error = "Cedula ecuatoriana invalida";
            return false;
        }
        idGenerado = cedula;
        if (Archivos::existeUsuarioRegistro(idGenerado)) {
            error = "Usuario ya existe";
            return false;
        }
        u.id = idGenerado;
        u.cedula = cedula;
    }

    if (!Archivos::appendUsuarioRegistro(u)) {
        error = "No se pudo escribir en usuarios.txt";
        return false;
    }
    if (!Archivos::guardarPerfil(u) || !Archivos::guardarCuenta(u)) {
        error = "No se pudo guardar perfil/cuenta";
        return false;
    }

    std::ofstream(Archivos::rutaTransacciones(u.id)).close();
    std::ofstream(Archivos::rutaLogica(u.id)).close();

    cachearUsuario(u);
    return true;
}

bool Banco::existeUsuario(const std::string& id) const {
    return const_cast<Banco*>(this)->obtenerUsuarioCache(id) != nullptr || Archivos::existeUsuarioRegistro(id);
}

bool Banco::cargarUsuario(const std::string& id, Usuario& usuario) {
    if (auto* u = obtenerUsuarioCache(id)) {
        usuario = *u;
        return true;
    }
    Usuario u;
    if (!Archivos::cargarPerfil(id, u)) return false;
    Archivos::cargarCuenta(id, u);
    Archivos::cargarTransacciones(id, u);
    Archivos::cargarLogica(id, u);
    usuario = u;
    cachearUsuario(usuario);
    return true;
}

bool Banco::guardarUsuario(const Usuario& usuario) {
    return Archivos::guardarPerfil(usuario) && Archivos::guardarCuenta(usuario);
}

Usuario* Banco::obtenerUsuarioCache(const std::string& id) {
    auto it = cache.find(id);
    if (it != cache.end()) return &it->second;
    return nullptr;
}

void Banco::cachearUsuario(const Usuario& usuario) {
    cache[usuario.id] = usuario;
}

void Banco::limpiarCache() {
    cache.clear();
}

EvaluacionLogica Banco::evaluarTransaccion(const Usuario& usuario,
                                           const Transaccion& tx,
                                           const std::vector<Transaccion>& ultimasTransacciones,
                                           const std::string& paisRegistro) {
    EvaluacionLogica e{};
     if (tx.tipo == "RETIRO" || tx.tipo == "TRANSFERENCIA") {
        double tentativa = usuario.totalRetiradoHoy + tx.monto;
        e.P = (tentativa > LIMITE_DIARIO);
    } else {
        e.P = false;
    }
    e.Q = (tx.paisOrigen != paisRegistro);

    int countVentana = 0;
    countVentana = static_cast<int>(ultimasTransacciones.size());
    e.R = (countVentana + 1 > 3);

    bool P = e.P;
    bool Q = e.Q;
    bool R = e.R;

    if (!P && !Q) {
        e.regla = "NORMAL";
        e.conjunto = 'A';
    } else if (P && Q && R) {
        e.regla = "ALTO_RIESGO";
        e.conjunto = 'C';
    } else if ((P && Q) || (!P && Q && R) || (P && !Q) || (P && !Q && R)) {
        e.regla = "SOSPECHOSA";
        e.conjunto = 'B';
    } else {
        e.regla = "SOSPECHOSA";
        e.conjunto = 'B';
    }

    return e;
}
