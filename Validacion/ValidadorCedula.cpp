#include "ValidadorCedula.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static const string ARCHIVO_CEDULAS = "cedulas.txt";
static const string ARCHIVO_PROVINCIAS = "provincias.txt";

ValidadorCedula::ValidadorCedula() : cabeza(nullptr) {
    // Cargar los datos que ya existan en el archivo.
    cargarDesdeArchivo(ARCHIVO_CEDULAS);
}

ValidadorCedula::~ValidadorCedula() {
    liberarMemoria();
}

void ValidadorCedula::registrarCedula(const string& numero, const string& nombre) {
    Nodo* nuevo = new Nodo(numero, nombre, nullptr);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* temp = cabeza;
        while (temp->getSiguiente()) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
    }
}

void ValidadorCedula::liberarMemoria() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}

bool ValidadorCedula::existeCedula(const string& cedula) const {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->getCedula() == cedula) {
            return true;
        }
        temp = temp->getSiguiente();
    }
    return false;
}

bool ValidadorCedula::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        size_t separador = linea.find(',');
        if (separador == string::npos) {
            continue;
        }

        string cedula = linea.substr(0, separador);
        string nombre = linea.substr(separador + 1);

        if (cedula.length() == 10 && !existeCedula(cedula)) {
            registrarCedula(cedula, nombre);
        }
    }

    archivo.close();
    return true;
}

bool ValidadorCedula::guardarRegistroEnArchivo(const string& cedula, const string& nombre) const {
    ofstream archivo(ARCHIVO_CEDULAS, ios::app);
    if (!archivo.is_open()) {
        return false;
    }

    archivo << cedula << "," << nombre << "\n";
    archivo.close();
    return true;
}

void ValidadorCedula::reescribirArchivo() const {
    ofstream archivo(ARCHIVO_CEDULAS, ios::trunc);
    if (!archivo.is_open()) {
        return;
    }

    Nodo* temp = cabeza;
    while (temp) {
        archivo << temp->getCedula() << "," << temp->getNombre() << "\n";
        temp = temp->getSiguiente();
    }

    archivo.close();
}

bool ValidadorCedula::validar(string cedula) {
    if (cedula.length() != 10) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (!isdigit(cedula[i])) {
            return false;
        }
    }
    
    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        int producto = digito * coeficientes[i];
        
        if (producto > 9) {
            producto -= 9;
        }
        suma += producto;
    }
    
    int residuo = suma % 10;
    int verificadorCalculado = (residuo == 0) ? 0 : 10 - residuo;
    int verificadorReal = cedula[9] - '0';

    return verificadorCalculado == verificadorReal;
}

bool ValidadorCedula::agregarRegistro(const string& cedula, const string& nombre) {
    if (!validar(cedula)) {
        return false;
    }

    if (existeCedula(cedula)) {
        return false;
    }

    registrarCedula(cedula, nombre);
    guardarRegistroEnArchivo(cedula, nombre);
    return true;
}

bool ValidadorCedula::buscarCedula(const string& cedula) const {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->getCedula() == cedula) {
            return true;
        }
        temp = temp->getSiguiente();
    }
    return false;
}

bool ValidadorCedula::eliminarCedula(const string& cedula) {
    if (!cabeza) {
        return false;
    }

    if (cabeza->getCedula() == cedula) {
        Nodo* eliminado = cabeza;
        cabeza = cabeza->getSiguiente();
        delete eliminado;
        reescribirArchivo();
        return true;
    }

    Nodo* temp = cabeza;
    while (temp->getSiguiente() && temp->getSiguiente()->getCedula() != cedula) {
        temp = temp->getSiguiente();
    }

    if (!temp->getSiguiente()) {
        return false;
    }

    Nodo* eliminado = temp->getSiguiente();
    temp->setSiguiente(eliminado->getSiguiente());
    delete eliminado;
    reescribirArchivo();
    return true;
}

void ValidadorCedula::mostrarRegistros() const {
    if (!cabeza) {
        cout << "\nNo hay cedulas registradas" << endl;
        return;
    }

    cout << "\n--- Listado de Cedulas Registradas ---" << endl;
    Nodo* temp = cabeza;
    while (temp) {
        cout << "Cedula: " << temp->getCedula() << " | Nombre: " << temp->getNombre() << endl;
        temp = temp->getSiguiente();
    }
}

void ValidadorCedula::contarPorProvincia() {
    vector<string> codigos;
    vector<string> nombres;
    vector<int> cantidades;

    ifstream archivoProv(ARCHIVO_PROVINCIAS);
    if (!archivoProv.is_open()) {
        cout << "\nNo se encontro el archivo de provincias" << endl;
        return;
    }

    string lineaProv;
    while (getline(archivoProv, lineaProv)) {
        if (lineaProv.empty()) {
            continue;
        }

        size_t separadorProv = lineaProv.find(',');
        if (separadorProv == string::npos) {
            continue;
        }

        string codigoProv = lineaProv.substr(0, separadorProv);
        string nombreProv = lineaProv.substr(separadorProv + 1);
        if (!codigoProv.empty() && !nombreProv.empty()) {
            codigos.push_back(codigoProv);
            nombres.push_back(nombreProv);
            cantidades.push_back(0);
        }
    }

    archivoProv.close();

    if (codigos.empty()) {
        cout << "\nNo hay provincias definidas en el archivo de provincias" << endl;
        return;
    }

    ifstream archivo(ARCHIVO_CEDULAS);
    if (!archivo.is_open()) {
        cout << "\nNo se encontro el archivo de cedulas para contar por provincia" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        size_t separador = linea.find(',');
        if (separador == string::npos || separador < 2) {
            continue;
        }

        string cedula = linea.substr(0, separador);
        if (cedula.length() < 2) {
            continue;
        }

        string codigo = cedula.substr(0, 2);
        for (size_t i = 0; i < codigos.size(); i++) {
            if (codigos[i] == codigo) {
                cantidades[i]++;
                break;
            }
        }
    }

    archivo.close();

    cout << "\n--- Conteo de Cedulas por Provincia ---" << endl;
    bool algunaProvincia = false;
    for (size_t i = 0; i < codigos.size(); i++) {
        if (cantidades[i] > 0) {
            cout << nombres[i] << ": " << cantidades[i] << endl;
            algunaProvincia = true;
        }
    }

    if (!algunaProvincia) {
        cout << "No hay cedulas registradas en ningun provincia" << endl;
    }
}

