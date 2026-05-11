#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include <conio.h>
#include "ValidadorCedula.h"

using namespace std;

static const auto validarCedulaRegex = [] (const string& cedula) -> bool {
    static const regex patron("^[0-9]{10}$");
    return regex_match(cedula, patron);
};

static const auto esDigito = [] (int c) -> bool {
    return c >= '0' && c <= '9';
};

static const auto esDigitoMenuValido = [] (int c) -> bool {
    return c >= '1' && c <= '6';
};

static const auto esLetraOEspacio = [] (int c) -> bool {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ';
};

string leerSoloDigitos() {
    string input;
    int c = 0;

    while (true) {
        c = _getch();
        if (c == 13) { // Enter
            break;
        }
        if (c == 8) { // Backspace
            if (!input.empty()) {
                input.pop_back();
                cout << "\b \b";
            }
            continue;
        }
        if (esDigito(c)) {
            if (input.length() < 10) {
                input.push_back(static_cast<char>(c));
                cout << static_cast<char>(c);
            }
        }
    }
    cout << endl;
    return input;
}

string leerNombreSoloLetras() {
    string nombre;
    int c = 0;

    while (true) {
        c = _getch();
        if (c == 13) { // Enter
            break;
        }
        if (c == 8) { // Backspace
            if (!nombre.empty()) {
                nombre.pop_back();
                cout << "\b \b";
            }
            continue;
        }

        if (esLetraOEspacio(c)) {
            nombre.push_back(static_cast<char>(c));
            cout << static_cast<char>(c);
        }
    }
    cout << endl;
    return nombre;
}

int leerOpcionMenu() {
    int c = 0;
    while (true) {
        c = _getch();
        if (c == 13) { // Enter
            continue;
        }
        if (esDigitoMenuValido(c)) {
            cout << static_cast<char>(c) << endl;
            return c - '0';
        }
    }
}

int main() {
    //No utilizar Corchetes
    ValidadorCedula* validador = new ValidadorCedula();
    int opcion = 0;
    string cedula;
    string nombre;

    do {
        cout << "\n--- MENU DE VALIDACION DE CEDULAS ---" << endl;
        cout << "1. Registrar cedula y nombre" << endl;
        cout << "2. Buscar cedula en el listado" << endl;
        cout << "3. Mostrar todas las cedulas registradas" << endl;
        cout << "4. Contar cedulas por provincia" << endl;
        cout << "5. Eliminar cedula" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        opcion = leerOpcionMenu();

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero de cedula: ";
                cedula = leerSoloDigitos();
                if (cedula.length() != 10 || !validarCedulaRegex(cedula)) {
                    cout << "Cedula invalida. Debe contener exactamente 10 digitos numericos." << endl;
                    break;
                }

                cout << "Ingrese el nombre completo: ";
                nombre = leerNombreSoloLetras();

                if (validador->agregarRegistro(cedula, nombre)) {
                    cout << "Cedula registrada correctamente" << endl;
                } else if (validador->buscarCedula(cedula)) {
                    cout << "La cedula ya existe en el listado" << endl;
                } else {
                    cout << "Cedula invalida" << endl;
                }
                break;

            case 2:
                cout << "Ingrese la cedula a buscar: ";
                cedula = leerSoloDigitos();

                if (validador->buscarCedula(cedula)) {
                    cout << "La cedula " << cedula << " se encuentra en el listado." << endl;
                } else {
                    cout << "La cedula " << cedula << " NO se encuentra en el listado." << endl;
                }
                break;

            case 3:
                validador->mostrarRegistros();
                break;

            case 4:
                validador->contarPorProvincia();
                break;

            case 5:
                cout << "Ingrese la cedula a eliminar: ";
                cedula = leerSoloDigitos();

                if (validador->eliminarCedula(cedula)) {
                    cout << "Cedula eliminada correctamente." << endl;
                } else {
                    cout << "No se encontro la cedula para eliminar." << endl;
                }
                break;

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

    delete validador;
    return 0;
}