#include "../headers/Menu.h"
#include <iostream>
#include <cstdlib>   // malloc, free
#include <new>       // placement new
using namespace std;

// ============================================================
//  IMPLEMENTACION - Menu
//  Las listas usan malloc internamente via Nodo<T>::crear()
// ============================================================

// ---- Constructor: aloja las listas con malloc ----
Menu::Menu() {
    // Reservar memoria para ListaSimple con malloc
    void* memS = malloc(sizeof(ListaSimple<Persona>));
    listaSimple = new (memS) ListaSimple<Persona>();

    // Reservar memoria para ListaDoble con malloc
    void* memD = malloc(sizeof(ListaDoble<Persona>));
    listaDoble = new (memD) ListaDoble<Persona>();

    // Reservar memoria para ListaCircular con malloc
    void* memC = malloc(sizeof(ListaCircular<Persona>));
    listaCircular = new (memC) ListaCircular<Persona>();
}

// ---- Destructor: destruir y liberar con free ----
Menu::~Menu() {
    listaSimple->~ListaSimple();
    free(listaSimple);

    listaDoble->~ListaDoble();
    free(listaDoble);

    listaCircular->~ListaCircular();
    free(listaCircular);
}

// ---- Pedir datos al usuario y crear PersonaConcreta con malloc ----
Persona* Menu::pedirPersona() const {
    string nombre, cedula;
    cout << "\n  Nombre : ";
    cin.ignore();
    getline(cin, nombre);
    cout << "  Cedula : ";
    getline(cin, cedula);

    // Alojar PersonaConcreta con malloc + placement new
    void* mem = malloc(sizeof(PersonaConcreta));
    if (mem == nullptr) {
        cout << "  [ERROR] malloc fallo." << endl;
        return nullptr;
    }
    // Construir en memoria cruda => retorna puntero polimorfico
    Persona* p = new (mem) PersonaConcreta(nombre, cedula);
    return p;
}

string Menu::pedirCedula() const {
    string c;
    cout << "\n  Ingrese cedula: ";
    cin.ignore();
    getline(cin, c);
    return c;
}

// ---- Submenu Lista Simple ----
void Menu::submenuSimple() const {
    int op = 0;
    do {
        cout << "\n  ------ LISTA SIMPLE ------" << endl;
        cout << "  1. Insertar" << endl;
        cout << "  2. Eliminar" << endl;
        cout << "  3. Mostrar" << endl;
        cout << "  4. Buscar" << endl;
        cout << "  0. Volver" << endl;
        cout << "  Opcion: ";
        cin >> op;

        if (op == 1) {
            Persona* p = pedirPersona();
            if (p) listaSimple->insertar(p);
        } else if (op == 2) {
            string c = pedirCedula();
            listaSimple->eliminar(c);
        } else if (op == 3) {
            listaSimple->mostrar();
        } else if (op == 4) {
            string c = pedirCedula();
            if (!listaSimple->buscar(c))
                cout << "  [!] No encontrado." << endl;
        }
    } while (op != 0);
}

// ---- Submenu Lista Doble ----
void Menu::submenuDoble() const {
    int op = 0;
    do {
        cout << "\n  ------ LISTA DOBLE ------" << endl;
        cout << "  1. Insertar" << endl;
        cout << "  2. Eliminar" << endl;
        cout << "  3. Mostrar (cabeza -> cola)" << endl;
        cout << "  4. Mostrar Inverso (cola -> cabeza)" << endl;
        cout << "  5. Buscar" << endl;
        cout << "  0. Volver" << endl;
        cout << "  Opcion: ";
        cin >> op;

        if (op == 1) {
            Persona* p = pedirPersona();
            if (p) listaDoble->insertar(p);
        } else if (op == 2) {
            string c = pedirCedula();
            listaDoble->eliminar(c);
        } else if (op == 3) {
            listaDoble->mostrar();
        } else if (op == 4) {
            listaDoble->mostrarInverso();
        } else if (op == 5) {
            string c = pedirCedula();
            if (!listaDoble->buscar(c))
                cout << "  [!] No encontrado." << endl;
        }
    } while (op != 0);
}

// ---- Submenu Lista Circular ----
void Menu::submenuCircular() const {
    int op = 0;
    do {
        cout << "\n  ------ LISTA CIRCULAR ------" << endl;
        cout << "  1. Insertar" << endl;
        cout << "  2. Eliminar" << endl;
        cout << "  3. Mostrar" << endl;
        cout << "  4. Recorrer N vueltas" << endl;
        cout << "  5. Buscar" << endl;
        cout << "  0. Volver" << endl;
        cout << "  Opcion: ";
        cin >> op;

        if (op == 1) {
            Persona* p = pedirPersona();
            if (p) listaCircular->insertar(p);
        } else if (op == 2) {
            string c = pedirCedula();
            listaCircular->eliminar(c);
        } else if (op == 3) {
            listaCircular->mostrar();
        } else if (op == 4) {
            int v;
            cout << "  Numero de vueltas: ";
            cin >> v;
            listaCircular->recorrerVueltas(v);
        } else if (op == 5) {
            string c = pedirCedula();
            if (!listaCircular->buscar(c))
                cout << "  [!] No encontrado." << endl;
        }
    } while (op != 0);
}

// ---- Menu principal ----
void Menu::ejecutar() {
    int op = 0;
    do {
        cout << "\n  ==========================================" << endl;
        cout << "   LISTAS ENLAZADAS - C++ POO + TEMPLATE    " << endl;
        cout << "         Memoria dinamica con malloc         " << endl;
        cout << "  ==========================================" << endl;
        cout << "  1. Lista Simple" << endl;
        cout << "  2. Lista Doble" << endl;
        cout << "  3. Lista Circular" << endl;
        cout << "  4. Mostrar TODAS" << endl;
        cout << "  0. Salir" << endl;
        cout << "  Opcion: ";
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
        case 0:
            cout << "\n  Saliendo... Memoria liberada con free()." << endl;
            break;
        default:
            cout << "  [!] Opcion no valida." << endl;
        }
    } while (op != 0);
}
