#include "Listas.h"
#include "Operaciones.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ListaSimple listS;
    ListaDoble listD;
    ListaCircular listC;

    ListaBase* tda = nullptr;
    int opcion = 0;
    int tipoLista = 1; 

    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "Estructura Actual: ";
        
        if (tipoLista == 1) { cout << "Lista Simple\n"; tda = &listS; }
        else if (tipoLista == 2) { cout << "Lista Doble\n"; tda = &listD; }
        else { cout << "Lista Circular\n"; tda = &listC; }

        cout << "1. Cambiar Estructura" << endl;
        cout << "2. Insertar Persona" << endl;
        cout << "3. Eliminar Persona" << endl;
        cout << "4. Buscar Persona" << endl;
        cout << "5. Mostrar Lista Actual" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Elija: 1(Simple), 2(Doble), 3(Circular): ";
                cin >> tipoLista;
                break;
            case 2:
                registrarDatoTDA(tda);
                break;
            case 3:
                eliminarDatoTDA(tda);
                break;
            case 4: {
                string bCed;
                cout << "Ingrese cedula a buscar: ";
                cin >> bCed;
                if (tda->buscar(bCed)) cout << ">> ESTA REGISTRADA <<" << endl;
                else cout << ">> NO EXISTE <<" << endl;
                break;
            } 
            case 5:
                tda->mostrar();
                break;
            case 6:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);

    return 0;
}