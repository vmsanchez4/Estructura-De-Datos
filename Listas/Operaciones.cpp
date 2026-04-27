#include "Operaciones.h"
#include <iostream>
#include <string>

using namespace std;

void registrarDatoTDA(ListaBase* listaPuntero) {
    string tempNombre;
    string tempCedula;

    cout << "\nIngrese el nombre: ";
    cin.ignore();
    getline(cin, tempNombre);

    cout << "Ingrese la cedula: ";
    cin >> tempCedula;

    if (listaPuntero->buscar(tempCedula)) {
        cout << "Error: La cedula ya esta registrada." << endl;
        return;
    }

    // Instanciacion con polimorfismo
    Persona* nuevaPersona = new Persona(tempNombre, tempCedula);
    listaPuntero->insertar(nuevaPersona);
    
    cout << "Guardado correctamente. Total en esta lista: " << listaPuntero->getTamanio() << endl;
}

void eliminarDatoTDA(ListaBase* listaPuntero) {
    string tempCedula;
    cout << "\nIngrese la cedula a eliminar: ";
    cin >> tempCedula;

    if (listaPuntero->buscar(tempCedula)) {
        listaPuntero->eliminar(tempCedula);
        cout << "Dato eliminado. Nuevo tamanio: " << listaPuntero->getTamanio() << endl;
    } else {
        cout << "No se encontro la cedula." << endl;
    }
}