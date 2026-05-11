#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>

namespace Validaciones {
    bool soloNumerosDosDecimales(const std::string& s);
    bool esCedulaEcuatorianaValida(const std::string& cedula);
    bool paisValido(const std::string& pais);
    std::string fechaHoraActualISO();
    std::string soloFecha(const std::string& isoDateTime);
    std::string pedirDocumentoValido();
    bool soloLetras(const std::string& s);
    bool primeraMayuscula(const std::string& s);
    bool montoValido(const std::string& s);
    int pedirOpcionValida(int min, int max);
    std::string pedirNombreValido(const std::string& campo);
    double pedirMontoValido();
    std::string pedirCedulaValida();
    std::string pedirIdValido();
}

#endif
