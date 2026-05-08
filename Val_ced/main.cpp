#include <iostream>
#include <stdlib.h>
#include "GestorArchivos.h"
#include "Operaciones.h"

using namespace std;

void menuCRUD(NodoPersona*& listaC, NodoProvincia* listaP);

int main() {
    GestorArchivos arch; Operaciones op;
    NodoProvincia* lP = nullptr; NodoPersona* lC = nullptr;
    
    arch.cargarProvincias(lP); arch.cargarPersonas(lC);

    int opt;
    do {
        system("cls");
        cout << "1. Ingresar Cedula\n2. Ver Lista y CRUD\n3. Salir\nOpcion: "; cin >> opt;

        if (opt == 1) {
            char* c = new char[15]; char* n = new char[50];
            cout << "Nombre: "; cin.ignore(); cin.getline(n, 50);
            cout << "Cedula: "; cin >> c;

            if (op.existePersona(lC, c)) { cout << "ERROR: Ya registrada.\n"; delete[] c; delete[] n; }
            else if (!op.validarCedulaEcuatoriana(c, lP)) { cout << "ERROR: Invalida.\n"; delete[] c; delete[] n; }
            else {
                NodoPersona* nuevo = new NodoPersona();
                nuevo->cedula = c; nuevo->nombre = n; nuevo->siguiente = lC; lC = nuevo;
                arch.guardarPersonas(lC); cout << "Guardado!\n";
            }
            system("pause");
        } 
        else if (opt == 2) menuCRUD(lC, lP);
    } while (opt != 3);

    return 0;
}

void menuCRUD(NodoPersona*& lC, NodoProvincia* lP) {
    GestorArchivos arch; Validaciones val; Operaciones op; int opt;
    do {
        system("cls"); cout << "--- REGISTROS ---" << endl;
        NodoProvincia* p = lP;
        while (p) {
            bool flag = false; NodoPersona* c = lC;
            while (c) {
                char* pref = new char[3]; *(pref+0) = *(c->cedula+0); *(pref+1) = *(c->cedula+1); *(pref+2) = '\0';
                if (val.comparar(pref, p->codigo)) {
                    if (!flag) { cout << "\n[" << p->nombre << "]\n"; flag = true; }
                    cout << " - " << c->nombre << " [" << c->cedula << "]\n";
                }
                delete[] pref; c = c->siguiente;
            }
            p = p->siguiente;
        }

        cout << "\n1. Volver | 2. Eliminar | 3. Modificar\nOpcion: "; cin >> opt;

        if (opt == 2 || opt == 3) {
            char* target = new char[15];
            cout << "Ingrese cedula a " << (opt == 2 ? "eliminar: " : "modificar: "); cin >> target;
            
            NodoPersona *curr = lC, *prev = nullptr; bool found = false;
            while (curr) {
                if (val.comparar(curr->cedula, target)) {
                    found = true;
                    if (opt == 2) { // ELIMINAR
                        if (prev) prev->siguiente = curr->siguiente; else lC = curr->siguiente;
                        delete[] curr->nombre; delete[] curr->cedula; delete curr;
                        cout << "Eliminado.\n";
                    } else { // MODIFICAR
                        char* nN = new char[50]; char* nC = new char[15];
                        cout << "Nuevo nombre: "; cin.ignore(); cin.getline(nN, 50);
                        cout << "Nueva cedula: "; cin >> nC;
                        
                        if (!val.comparar(curr->cedula, nC) && op.existePersona(lC, nC)) { cout << "Error: Ya existe.\n"; }
                        else if (!op.validarCedulaEcuatoriana(nC, lP)) { cout << "Error: Invalida.\n"; }
                        else {
                            delete[] curr->nombre; delete[] curr->cedula;
                            curr->nombre = nN; curr->cedula = nC; cout << "Modificado.\n";
                        }
                    }
                    arch.guardarPersonas(lC); break;
                }
                prev = curr; curr = curr->siguiente;
            }
            if (!found) cout << "No encontrada.\n";
            delete[] target; system("pause");
        }
    } while (opt != 1);
}