#include "../headers/Menu.h"
#include "../headers/PersonaConcreta.h"
#include <iostream>
#include <limits>
using namespace std;

// ============================================================
//  IMPLEMENTACION - Menu
// ============================================================

Menu::Menu() {
    listaSimple   = new ListaSimple();
    listaDoble    = new ListaDoble();
    listaCircular = new ListaCircular();
}

Menu::~Menu() {
    delete listaSimple;
    delete listaDoble;
    delete listaCircular;
}

// Pedir datos de persona al usuario — retorna puntero
Persona* Menu::pedirPersona() const {
    string nombre, cedula;
    cout << "\n  Ingrese nombre : ";
    cin.ignore();
    getline(cin, nombre);
    cout << "  Ingrese cedula : ";
    getline(cin, cedula);
    // Retorna puntero a clase concreta (polimorfismo)
    return new PersonaConcreta(nombre, cedula);
}

string Menu::pedirCedula() const {
    string cedula;
    cout << "\n  Ingrese cedula a buscar/eliminar: ";
    cin.ignore();
    getline(cin, cedula);
    return cedula;
}

// Sub-menu generico — recibe referencia a puntero de ListaBase
void Menu::submenuLista(ListaBase* lista, const string& nombre) const {
    int op = 0;
    do {
        cout << "\n  ======================================" << endl;
        cout << "        " << nombre << endl;
        cout << "  ======================================" << endl;
        cout << "  1. Insertar persona" << endl;
        cout << "  2. Eliminar persona (por cedula)" << endl;
        cout << "  3. Mostrar lista" << endl;
        cout << "  4. Buscar persona (por cedula)" << endl;
        cout << "  5. Opciones especiales" << endl;
        cout << "  0. Volver al menu principal" << endl;
        cout << "  Opcion: ";
        cin  >> op;

        switch (op) {
            case 1: {
                Persona* p = pedirPersona();   // Puntero polimorfico
                lista->insertar(p);
                break;
            }
            case 2: {
                string c = pedirCedula();
                lista->eliminar(c);
                break;
            }
            case 3:
                lista->mostrar();
                break;
            case 4: {
                string c = pedirCedula();
                if (!lista->buscar(c)) {
                    cout << "\n  [!] Persona con cedula " << c << " no encontrada." << endl;
                }
                break;
            }
            case 5:
                opcionesExtras(
                    (nombre == "LISTA SIMPLE")   ? 1 :
                    (nombre == "LISTA DOBLE")    ? 2 : 3
                );
                break;
            case 0:
                cout << "\n  Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "\n  [!] Opcion no valida." << endl;
        }
    } while (op != 0);
}

// Opciones extras segun tipo de lista
void Menu::opcionesExtras(int tipoLista) const {
    if (tipoLista == 1) {
        cout << "\n  [Lista Simple] No tiene opciones extras." << endl;

    } else if (tipoLista == 2) {
        cout << "\n  --- Opciones Lista Doble ---" << endl;
        cout << "  1. Mostrar en orden inverso (COLA -> CABEZA)" << endl;
        cout << "  Opcion: ";
        int op; cin >> op;
        if (op == 1) listaDoble->mostrarInverso();

    } else if (tipoLista == 3) {
        cout << "\n  --- Opciones Lista Circular ---" << endl;
        cout << "  1. Recorrer N vueltas" << endl;
        cout << "  Opcion: ";
        int op; cin >> op;
        if (op == 1) {
            int v;
            cout << "  Numero de vueltas: ";
            cin >> v;
            listaCircular->recorrerVueltas(v);
        }
    }
}

// Menu principal
void Menu::ejecutar() {
    int op = 0;
    do {
        cout << "\n  =========================================" << endl;
        cout << "    SISTEMA DE LISTAS ENLAZADAS - C++ POO  " << endl;
        cout << "  =========================================" << endl;
        cout << "  1. Lista Simple" << endl;
        cout << "  2. Lista Doble" << endl;
        cout << "  3. Lista Circular" << endl;
        cout << "  4. Mostrar TODAS las listas" << endl;
        cout << "  0. Salir" << endl;
        cout << "  Opcion: ";
        cin  >> op;

        switch (op) {
            case 1:
                submenuLista(listaSimple, "LISTA SIMPLE");
                break;
            case 2:
                submenuLista(listaDoble, "LISTA DOBLE");
                break;
            case 3:
                submenuLista(listaCircular, "LISTA CIRCULAR");
                break;
            case 4:
                listaSimple->mostrar();
                listaDoble->mostrar();
                listaCircular->mostrar();
                break;
            case 0:
                cout << "\n  Saliendo del programa. Hasta luego!" << endl;
                break;
            default:
                cout << "\n  [!] Opcion no valida." << endl;
        }
    } while (op != 0);
}
