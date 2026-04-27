#include "Operaciones.h"
#include <iostream>

void registrarPersona(ListaBase* lista) {
    string n, c;
    cout << "Nombre: "; cin.ignore(); getline(cin, n);
    cout << "Cedula: "; cin >> c;
    if (lista->buscar(c)) cout << "Error: Ya existe." << endl;
    else { lista->insertar(new Persona(n, c)); cout << "Guardado." << endl; }
}

void modificarPersona(ListaBase* lista) {
    string c, n;
    cout << "Cedula a modificar: "; cin >> c;
    if (lista->buscar(c)) {
        cout << "Nuevo nombre: "; cin.ignore(); getline(cin, n);
        lista->modificar(c, n); cout << "Actualizado." << endl;
    } else cout << "No encontrado." << endl;
}

void eliminarPersona(ListaBase* lista) {
    string c;
    cout << "Cedula a eliminar: "; cin >> c;
    if (lista->buscar(c)) { lista->eliminar(c); cout << "Eliminado." << endl; }
    else cout << "No encontrado." << endl;
}