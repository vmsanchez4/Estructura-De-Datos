#include "Validaciones.h"
#include <iostream>
#include <regex>
#include <cctype>
#include <limits>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>

namespace Validaciones {

bool soloNumerosDosDecimales(const std::string& s) {
    static const std::regex re(R"(^[0-9]+(\.[0-9]{1,2})?$)");
    return std::regex_match(s, re);
}

bool esCedulaEcuatorianaValida(const std::string& cedula) {
    if (cedula.size() != 10) return false;
    if (!std::all_of(cedula.begin(), cedula.end(), ::isdigit)) return false;

    int provincia = std::stoi(cedula.substr(0, 2));
    if (provincia < 1 || provincia > 24) return false;

    int tercer = cedula[2] - '0';
    if (tercer >= 6) return false;

    int coef[9] = {2,1,2,1,2,1,2,1,2};
    int suma = 0;
    for (int i = 0; i < 9; ++i) {
        int dig = cedula[i] - '0';
        int res = dig * coef[i];
        if (res >= 10) res -= 9;
        suma += res;
    }
    int verificador = (10 - (suma % 10)) % 10;
    return verificador == (cedula[9] - '0');
}

bool paisValido(const std::string& pais) {
    return soloLetras(pais) && primeraMayuscula(pais);
}

std::string fechaHoraActualISO() {
    std::time_t t = std::time(nullptr);
    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    tm = *std::localtime(&t);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
    return oss.str();
}

std::string soloFecha(const std::string& isoDateTime) {
    if (isoDateTime.size() >= 10) return isoDateTime.substr(0, 10);
    return isoDateTime;
}

bool soloLetras(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ')
            return false;
    }
    return true;
}

bool primeraMayuscula(const std::string& s) {
    if (s.empty()) return false;
    return std::isupper(static_cast<unsigned char>(s[0]));
}

bool montoValido(const std::string& s) {
    std::regex re("^[0-9]+(\\.[0-9]{1,2})?$");
    return std::regex_match(s, re);
}

int pedirOpcionValida(int min, int max) {
    std::string entrada;
    int op;
    while (true) {
        std::cout << "Seleccion: ";
        if (!std::getline(std::cin, entrada)) {
            std::cin.clear();
            continue;
        }
        try {
            op = std::stoi(entrada);
            if (op >= min && op <= max) return op;
        } catch (...) {
        }
        std::cout << "Error: opcion invalida. Intente de nuevo.\n";
    }
}

std::string pedirNombreValido(const std::string& campo) {
    std::string valor;
    while (true) {
        std::cout << campo << ": ";
        std::getline(std::cin, valor);
        if (soloLetras(valor) && primeraMayuscula(valor)) return valor;
        std::cout << "Error: solo letras y primera mayuscula.\n";
    }
}

double pedirMontoValido() {
    std::string entrada;
    while (true) {
        std::cout << "Monto: ";
        std::getline(std::cin, entrada);
        if (montoValido(entrada)) return std::stod(entrada);
        std::cout << "Error: ingrese un monto numerico con maximo 2 decimales.\n";
    }
}

std::string pedirCedulaValida() {
    std::string cedula;
    while (true) {
        std::cout << "Cedula: ";
        std::getline(std::cin, cedula);
        if (esCedulaEcuatorianaValida(cedula)) return cedula;
        std::cout << "Error: cedula invalida.\n";
    }
}

std::string pedirDocumentoValido() {
    std::string doc;
    while (true) {
        std::cout << "Numero de documento/pasaporte: ";
        std::getline(std::cin, doc);
        if (doc.empty()) { std::cout << "Error: no puede estar vacio.\n"; continue; }
        if (doc.size() < 4 || doc.size() > 20) { std::cout << "Error: longitud invalida (4-20 caracteres).\n"; continue; }
        bool valido = true;
        for (char c : doc)
            if (!isalnum(static_cast<unsigned char>(c)) && c != '-') { valido = false; break; }
        if (!valido) { std::cout << "Error: solo letras, numeros y guion.\n"; continue; }
        return doc;
    }
}

std::string pedirIdValido() {
    std::string id;
    while (true) {
        std::cout << "ID: ";
        std::getline(std::cin, id);
        if (!id.empty()) {
            bool valido = true;
            for (char c : id) {
                if (!isalnum(static_cast<unsigned char>(c))) {
                    valido = false;
                    break;
                }
            }
            if (valido) return id;
        }
        std::cout << "Error: ID invalido, ingrese solo letras/numeros.\n";
    }
}

} // namespace Validaciones
