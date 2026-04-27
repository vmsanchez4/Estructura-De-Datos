#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

Menu::Menu() {
    void* ms = malloc(sizeof(ListaSimple<Persona>));
    listaSimple = new (ms) ListaSimple<Persona>();

    void* md = malloc(sizeof(ListaDoble<Persona>));
    listaDoble = new (md) ListaDoble<Persona>();

    void* mc = malloc(sizeof(ListaCircular<Persona>));
    listaCircular = new (mc) ListaCircular<Persona>();
}

Menu::~Menu() {
    listaSimple->~ListaSimple();   free(listaSimple);
    listaDoble->~ListaDoble();     free(listaDoble);
    listaCircular->~ListaCircular(); free(listaCircular);
}

Persona* Menu::pedirPersona() const {
    string nombre, cedula;
    cout << "\n  Nombre : "; cin.ignore(); getline(cin, nombre);
    cout << "  Cedula : ";               getline(cin, cedula);
    void* mem = malloc(sizeof(PersonaConcreta));
    if (!mem) { cout << "  [ERROR] malloc fallo." << endl; return nullptr; }
    return new (mem) PersonaConcreta(nombre, cedula);
}

string Menu::pedirCedula() const {
    string c;
    cout << "\n  Cedula: "; cin.ignore(); getline(cin, c);
    return c;
}

void Menu::submenuSimple() const {
    int op = 0;
    do {
        cout << "\n  --- LISTA SIMPLE ---\n"
             << "  1. Insertar\n  2. Eliminar\n  3. Mostrar\n  4. Buscar\n  0. Volver\n"
             << "  Opcion: ";
        cin >> op;
        if      (op == 1) { Persona* p = pedirPersona(); if (p) listaSimple->insertar(p); }
        else if (op == 2) { listaSimple->eliminar(pedirCedula()); }
        else if (op == 3) { listaSimple->mostrar(); }
        else if (op == 4) { if (!listaSimple->buscar(pedirCedula())) cout << "  [!] No encontrado.\n"; }
    } while (op != 0);
}

void Menu::submenuDoble() const {
    int op = 0;
    do {
        cout << "\n  --- LISTA DOBLE ---\n"
             << "  1. Insertar\n  2. Eliminar\n  3. Mostrar\n  4. Mostrar Inverso\n  5. Buscar\n  0. Volver\n"
             << "  Opcion: ";
        cin >> op;
        if      (op == 1) { Persona* p = pedirPersona(); if (p) listaDoble->insertar(p); }
        else if (op == 2) { listaDoble->eliminar(pedirCedula()); }
        else if (op == 3) { listaDoble->mostrar(); }
        else if (op == 4) { listaDoble->mostrarInverso(); }
        else if (op == 5) { if (!listaDoble->buscar(pedirCedula())) cout << "  [!] No encontrado.\n"; }
    } while (op != 0);
}

void Menu::submenuCircular() const {
    int op = 0;
    do {
        cout << "\n  --- LISTA CIRCULAR ---\n"
             << "  1. Insertar\n  2. Eliminar\n  3. Mostrar\n  4. Recorrer N vueltas\n  5. Buscar\n  0. Volver\n"
             << "  Opcion: ";
        cin >> op;
        if      (op == 1) { Persona* p = pedirPersona(); if (p) listaCircular->insertar(p); }
        else if (op == 2) { listaCircular->eliminar(pedirCedula()); }
        else if (op == 3) { listaCircular->mostrar(); }
        else if (op == 4) { int v; cout << "  Vueltas: "; cin >> v; listaCircular->recorrerVueltas(v); }
        else if (op == 5) { if (!listaCircular->buscar(pedirCedula())) cout << "  [!] No encontrado.\n"; }
    } while (op != 0);
}

void Menu::ejecutar() {
    int op = 0;
    do {
        cout << "\n  ==========================================\n"
             << "   LISTAS ENLAZADAS - POO + Template + malloc\n"
             << "  ==========================================\n"
             << "  1. Lista Simple\n"
             << "  2. Lista Doble\n"
             << "  3. Lista Circular\n"
             << "  4. Mostrar TODAS\n"
             << "  0. Salir\n"
             << "  Opcion: ";
        cin >> op;
        switch (op) {
        case 1: submenuSimple();   break;
        case 2: submenuDoble();    break;
        case 3: submenuCircular(); break;
        case 4:
            listaSimple->mostrar();
            listaDoble->mostrar();
            listaCircular->mostrar();
            break;
        case 0: cout << "\n  Saliendo... memoria liberada con free().\n"; break;
        default: cout << "  [!] Opcion invalida.\n";
        }
    } while (op != 0);
}
