#include "Archivos.h"
#include "Validaciones.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

void Archivos::asegurarEstructura() {
    fs::create_directories("data/users");
    std::ofstream f("data/usuarios.txt", std::ios::app);
}

std::string Archivos::rutaUsuarioDir(const std::string& id) { return "data/users/" + id; }
std::string Archivos::rutaPerfil(const std::string& id) { return rutaUsuarioDir(id) + "/perfil.txt"; }
std::string Archivos::rutaCuenta(const std::string& id) { return rutaUsuarioDir(id) + "/cuenta.txt"; }
std::string Archivos::rutaTransacciones(const std::string& id) { return rutaUsuarioDir(id) + "/transacciones.txt"; }
std::string Archivos::rutaLogica(const std::string& id) { return rutaUsuarioDir(id) + "/logica_conjuntos.txt"; }

bool Archivos::appendUsuarioRegistro(const Usuario& u) {
    fs::create_directories(rutaUsuarioDir(u.id));
    std::ofstream out("data/usuarios.txt", std::ios::app);
    if (!out) return false;
    out << u.id << "|" << u.nombre << "|" << u.paisRegistro << "|"
        << (u.esExtranjero ? "SI" : "NO") << "|"
        << (u.esExtranjero ? u.numDocumento : u.cedula) << "|"
        << Validaciones::fechaHoraActualISO() << "\n";
    return true;
}

bool Archivos::existeUsuarioRegistro(const std::string& id) {
    std::ifstream in("data/usuarios.txt");
    if (!in) return false;
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string token;
        if (std::getline(iss, token, '|')) {
            if (token == id) return true;
        }
    }
    return false;
}

bool Archivos::cargarPerfil(const std::string& id, Usuario& u) {
    std::ifstream in(rutaPerfil(id));
    if (!in) return false;
    std::string line;
    while (std::getline(in, line)) {
        auto pos = line.find(':');
        if (pos == std::string::npos) continue;
        std::string k = line.substr(0, pos);
        std::string v = line.substr(pos + 1);
        if (k == "id") u.id = v;
        else if (k == "nombre") u.nombre = v;
        else if (k == "pais") u.paisRegistro = v;
        else if (k == "extranjero") u.esExtranjero = (v == "SI");
        else if (k == "cedula") u.cedula = v;
        else if (k == "num_documento") u.numDocumento = v;
    }
    return !u.id.empty();
}

bool Archivos::guardarPerfil(const Usuario& u) {
    fs::create_directories(rutaUsuarioDir(u.id));
    std::ofstream out(rutaPerfil(u.id));
    if (!out) return false;
    out << "id:" << u.id << "\n"
        << "nombre:" << u.nombre << "\n"
        << "pais:" << u.paisRegistro << "\n"
        << "extranjero:" << (u.esExtranjero ? "SI" : "NO") << "\n"
        << "cedula:" << (u.esExtranjero ? "" : u.cedula) << "\n"
        << "num_documento:" << u.numDocumento << "\n";
    return true;
}

bool Archivos::cargarCuenta(const std::string& id, Usuario& u) {
    std::ifstream in(rutaCuenta(id));
    if (!in) return false;
    std::string line;
    while (std::getline(in, line)) {
        auto pos = line.find(':');
        if (pos == std::string::npos) continue;
        std::string k = line.substr(0, pos);
        std::string v = line.substr(pos + 1);
        if (k == "saldo") u.saldo = std::stod(v);
        else if (k == "depositado_hoy") u.totalDepositadoHoy = std::stod(v);
        else if (k == "retirado_hoy") u.totalRetiradoHoy = std::stod(v);
        else if (k == "fecha_resumen") u.fechaUltResumen = v;
    }
    return true;
}

bool Archivos::cargarTransacciones(const std::string& id, Usuario& u) {
    std::ifstream in(rutaTransacciones(id));
    if (!in) return false;
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        Transaccion tx;
        std::getline(iss, tx.idTransaccion, '|');
        std::getline(iss, tx.tipo, '|');
        std::string montoStr;
        std::getline(iss, montoStr, '|');
        tx.monto = std::stod(montoStr);
        std::getline(iss, tx.paisOrigen, '|');
        std::getline(iss, tx.fechaHora, '|');
        std::getline(iss, tx.estado, '|');
        std::getline(iss, tx.motivoFalla, '|');
        std::getline(iss, tx.idDestino, '|');
        u.historialSesion.push_back(tx);
    }
    return true;
}

bool Archivos::cargarLogica(const std::string& id, Usuario& u) {
    std::ifstream in(rutaLogica(id));
    if (!in) return false;
    std::string line;
    while (std::getline(in, line)) {
        EvaluacionLogica eval{};
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, '|')) {
            if (token.rfind("P:",0)==0) eval.P = (token.substr(2)=="1");
            else if (token.rfind("Q:",0)==0) eval.Q = (token.substr(2)=="1");
            else if (token.rfind("R:",0)==0) eval.R = (token.substr(2)=="1");
            else if (token.rfind("Regla:",0)==0) eval.regla = token.substr(6);
            else if (token.rfind("Conjunto:",0)==0) eval.conjunto = token.substr(9)[0];
        }
        u.historialLogico.push_back(eval);
    }
    return true;
}


bool Archivos::guardarCuenta(const Usuario& u) {
    fs::create_directories(rutaUsuarioDir(u.id));
    std::ofstream out(rutaCuenta(u.id));
    if (!out) return false;
    out << std::fixed << std::setprecision(2);
    out << "saldo:" << u.saldo << "\n"
        << "depositado_hoy:" << u.totalDepositadoHoy << "\n"
        << "retirado_hoy:" << u.totalRetiradoHoy << "\n"
        << "fecha_resumen:" << u.fechaUltResumen << "\n";
    return true;
}

bool Archivos::appendTransaccion(const std::string& id, const Transaccion& tx) {
    fs::create_directories(rutaUsuarioDir(id));
    std::ofstream out(rutaTransacciones(id), std::ios::app);
    if (!out) return false;
    out << tx.idTransaccion << "|" << tx.tipo << "|" << std::fixed << std::setprecision(2) << tx.monto
        << "|" << tx.paisOrigen << "|" << tx.fechaHora << "|" << tx.estado
        << "|" << tx.motivoFalla << "|" << tx.idDestino << "\n";
    return true;
}

bool Archivos::appendLogica(const std::string& id, const Transaccion& tx, const EvaluacionLogica& eval) {
    fs::create_directories(rutaUsuarioDir(id));
    std::ofstream out(rutaLogica(id), std::ios::app);
    if (!out) return false;
    out << tx.idTransaccion << "|" << tx.tipo << "|" << std::fixed << std::setprecision(2) << tx.monto
        << "|" << tx.paisOrigen << "|" << tx.fechaHora
        << "|P:" << (eval.P ? "1" : "0")
        << "|Q:" << (eval.Q ? "1" : "0")
        << "|R:" << (eval.R ? "1" : "0")
        << "|Regla:" << eval.regla
        << "|Conjunto:" << eval.conjunto
        << "\n";
    return true;
}
