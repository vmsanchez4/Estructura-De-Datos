#include "Usuario.h"
#include "Validaciones.h"
#include "Banco.h"
#include <random>
#include <sstream>

Usuario::Usuario()
    : esExtranjero(false), saldo(0.0),
      totalDepositadoHoy(0.0), totalRetiradoHoy(0.0) {}

std::string Usuario::generarIdTransaccion() const {
    static std::mt19937_64 rng(std::random_device{}());
    static std::uniform_int_distribution<unsigned long long> dist;
    unsigned long long r = dist(rng);
    std::ostringstream oss;
    oss << "TX-" << r;
    return oss.str();
}

void Usuario::resetearResumenSiCambioDia(const std::string& fechaActualISODate) {
    if (fechaUltResumen != fechaActualISODate) {
        totalDepositadoHoy = 0.0;
        totalRetiradoHoy = 0.0;
        fechaUltResumen = fechaActualISODate;
    }
}

bool Usuario::depositar(double monto, const std::string& pais, std::string& motivoFalla, EvaluacionLogica& eval) {
    Transaccion tx;
    tx.idTransaccion = generarIdTransaccion();
    tx.tipo = "DEPOSITO";
    tx.monto = monto;
    tx.paisOrigen = pais;
    tx.fechaHora = Validaciones::fechaHoraActualISO();
    tx.estado = "FALLIDA";

    resetearResumenSiCambioDia(Validaciones::soloFecha(tx.fechaHora));

    double tentativaDepositos = totalDepositadoHoy + monto;
    eval.P = (tentativaDepositos > Banco::LIMITE_DIARIO);
    eval.Q = (pais != paisRegistro);

    if (!Validaciones::paisValido(pais)) {
        motivoFalla = "Pais invalido";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }

    saldo += monto;
    totalDepositadoHoy += monto;
    tx.estado = "EXITOSA";
    historialSesion.push_back(tx);
    return true;
}

bool Usuario::retirar(double monto, const std::string& pais, std::string& motivoFalla, EvaluacionLogica& eval) {
    Transaccion tx;
    tx.idTransaccion = generarIdTransaccion();
    tx.tipo = "RETIRO";
    tx.monto = monto;
    tx.paisOrigen = pais;
    tx.fechaHora = Validaciones::fechaHoraActualISO();
    tx.estado = "FALLIDA";

    resetearResumenSiCambioDia(Validaciones::soloFecha(tx.fechaHora));

    double tentativaRetiros = totalRetiradoHoy + monto;
    eval.P = (tentativaRetiros > Banco::LIMITE_DIARIO);
    eval.Q = (pais != paisRegistro);

    if (!Validaciones::paisValido(pais)) {
        motivoFalla = "Pais invalido";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }
    if (monto > saldo) {
        motivoFalla = "Saldo insuficiente";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }
    if (tentativaRetiros > Banco::LIMITE_DIARIO) {
        motivoFalla = "Excede limite diario";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }

    saldo -= monto;
    totalRetiradoHoy += monto;
    tx.estado = "EXITOSA";
    historialSesion.push_back(tx);
    return true;
}

bool Usuario::transferirA(Usuario& destino, double monto, const std::string& pais,
                          std::string& motivoFalla, EvaluacionLogica& eval) {
    Transaccion tx;
    tx.idTransaccion = generarIdTransaccion();
    tx.tipo = "TRANSFERENCIA";
    tx.monto = monto;
    tx.paisOrigen = pais;
    tx.fechaHora = Validaciones::fechaHoraActualISO();
    tx.estado = "FALLIDA";
    tx.idDestino = destino.id;

    resetearResumenSiCambioDia(Validaciones::soloFecha(tx.fechaHora));

    double tentativaRetiros = totalRetiradoHoy + monto;
    eval.P = (tentativaRetiros > Banco::LIMITE_DIARIO);
    eval.Q = (pais != paisRegistro);

    if (!Validaciones::paisValido(pais)) {
        motivoFalla = "Pais invalido";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }
    if (monto > saldo) {
        motivoFalla = "Saldo insuficiente";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }
    if (tentativaRetiros > Banco::LIMITE_DIARIO) {
        motivoFalla = "Excede limite diario";
        tx.motivoFalla = motivoFalla;
        historialSesion.push_back(tx);
        return false;
    }

    saldo -= monto;
    totalRetiradoHoy += monto;
    tx.estado = "EXITOSA";
    historialSesion.push_back(tx);

    destino.saldo += monto;
    destino.totalDepositadoHoy += monto;

    Transaccion txDestino;
    txDestino.idTransaccion = tx.idTransaccion;
    txDestino.tipo = "TRANSFERENCIA_RECIBIDA";
    txDestino.monto = monto;
    txDestino.paisOrigen = pais;
    txDestino.fechaHora = tx.fechaHora;
    txDestino.estado = "EXITOSA";
    txDestino.idDestino = id;
    destino.historialSesion.push_back(txDestino);

    return true;
}
