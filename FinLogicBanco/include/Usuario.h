#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

struct Transaccion {
    std::string idTransaccion;
    std::string tipo;
    double monto;
    std::string paisOrigen;
    std::string fechaHora;
    std::string estado;
    std::string motivoFalla;
    std::string idDestino;
};

struct EvaluacionLogica {
    bool P;
    bool Q;
    bool R;
    std::string regla;
    char conjunto;
};

class Usuario {
public:
    std::string id;
    std::string nombre;
    std::string paisRegistro;
    bool esExtranjero;
    std::string cedula;
    std::string numDocumento;
    double saldo;

    double totalDepositadoHoy;
    double totalRetiradoHoy;
    std::string fechaUltResumen;

    std::vector<Transaccion> historialSesion;
    std::vector<EvaluacionLogica> historialLogico;

    Usuario();

    bool depositar(double monto, const std::string& pais, std::string& motivoFalla, EvaluacionLogica& eval);
    bool retirar(double monto, const std::string& pais, std::string& motivoFalla, EvaluacionLogica& eval);
    bool transferirA(Usuario& destino, double monto, const std::string& pais, std::string& motivoFalla, EvaluacionLogica& eval);

    void resetearResumenSiCambioDia(const std::string& fechaActualISODate);
    std::string generarIdTransaccion() const;
};

#endif
