#include "Listas.h"
#include "Operaciones.h"
#include <iostream>

using namespace std;

void menuOperaciones(ListaBase* lista, string tipo) {
    int op;
    do {
        cout << "\n--- MODO: " << tipo << " ---" << endl;
        cout << "1. Insertar\n2. Modificar\n3. Eliminar\n4. Buscar\n5. Mostrar\n6. Volver\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: registrarPersona(lista); break;
            case 2: modificarPersona(lista); break;
            case 3: eliminarPersona(lista); break;
            case 4: {
                string c; cout << "Cedula: "; cin >> c;
                cout << (lista->buscar(c) ? "Encontrado." : "No existe.") << endl;
                break;
            }
            case 5: lista->mostrar(); break;
        }
    } while (op != 6);
}

int main() {
    ListaSimple ls; ListaDoble ld; ListaCircular lc;
    int op;
    do {
        cout << "\n=== MENU PRINCIPAL ===\n1. Lista Simple\n2. Lista Doble\n3. Lista Circular\n4. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) menuOperaciones(&ls, "SIMPLE");
        else if (op == 2) menuOperaciones(&ld, "DOBLE");
        else if (op == 3) menuOperaciones(&lc, "CIRCULAR");
    } while (op != 4);
    return 0;
}