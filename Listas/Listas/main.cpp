#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ListaSimple.h"
#include "OperacionesCedula.h"
#include <fstream>
#include <regex>
#include <functional>
using namespace std;
int* contarCedulasProvincia(string[], ListaSimple&);
string ingresarCedula(char*);
void ingresar(ListaSimple&);
void cargarArchivo(ListaSimple&);
void guardarArchivo(ListaSimple&);
void cargarProvincias(string[],string[]);
string ingresarDato(const char* msj, function<bool(char, const string&)> validator) {
    cout << msj;
    char c;
    string dato = "";
    while ((c = getch()) != 13) {
        if (validator(c, dato)) {
            cout << c;
            dato += c;
        }
    }
    cout << endl;
    return dato;
}/*bool validarCedulaRegex(string cedula){
    regex patron("^[0-9]{10}$");
    return regex_match(cedula, patron);
}
bool validarCorreo(string correo){
    regex patron("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    return regex_match(correo, patron);
}
bool validarNombreRegex(string nombre){
    regex patron("^[A-Za-z������������]+( [A-Za-z������������]+)+$");
    return regex_match(nombre, patron);
}*/

void guardarArchivo(ListaSimple& ls) {
    ofstream archivo("datos.txt");
    Nodo* aux = ls.getCabeza();
    while (aux) {
        archivo << aux->getCedula() << " " << aux->getNombre() << endl;
        aux = aux->siguiente;
    }
    archivo.close();
    cout << "Datos guardados en datos.txt\n";
}
void cargarArchivo(ListaSimple& ls) {
    ifstream archivo("datos.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return;
    }
    string cedula, nombre;
    while (archivo >> cedula) {
        getline(archivo, nombre);
        if (!nombre.empty() && nombre[0] == ' ')
            nombre = nombre.substr(1);
        OperacionesCedula validador;
        if (validador.validarCedula(cedula) && !ls.buscar(cedula)) {
            ls.insertarFinal(cedula, nombre);
        }
    }
    archivo.close();
    cout << "Datos cargados desde archivo\n";
}
void ingresar(ListaSimple& ls){
    OperacionesCedula validadorCedula;
    string cedula, nombre;
    char opcion;
    do{
        auto cedulaValidator = [](char c, const string& current) -> bool {
            return (c >= '0' && c <= '9') && current.length() < 10;
        };
        cedula = ingresarDato("Ingrese cedula: ", cedulaValidator);
        if(!validadorCedula.validarCedula(cedula)){
            cout << "Cedula invalida\n";
        }
        else if(ls.buscar(cedula)){
            cout << "Esta cedula ya esta ingresada\n";
        }
        else{
            auto nombreValidator = [](char c, const string& current) -> bool {
                return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ';
            };
            nombre = ingresarDato("Ingrese nombre: ", nombreValidator);
            if (nombre.empty()) {
                cout << "Nombre invalido\n";
            }else{
                ls.insertarFinal(cedula, nombre);}
        }
        cout << "Desea ingresar otra persona? (s/n): ";
        cin >> opcion;
    }while(opcion == 's' || opcion == 'S');
}
int* contarCedulasProvincia(string numeroProvincia[], ListaSimple& ls){
    int* conteoProvincias = new int[24];
    for(int i=0;i<24;i++){
        conteoProvincias[i] = 0;
    }
    Nodo* nuevo=ls.getCabeza();
    while(nuevo!=NULL){
        string cedula=nuevo->getCedula();
        string prefijoProvincia=cedula.substr(0,2);
        for(int i=0;i<24;i++){
            if(prefijoProvincia==numeroProvincia[i]){
                conteoProvincias[i]++;
            }
        }
        nuevo=nuevo->siguiente;
    }
    return conteoProvincias;
}
void cargarProvincias(string codigos[], string nombres[]) {
    ifstream archivo("provincias.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir provincias.txt\n";
        return;
    }
    for (int i = 0; i < 24; i++) {
        archivo >> codigos[i];
        archivo.ignore();
        getline(archivo, nombres[i]);
    }
    archivo.close();
}
int main() {
    string numeroProvincia[24];
    string provincias[24];
    ListaSimple ls;
    cargarProvincias(numeroProvincia, provincias);
    cargarArchivo(ls);
    int opcion;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Ingresar personas\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Buscar por cedula\n";
        cout << "4. Eliminar persona\n";
        cout << "5. Contar por provincias\n";
        cout << "6. Guardar datos\n";
        cout << "7. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            ingresar(ls);
            break;
        case 2:
            cout << "\n=====LISTA=====\n";
            ls.mostrar();
            break;
        case 3: {
            auto cedulaValidatorBuscar = [](char c, const string& current) -> bool {
                return (c >= '0' && c <= '9') && current.length() < 10;
            };
            string cedula = ingresarDato("Ingrese cedula a buscar: ", cedulaValidatorBuscar);
            if (ls.buscar(cedula))
                cout << "Cedula encontrada\n";
            else
                cout << "No existe la cedula ingresada\n";
            break;
        }
        case 4: {
            auto cedulaValidatorEliminar = [](char c, const string& current) -> bool {
                return (c >= '0' && c <= '9') && current.length() < 10;
            };
            string cedula = ingresarDato("Ingrese cedula a eliminar: ", cedulaValidatorEliminar);
            ls.eliminar(cedula);
            cout << "Datos pertenecientes a esta cedula eliminados\n";
            break;
        }
        case 5: {
            int* conteoProvincias = contarCedulasProvincia(numeroProvincia, ls);
            cout << "\n====CONTEO POR PROVINCIAS====\n";
            for(int i = 0; i < 24; i++){
                cout << numeroProvincia[i] << " - " << provincias[i]
                     << ": " << conteoProvincias[i] << endl;
            }
            delete[] conteoProvincias;
            break;
        }
        case 6:
            guardarArchivo(ls);
            break;
        case 7:
            guardarArchivo(ls);
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida\n";
        }
    }while(opcion!=7);
    return 0;
}
